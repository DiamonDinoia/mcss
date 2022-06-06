#ifndef MCSS_GPU_H
#define MCSS_GPU_H

#include <cuda.h>
#include <curand.h>
#include <curand_kernel.h>

#include "common.h"

#define NUM_THREADS 512

namespace Gpu {
Histograms Simulate(Material material = GOLD, int numHists = 1000000);

__device__ real_type sampleCosTheta(real_type scrpar, real_type rn);
__device__ void rotateToLabFrame(real_type &u, real_type &v, real_type &w,
                                 real_type &u1, real_type &u2, real_type &u3);

__global__ void compute_terminal_positions(
    curandState *states, real_type *longHist, real_type *transHist,
    real_type screening_param, real_type mean_free_path, real_type track_limit,
    unsigned int longHistNumBins, unsigned int transHistNumBins,
    real_type longDistInvD, real_type transDistInvD, int numSims);
__global__ void initialise_RNG(curandState *states, int numStates);
}  // namespace Gpu

#endif
