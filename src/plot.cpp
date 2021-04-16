#include "mcss_reference.h"
#include "common.h"
#include "mcss_multithread.h"
#include "util/matplotlibcpp.h"

namespace plt = matplotlibcpp;

void plot(const std::vector<real_type>& v1, const std::vector<real_type>& v2, const std::string& title) {
    plt::named_plot("Multithreaded", v1);
    plt::named_plot("Reference", v2);
    plt::title(title);
    plt::legend();
    plt::show();
}


int main() {
    auto multithreadedHistograms = Multithread::Simulate();
    auto referenceHistograms = Reference::Simulate();
    std::vector<real_type> referenceLongi(
        referenceHistograms.longiHist,
        referenceHistograms.longiHist + longiDistNumBin);
    std::vector<real_type> referenceTrans(
        referenceHistograms.transHist,
        referenceHistograms.transHist + transDistNumBin);

    plot(multithreadedHistograms.longiHist, referenceLongi, "Plot of reference and multithreaded longitudinal histograms");
    plot(multithreadedHistograms.transHist, referenceTrans, "Plot of reference and multithreaded transverse histograms");
    return EXIT_SUCCESS;
}