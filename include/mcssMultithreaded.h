#ifndef MultithreadedMCSS_H
#define MultithreadedMCSS_H

#include <vector>

#include "common.h"

struct Histograms {
    std::vector<real_type> longiHist;
    std::vector<real_type> transHist;
};

Histograms Simulate();

#endif