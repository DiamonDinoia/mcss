#ifndef MCSS_ORIGINAL_H
#define MCSS_ORIGINAL_H

#include "../include/common.h"

namespace Original {
struct Histograms {
    double longiHist[longiDistNumBin]{};
    double transHist[transDistNumBin]{};
};

Histograms Simulate();
}

#endif