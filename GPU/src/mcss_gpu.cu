// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by R. Brandt 2022
// Modified by M. Barbone 2022#include <cmath>
#include <iostream>
#include <memory>
#include <random>

#include "common.h"
#include "mcss_gpu.h"

namespace Gpu {

static constexpr size_t div_rounding_up(size_t dividend, size_t divisor) {
    return (dividend + divisor - 1) / divisor;
}

__global__ static void compute_terminal_positions(
    unsigned int seed, unsigned int* longHist, unsigned int* transHist,
    const real_type theScrPar, const real_type theMFP, const real_type theLimit,
    const int numSims, const int thread_histories) {
    const int threadX = threadIdx.x;
    const int i       = blockIdx.x * blockDim.x + threadX;

    // Load cuda random state into local register memory
    curandStatePhilox4_32_10 local_state{};
    curand_init(i, seed, 0, &local_state);
#ifdef USE_SHARED_MEMORY
    __shared__ unsigned int shared_longHist[longiDistNumBin];
    __shared__ unsigned int shared_transHist[transDistNumBin];
    if (threadX < longiDistNumBin) { shared_longHist[threadX] = 0.0; }
    if (threadX < transDistNumBin) { shared_transHist[threadX] = 0.0; }

    // Ensure that every thread has initialised the histograms
    __syncthreads();
#endif
    // Perform multiple simulations per thread
    for (int j = 0; j < thread_histories; j++) {
        // Use strides of size blockDim.x*gridDim.x to divide work as
        // equally as possible

        const auto local_idx =
            j * blockDim.x * gridDim.x + blockDim.x * blockIdx.x + threadX;

        if (local_idx >= numSims) { break; }

        Track     aTrack{};
        real_type trackLength = 0.0;
        bool      stop        = false;
        do {
            real_type stepLength =
                -theMFP * std::log(curand_uniform(&local_state));
            trackLength += stepLength;
            if (trackLength > theLimit) {
                stepLength = theLimit - aTrack.fTrackLength;
                stop       = true;
            }
            aTrack.fPosition[0] += aTrack.fDirection[0] * stepLength;
            aTrack.fPosition[1] += aTrack.fDirection[1] * stepLength;
            aTrack.fPosition[2] += aTrack.fDirection[2] * stepLength;
            aTrack.fTrackLength += stepLength;
            if (!stop) {
                const real_type cost =
                    sampleCosTheta(theScrPar, curand_uniform(&local_state));
                const real_type dum0 = 1.0 - cost;
                const real_type sint = std::sqrt(dum0 * (2.0 - dum0));
                const real_type phi  = 2.0 * kPI * curand_uniform(&local_state);
                real_type       u1   = sint * std::cos(phi);
                real_type       u2   = sint * std::sin(phi);
                real_type       u3   = cost;
                rotateToLabFrame(u1, u2, u3, aTrack.fDirection[0],
                                 aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while (!stop);

        // Calculate final longitudinal location.
        const real_type longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        const unsigned  lIndx = (longi + 1.0) * longiDistInvD;
        // Increment the relevant element of the thread-specific
        // longitudinal histogram.
        const real_type trans =
            std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                      aTrack.fPosition[1] * aTrack.fPosition[1]) /
            aTrack.fTrackLength;
        const unsigned tIndx = trans * transDistInvD;
        // Increment the relevent element of the thread-specific
        // trans histogram.
#ifndef USE_SHARED_MEMORY
        atomicAdd(&(longHist[lIndx]), 1);
        atomicAdd(&(transHist[tIndx]), 1);
#endif
#ifdef USE_SHARED_MEMORY

        atomicAdd(&(shared_longHist[lIndx]), 1);
        atomicAdd(&(shared_transHist[tIndx]), 1);
#endif
    }
#ifdef USE_SHARED_MEMORY
    // Add shared histogram to global histogram
    if (threadX < longiDistNumBin) {
        atomicAdd(&(longHist[threadX]), shared_longHist[threadX]);
    }
    if (threadX < transDistNumBin) {
        atomicAdd(&(longHist[threadX]), shared_transHist[threadX]);
    }
#endif
}

/*
 * Host code
 */

Histograms Simulate(Material material, int numHists) {
    cudaError_t cuda_ret;
    const auto  seed = std::random_device()();
    // Wake up GPU (seems to be a problem with Peregrine GPUs being in
    // sleep mode, so I wake them up before timing the application)
    // cudaFree(0);
    // cudaDeviceSynchronize();
#ifndef USE_SHARED_MEMORY
    cuda_ret = cudaFuncSetCacheConfig(compute_terminal_positions,
                                      cudaFuncCachePreferL1);
#else
    cuda_ret = cudaFuncSetCacheConfig(compute_terminal_positions,
                                      cudaFuncCachePreferShared);
#endif
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise longHist on the GPU.\n");
        exit(-1);
    }

    // Initialise space on host for histograms
    auto longHist_h  = std::make_unique<unsigned int[]>(longiDistNumBin);
    auto transHist_h = std::make_unique<unsigned int[]>(transDistNumBin);

    // Initialise constants
    const real_type theScrPar = computeScrParam(material, thePC2);
    const real_type theMFP    = computeMFP(material, theBeta2, theScrPar);
    const real_type theLimit  = theMFP * 33.5;

    // Define block and grid dimensions
    constexpr auto num_threads = NUM_THREADS;
    auto           num_blocks  = div_rounding_up(numHists, num_threads);
    // CUDA has a limit on the grid size
    num_blocks            = math::min(num_blocks, GRID_SIZE);

    auto thread_histories = div_rounding_up(numHists, num_blocks * num_threads);
    thread_histories      = math::max(thread_histories, 1);

    // Initialise histograms on GPU
    unsigned int* longHist_d;
    unsigned int* transHist_d;
    cuda_ret = cudaMalloc(&longHist_d, longiDistNumBin * sizeof(unsigned int));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise longHist on the GPU.\n");
        exit(-1);
    }

    cuda_ret = cudaMalloc(&transHist_d, transDistNumBin * sizeof(unsigned int));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise transHist on the GPU.\n");
        exit(-1);
    }

