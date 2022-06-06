#include <cmath>

#include "common.h"
#include "mcss_gpu.cuh"

namespace Gpu {

/*
 * Device code
 */

__device__ real_type sampleCosTheta(real_type scrpar, real_type rn) {
    real_type cost = 1.0 - 2 * scrpar * rn / (1.0 - rn + scrpar);
    return max((real_type)-1.0, min((real_type)1.0, cost));
}

__device__ void rotateToLabFrame(real_type &u, real_type &v, real_type &w,
                                 real_type &u1, real_type &u2, real_type &u3) {
    real_type up = u1 * u1 + u2 * u2;
    if (up > 0.0) {
        up = sqrt(up);
        real_type px = u;
        real_type py = v;
        real_type pz = w;
        u = (u1 * u3 * px - u2 * py) / up + u1 * pz;
        v = (u2 * u3 * px + u1 * py) / up + u2 * pz;
        w = -up * px + u3 * pz;
    } else if (u3 < 0.0) {
        u = -u;
        w = -w;
    }
}

__global__ void compute_terminal_positions(
    curandState *states, real_type *longHist, real_type *transHist,
    real_type screening_param, real_type mean_free_path, real_type track_limit,
    const unsigned int longHistNumBins, const unsigned int transHistNumBins,
    real_type longDistInvD, real_type transDistInvD, int numSims) {
    int threadX = threadIdx.x;
    int i = blockIdx.x * blockDim.x + threadX;

    // Initialise local histograms
    __shared__ real_type shared_longHist[longiDistNumBin];
    __shared__ real_type shared_transHist[transDistNumBin];

    if (threadX < longHistNumBins) {
        shared_longHist[threadX] = 0.0;
    }
    if (threadX < transHistNumBins) {
        shared_transHist[threadX] = 0.0;
    }

    // Ensure that every thread has initialised the histograms
    __syncthreads();

    // Load cuda random state into local register memory
    curandState local_state = states[i];

    // Compute how many simulations each thread will perform
    unsigned int num_sims_per_thread =
        (unsigned int)ceil(float(numSims) / (blockDim.x * gridDim.x));

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
    for (int j = 0; j < num_sims_per_thread; j++) {
        // Use strides of size blockDim.x*gridDim.x to divide work as
        // equally as possible
        local_idx =
            j * blockDim.x * gridDim.x + blockDim.x * blockIdx.x + threadX;

        if (local_idx < numSims) {
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
                    rotateToLabFrame(u1, u2, u3, trackDirection_x,
                                     trackDirection_y, trackDirection_z);

                    trackDirection_x = u1;
                    trackDirection_y = u2;
                    trackDirection_z = u3;
                }
            }

            // Compute longitudinal deviation and its bin index
            real_type longitudinal_deviation = trackPosition_z / trackLength;
            unsigned int longIdx =
                (unsigned int)((longitudinal_deviation + 1.0) * longDistInvD);

            // Compute transversal deviation and its bin index
            real_type transversal_deviation =
                sqrt(trackPosition_x * trackPosition_x +
                     trackPosition_y * trackPosition_y) /
                trackLength;
            unsigned int transIdx =
                (unsigned int)(transversal_deviation * transDistInvD);

            // Write simulation result to histograms
            atomicAdd(&(shared_longHist[longIdx]), longDistInvD / numSims);
            atomicAdd(&(shared_transHist[transIdx]), transDistInvD / numSims);
        }
    }

    // Sync up threads after simulations
    __syncthreads();

    // Add shared histogram to global histogram
    if (threadX < longHistNumBins) {
        atomicAdd(&(longHist[threadX]), shared_longHist[threadX]);
    }
    if (threadX < transHistNumBins) {
        atomicAdd(&(transHist[threadX]), shared_transHist[threadX]);
    }
}

__global__ void initialise_RNG(curandState *states, int numStates) {
    unsigned long i = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned long seed = 0;

    // Use the same seed but different sequence number
    if (i < numStates) {
        curand_init(i, seed, 0, &states[i]);
    }
}

