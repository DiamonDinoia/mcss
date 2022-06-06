#ifndef MultithreadedMCSS_H
#define MultithreadedMCSS_H


#include "common.h"
#include <thread>

namespace Multithread {

Histograms Simulate(
    Material material, int numHists,
    unsigned int numThreads = std::thread::hardware_concurrency());
}  // namespace Multithread

#endif