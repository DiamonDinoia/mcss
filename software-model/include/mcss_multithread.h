// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by D. Chen 2020
// Modified by M. Barbone 2020
#ifndef MultithreadedMCSS_H
#define MultithreadedMCSS_H

#include <thread>

#include "common.h"

namespace Multithread {
template<typename T>
Histograms Simulate(
    Material material, int numHists,
    unsigned int numThreads = std::thread::hardware_concurrency());

}  // namespace Multithread

#endif