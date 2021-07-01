#ifndef MCSS_ORIGINAL_H
#define MCSS_ORIGINAL_H

#include "../../include/common.h"

namespace Reference {
struct Histograms {
    double longiHist[longiDistNumBin]{};
    double transHist[transDistNumBin]{};
};

Histograms Simulate(Material material = GOLD, int numHists = 1000000);
}  // namespace Reference

#endif