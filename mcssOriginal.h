
const int OriginalTransDistNumBin = 101;
const int OriginalLongiDistNumBin = 201;

struct OriginalHistograms {
    double longiHist[OriginalLongiDistNumBin]{};
    double transHist[OriginalTransDistNumBin]{};
};

OriginalHistograms OriginalSimulate();