#include "common.h"
#include "matplotlibcpp.h"
#include "mcss_multithread.h"
#include "mcss_reference.h"

namespace plt = matplotlibcpp;

void plot(const std::vector<real_type>& v1, const std::vector<real_type>& v2,
          const std::string& title) {
    plt::named_plot("Gold", v1);
    plt::named_plot("Air", v2);
    plt::title(title);
    plt::legend();
    plt::show();
}

int main() {
    theMaterial = GOLD;
    numHists = 1000000;

    auto goldHistograms = Multithread::Simulate();

    theMaterial = WATER;
    std::cout << theMaterial << std::endl;
    std::cout << numHists << std::endl;
    auto airHistograms = Multithread::Simulate();
//    auto referenceHistograms = Reference::Simulate();
//    std::vector<real_type> referenceLongi(
//        referenceHistograms.longiHist,
//        referenceHistograms.longiHist + longiDistNumBin);
//    std::vector<real_type> referenceTrans(
//        referenceHistograms.transHist,
//        referenceHistograms.transHist + transDistNumBin);

    plot(goldHistograms.longiHist, airHistograms.longiHist,
         "Plot of the longitudinal histograms for Air and Gold - 1,000,000 histories");
    plot(airHistograms.transHist, airHistograms.transHist,
         "Plot of the transverse histograms for Air and Gold -  1,000,000 histories");
    return EXIT_SUCCESS;
}