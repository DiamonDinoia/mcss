#ifndef MultithreadedMCSS_H
#define MultithreadedMCSS_H

#include <vector>

#include "common.h"

namespace Multithread {

Histograms Simulate(
    Material material = GOLD, int numHists = 1000000,
    unsigned int numThreads = std::thread::hardware_concurrency());
}  // namespace Multithread

#endif