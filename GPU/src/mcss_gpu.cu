#include <cmath>
#include <iostream>
#include <random>

#include "common.h"
#include "mcss_gpu.h"

namespace Gpu {

static constexpr size_t div_rounding_up(size_t dividend, size_t divisor) {
    return (dividend + divisor - 1) / divisor;
}

__global__ static void compute_terminal_positions(
    const unsigned seed, unsigned int* longHist, unsigned int* transHist,
    real_type screening_param, real_type mean_free_path, real_type track_limit,
    const unsigned int longHistNumBins, const unsigned int transHistNumBins,
    real_type longDistInvD, real_type transDistInvD, int numSims,
    int thread_histories) {
    int threadX = threadIdx.x;
    int i = blockIdx.x * blockDim.x + threadX;

    curandStatePhilox4_32_10 local_state{};
    curand_init(i, seed, 0, &local_state);

    // Initialise local variables
    real_type trackPosition_x;
    real_type trackPosition_y;
    real_type trackPosition_z;
    real_type trackDirection_x;
    real_type trackDirection_y;
    real_type trackDirection_z;
    real_type stepLength;
    real_type trackLength;
    bool stop;
    unsigned int local_idx;
    real_type rand_val;

    // Perform multiple simulations per thread
    for (int j = 0; j < thread_histories; j++) {
        // Use strides of size blockDim.x*gridDim.x to divide work as
        // equally as possible
        local_idx =
            j * blockDim.x * gridDim.x + blockDim.x * blockIdx.x + threadX;

        if (local_idx >= numSims) {
            break;
        }

        // Initialise local variables
        trackPosition_x = 0.0;
        trackPosition_y = 0.0;
        trackPosition_z = 0.0;
        trackDirection_x = 0.0;
        trackDirection_y = 0.0;
        trackDirection_z = 1.0;

        stepLength = 0.0;
        trackLength = 0.0;
        stop = false;

        // Start the simulation
        while (!stop) {
            // Compute step length
            rand_val = curand_uniform(&local_state);

            stepLength = -mean_free_path * log(rand_val);
            if (trackLength > track_limit) {  // Last step, so shorten it
                                              // and stop afterwards
                stepLength = track_limit - trackLength;
                stop = true;
            }

            // Update track positions
            trackPosition_x += stepLength * trackDirection_x;
            trackPosition_y += stepLength * trackDirection_y;
            trackPosition_z += stepLength * trackDirection_z;
            trackLength += stepLength;

            // Update track direction if we are not at the end already
            if (!stop) {
                // Compute new positions based on random collision direction
                rand_val = curand_uniform(&local_state);

                real_type cost = sampleCosTheta(screening_param, rand_val);
                real_type sint = sqrt((1.0 - cost) * (1.0 + cost));
                rand_val = curand_uniform(&local_state);
                real_type phi = 2.0 * kPI * rand_val;

                real_type u1 = sint * cos(phi);
                real_type u2 = sint * sin(phi);
                real_type u3 = cost;

                // Rotate back to lab frame
                rotateToLabFrame(u1, u2, u3, trackDirection_x, trackDirection_y,
                                 trackDirection_z);

                trackDirection_x = u1;
                trackDirection_y = u2;
                trackDirection_z = u3;
            }
        }

        // Compute longitudinal deviation and its bin index
        real_type longitudinal_deviation = trackPosition_z / trackLength;
        auto longIdx =
            (unsigned int)((longitudinal_deviation + 1.0) * longDistInvD);

        // Compute transversal deviation and its bin index
        real_type transversal_deviation =
            sqrt(trackPosition_x * trackPosition_x +
                 trackPosition_y * trackPosition_y) /
            trackLength;
        auto transIdx = (unsigned int)(transversal_deviation * transDistInvD);

        // Write simulation result to histograms
        atomicAdd(&(longHist[longIdx]), 1);
        atomicAdd(&(transHist[transIdx]), 1);
    }
}

/*
 * Host code
 */

Histograms Simulate(Material material, int numHists) {
    unsigned int *longHist_h, *transHist_h;
    cudaError_t cuda_ret;
    const auto seed = std::random_device()();
    // Wake up GPU (seems to be a problem with Peregrine GPUs being in
    // sleep mode, so I wake them up before timing the application)
    // cudaFree(0);
    // cudaDeviceSynchronize();
    cuda_ret = cudaFuncSetCacheConfig(compute_terminal_positions,
                                      cudaFuncCachePreferL1);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise longHist on the GPU.\n");
        exit(-1);
    }

    // Initialise space on host for histograms
    longHist_h =
        (unsigned int*)malloc(longiDistNumBin * sizeof(unsigned int));
    transHist_h =
        (unsigned int*)malloc(transDistNumBin * sizeof(unsigned int));

    // Initialise constants
    const real_type theScrPar = computeScrParam(material, thePC2);
    const real_type theMFP = computeMFP(material, theBeta2, theScrPar);
    const real_type theLimit = theMFP * 33.5;

    // Define block and grid dimensions
    constexpr auto num_threads = NUM_THREADS;
    auto num_blocks = div_rounding_up(numHists, num_threads);
    // CUDA has a limit on the grid size
    num_blocks =
        math::min(num_blocks, std::numeric_limits<unsigned int>::max());
    auto thread_histories = div_rounding_up(numHists, num_blocks * num_threads);
    thread_histories = math::max(thread_histories, 1);

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
        seed, longHist_d, transHist_d, theScrPar, theMFP, theLimit,
        longiDistNumBin, transDistNumBin, longiDistInvD, transDistInvD,
        numHists, thread_histories);

    cuda_ret = cudaDeviceSynchronize();
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to complete simulation kernel.\n");
        exit(-1);
    }
    // Retrieve histograms from GPU
    cuda_ret = cudaMemcpy(longHist_h, longHist_d,
                          longiDistNumBin * sizeof(unsigned int),
                          cudaMemcpyDeviceToHost);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve longitudinal histogram from GPU.\n");
        exit(-1);
    }
    cuda_ret = cudaMemcpy(transHist_h, transHist_d,
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

    free(longHist_h);
    free(transHist_h);

    return histograms;
}

Histograms Simulate() { return Simulate(GOLD, 1000000); }

}  // namespace Gpu
