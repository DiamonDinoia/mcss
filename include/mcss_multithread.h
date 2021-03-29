#ifndef MultithreadedMCSS_H
#define MultithreadedMCSS_H

#include <vector>

#include "common.h"

namespace multithread {
struct Histograms {
    std::vector<real_type> longiHist;
    std::vector<real_type> transHist;
};

Histograms Simulate();
}  // namespace multithread

#endif