// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by R. Brandt 2022
// Modified by M. Barbone 2022
#ifndef MCSS_GPU_H
#define MCSS_GPU_H

#include <cuda.h>
#include <curand.h>
#include <curand_kernel.h>

#include "common.h"

#define NUM_THREADS 256
#define GRID_SIZE   256

namespace Gpu {
template <typename T>
Histograms Simulate(Material material, int numHists);

}  // namespace Gpu

#endif
