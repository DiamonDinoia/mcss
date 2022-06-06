#ifndef MCSS_GPU_H
#define MCSS_GPU_H

#include <cuda.h>
#include <curand.h>
#include <curand_kernel.h>

#include "common.h"

#define NUM_THREADS 512

namespace Gpu {
Histograms Simulate(Material material, int numHists);

}  // namespace Gpu

#endif