    // Set histogram values to 0
    cuda_ret =
        cudaMemset(longHist_d, 0, longiDistNumBin * sizeof(unsigned int));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to set longHist to zero on the GPU.\n");
        exit(-1);
    }

    cuda_ret =
        cudaMemset(transHist_d, 0, transDistNumBin * sizeof(unsigned int));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to set transHist to zero on the GPU.\n");
        exit(-1);
    }

    cuda_ret = cudaDeviceSynchronize();
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve transversal histogram from GPU.\n");
        exit(-1);
    }

    // Run simulation on GPU
    compute_terminal_positions<<<num_blocks, num_threads>>>(
        seed, longHist_d, transHist_d, theScrPar, theMFP, theLimit, numHists,
        thread_histories);

    cuda_ret = cudaDeviceSynchronize();
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to complete simulation kernel.\n");
        exit(-1);
    }
    // Retrieve histograms from GPU
    cuda_ret = cudaMemcpy(longHist_h.get(), longHist_d,
                          longiDistNumBin * sizeof(unsigned int),
                          cudaMemcpyDeviceToHost);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve longitudinal histogram from GPU.\n");
        exit(-1);
    }
    cuda_ret = cudaMemcpy(transHist_h.get(), transHist_d,
                          transDistNumBin * sizeof(unsigned int),
                          cudaMemcpyDeviceToHost);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve transversal histogram from GPU.\n");
        exit(-1);
    }

    cuda_ret = cudaDeviceSynchronize();
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve transversal histogram from GPU.\n");
        exit(-1);
    }

    // Copy array pointers into histogram variable
    Histograms histograms{longiDistNumBin, transDistNumBin};
    for (int i = 0; i < longiDistNumBin; ++i) {
        histograms.longiHist[i] = longHist_h[i] * (longiDistInvD / numHists);
    }
    for (int i = 0; i < transDistNumBin; ++i) {
        histograms.transHist[i] = transHist_h[i] * (transDistInvD / numHists);
    }

    // Free buffers
    cudaFree(longHist_d);
    cudaFree(transHist_d);

    return histograms;
}

Histograms Simulate() { return Simulate(GOLD, 1000000); }

}  // namespace Gpu
