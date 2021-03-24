#include "common.h"

struct OriginalHistograms {
    double longiHist[longiDistNumBin]{};
    double transHist[transDistNumBin]{};
};

OriginalHistograms OriginalSimulate();