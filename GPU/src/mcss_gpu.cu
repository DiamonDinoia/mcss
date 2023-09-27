// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by R. Brandt 2022
// Modified by M. Barbone 2022
#include <VectorXoshiro/xoshiroPlusPlus.h>

#include <cmath>
#include <iostream>
#include <memory>
#include <random>

#include "common.h"
#include "mcss_gpu.h"
#include "mixmax/mixmax.h"

namespace Gpu {

static constexpr size_t div_rounding_up(size_t dividend, size_t divisor) {
    return (dividend + divisor - 1) / divisor;
}

template <typename T>
__device__ __attribute__((noinline)) static constexpr auto getGenerator(
    std::uint64_t i, std::uint64_t seed) {
    if constexpr (std::is_same_v<T, curandStatePhilox4_32_10_t> ||
                  std::is_same_v<T, curandStateMRG32k3a_t>) {
        T local_state{};
        curand_init(i, seed, 0, &local_state);
        return local_state;
    } else
        return T(seed, i);
}

template <typename T>
__device__ inline auto getUniform(T& rng
#ifdef COUNT_NUMBERS
                                  ,
                                  std::uint64_t* counter
#endif
) {
#ifdef COUNT_NUMBERS
    counter[blockIdx.x * blockDim.x + threadIdx.x]++;
#endif
    if constexpr (std::is_same_v<T, curandStatePhilox4_32_10_t> ||
                  std::is_same_v<T, curandStateMRG32k3a_t>) {
        return curand_uniform(&rng);
    }
    if constexpr (std::is_same_v<T, XoshiroPlusPlus>) { return rng.uniform(); }
    if constexpr (std::is_same_v<T, MIXMAX::MixMaxRng8> ||
                  std::is_same_v<T, CounterRNG> || std::is_same_v<T, ChaCha8>) {
        return rng.Uniform();
    }
}

template <typename T>
__global__ static void compute_terminal_positions(
    unsigned int seed, unsigned int* longHist, unsigned int* transHist,
    const real_type theScrPar, const real_type theMFP, const real_type theLimit,
    const int numSims, const int thread_histories
#ifdef COUNT_NUMBERS
    ,
    std::uint64_t* counter
#endif
) {
    const auto threadX = threadIdx.x;
    const auto i       = blockIdx.x * blockDim.x + threadX;

    // Load cuda random state into local register memory
    auto local_state = getGenerator<T>(i, seed);
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
            real_type stepLength = -theMFP * std::log(getUniform(local_state
#ifdef COUNT_NUMBERS
                                                                 ,
                                                                 counter
#endif
                                                                 ));
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
                    sampleCosTheta(theScrPar, getUniform(local_state
#ifdef COUNT_NUMBERS
                                                         ,
                                                         counter
#endif
                                                         ));
                const real_type dum0 = 1.0 - cost;
                const real_type sint = std::sqrt(dum0 * (2.0 - dum0));
                const real_type phi  = 2.0 * kPI *
                                      getUniform(local_state
#ifdef COUNT_NUMBERS
                                                 ,
                                                 counter
#endif
                                      );
                real_type u1 = sint * std::cos(phi);
                real_type u2 = sint * std::sin(phi);
                real_type u3 = cost;
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
template <typename T>
Histograms Simulate(Material material, int numHists) {
    cudaError_t cuda_ret;
    const auto  seed = 42;

#ifndef USE_SHARED_MEMORY
    cuda_ret = cudaFuncSetCacheConfig(compute_terminal_positions<T>,
                                      cudaFuncCachePreferL1);
#else
    cuda_ret = cudaFuncSetCacheConfig(compute_terminal_positions<T>,
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

#ifdef COUNT_NUMBERS
    // count the random numbers generated
    const auto numRands       = num_threads * num_blocks;
    auto       random_numbers = std::make_unique<std::uint64_t[]>(numRands);
    decltype(random_numbers.get()) random_numbers_d;

    cuda_ret = cudaMalloc(&random_numbers_d, numRands * sizeof(std::uint64_t));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise rng counter on the GPU.\n");
        exit(-1);
    }

    cuda_ret =
        cudaMemset(random_numbers_d, 0, numRands * sizeof(std::uint64_t));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to set rng counter to zero on the GPU.\n");
        exit(-1);
    }
#endif
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
    compute_terminal_positions<T><<<num_blocks, num_threads>>>(
        seed, longHist_d, transHist_d, theScrPar, theMFP, theLimit, numHists,
        thread_histories
#ifdef COUNT_NUMBERS
        ,
        random_numbers_d
#endif
    );

    cuda_ret = cudaDeviceSynchronize();
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to complete simulation kernel.\n");
        exit(-1);
    }

#ifdef COUNT_NUMBERS
    // Retrieve random numbers from GPU
    cuda_ret =
        cudaMemcpy(random_numbers.get(), random_numbers_d,
                   numRands * sizeof(std::uint64_t), cudaMemcpyDeviceToHost);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve random numbers from GPU.\n");
        exit(-1);
    }
#endif

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
#ifdef COUNT_NUMBERS
    // sum the random numbers
    const std::uint64_t sum = std::accumulate(
        random_numbers.get(), random_numbers.get() + numRands, 0UL);
    std::cout << "Random numbers generated: " << sum << std::endl;
#endif
    // Copy array pointers into histogram variable
    Histograms histograms{longiDistNumBin, transDistNumBin};
    for (int i = 0; i < longiDistNumBin; ++i) {
        histograms.longiHist[i] = longHist_h[i] * (longiDistInvD / numHists);
    }
    for (int i = 0; i < transDistNumBin; ++i) {
        histograms.transHist[i] = transHist_h[i] * (transDistInvD / numHists);
    }

    // Free buffers
#ifdef COUNT_NUMBERS
    cudaFree(random_numbers_d);
#endif
    cudaFree(longHist_d);
    cudaFree(transHist_d);
    return histograms;
}

template Histograms Simulate<XoshiroPlusPlus>(Material, int);
template Histograms Simulate<MIXMAX::MixMaxRng8>(Material, int);
template Histograms Simulate<curandStatePhilox4_32_10>(Material, int);
template Histograms Simulate<curandStateMRG32k3a>(Material, int);
template Histograms Simulate<CounterRNG>(Material, int);
template Histograms Simulate<ChaCha8>(Material, int);

}  // namespace Gpu