/*
 * Host code
 */

Histograms Simulate(Material material, int numHists) {
    real_type *longHist_h, *transHist_h;
    cudaError_t cuda_ret;

    // Wake up GPU (seems to be a problem with Peregrine GPUs being in
    // sleep mode, so I wake them up before timing the application)
    // cudaFree(0);
    // cudaDeviceSynchronize();

    // Initialise space on host for histograms
    longHist_h = (real_type *)malloc(longiDistNumBin * sizeof(real_type));
    transHist_h = (real_type *)malloc(transDistNumBin * sizeof(real_type));

    // Initialise constants
    const real_type theScrPar = computeScrParam(material, thePC2);
    const real_type theMFP = computeMFP(material, theBeta2, theScrPar);
    const real_type theLimit = theMFP * 33.5;

    // Define block and grid dimensions
    int num_blocks = 80;
    dim3 grid_dim, block_dim;
    grid_dim.x = num_blocks;
    block_dim.x = NUM_THREADS;

    // Initialise the RNG state for use in the simulations
    curandState *states_d;

    cuda_ret = cudaMalloc((void **)&states_d,
                          (num_blocks * NUM_THREADS) * sizeof(curandState));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise states on the GPU.\n");
        exit(-1);
    }

    cudaDeviceSynchronize();

    initialise_RNG<<<grid_dim, block_dim>>>(states_d, numHists);
    cudaDeviceSynchronize();

    // Initialise histograms on GPU
    real_type *longHist_d;
    real_type *transHist_d;
    cuda_ret =
        cudaMalloc((void **)&longHist_d, longiDistNumBin * sizeof(real_type));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise longHist on the GPU.\n");
        exit(-1);
    }

    cuda_ret =
        cudaMalloc((void **)&transHist_d, transDistNumBin * sizeof(real_type));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to initialise transHist on the GPU.\n");
        exit(-1);
    }

    // Set histogram values to 0
    cuda_ret = cudaMemset(longHist_d, 0, longiDistNumBin * sizeof(real_type));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to set longHist to zero on the GPU.\n");
        exit(-1);
    }

    cuda_ret = cudaMemset(transHist_d, 0, transDistNumBin * sizeof(real_type));
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to set transHist to zero on the GPU.\n");
        exit(-1);
    }

    cudaDeviceSynchronize();

    // Run simulation on GPU
    compute_terminal_positions<<<grid_dim, block_dim>>>(
        states_d, longHist_d, transHist_d, theScrPar, theMFP, theLimit,
        longiDistNumBin, transDistNumBin, longiDistInvD, transDistInvD,
        numHists);

    cuda_ret = cudaDeviceSynchronize();
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to complete simulation kernel.\n");
        exit(-1);
    }

    // Retrieve histograms from GPU
    cuda_ret =
        cudaMemcpy(longHist_h, longHist_d, longiDistNumBin * sizeof(real_type),
                   cudaMemcpyDeviceToHost);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve longitudinal histogram from GPU.\n");
        exit(-1);
    }
    cuda_ret =
        cudaMemcpy(transHist_h, transHist_d,
                   transDistNumBin * sizeof(real_type), cudaMemcpyDeviceToHost);
    if (cuda_ret != cudaSuccess) {
        printf("ERROR: Failed to retrieve transversal histogram from GPU.\n");
        exit(-1);
    }

    cudaDeviceSynchronize();

    // Copy array pointers into histogram variable
    Histograms histograms{longiDistNumBin, transDistNumBin};
    memcpy(&(histograms.longiHist[0]), &(longHist_h[0]),
           longiDistNumBin * sizeof(real_type));
    memcpy(&(histograms.transHist[0]), &(transHist_h[0]),
           transDistNumBin * sizeof(real_type));

    // Free buffers
    cudaFree(longHist_d);
    cudaFree(transHist_d);
    cudaFree(states_d);

    free(longHist_h);
    free(transHist_h);

    return histograms;
}

Histograms Simulate() { return Simulate(GOLD, 1000000); }

}  // namespace Gpu
