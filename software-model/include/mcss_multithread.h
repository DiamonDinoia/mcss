#ifndef MultithreadedMCSS_H
#define MultithreadedMCSS_H

#include <thread>
#include "common.h"

namespace Multithread {

Histograms Simulate(
    Material material, int numHists,
    unsigned int numThreads = std::thread::hardware_concurrency());
}  // namespace Multithread

#endif