#include "../include/common.h"

namespace Original {
struct Histograms {
    double longiHist[longiDistNumBin]{};
    double transHist[transDistNumBin]{};
};

Histograms Simulate();
}