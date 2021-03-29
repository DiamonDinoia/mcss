#ifndef MCSS_ORIGINAL_H
#define MCSS_ORIGINAL_H

#include "common.h"

namespace Reference {
struct Histograms {
    double longiHist[longiDistNumBin]{};
    double transHist[transDistNumBin]{};
};

Histograms Simulate();
}  // namespace Reference

#endif