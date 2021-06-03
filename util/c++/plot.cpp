#include <iostream>

#include "common.h"
#include "mcss_multithread.h"
#include "mcss_reference.h"

// Overloaded function to create and save a histogram to a CSV file.
void createCSV(const Reference::Histograms& histograms) {
    auto longitudinal = histograms.longiHist;
    auto transverse = histograms.transHist;
    std::ofstream longFile;
    longFile.open("../../plots/reference_longitudinal.csv");
    for (int i = 0; i < longiDistNumBin; i++) {
        longFile << ((i + 0.5) / longiDistInvD - 1.0) << "," << longitudinal[i]
                 << std::endl;
    }
    longFile.close();

    std::ofstream transFile;
    transFile.open("../../plots/reference_transverse.csv");
    for (int i = 0; i < transDistNumBin; i++) {
        transFile << (i + 0.5) / transDistInvD << "," << transverse[i]
                  << std::endl;
    }
    transFile.close();
}

// Overloaded function to create and save a histogram to a CSV file.
void createCSV(const Multithread::Histograms& histograms) {
    auto longitudinal = histograms.longiHist;
    auto transverse = histograms.transHist;
    std::ofstream longFile;
    longFile.open("../../plots/multithreaded_longitudinal.csv");
    for (int i = 0; i < longiDistNumBin; i++) {
        longFile << ((i + 0.5) / longiDistInvD - 1.0) << "," << longitudinal[i]
                 << std::endl;
    }
    longFile.close();

    std::ofstream transFile;
    transFile.open("../../plots/multithreaded_transverse.csv");
    for (int i = 0; i < transDistNumBin; i++) {
        transFile << (i + 0.5) / transDistInvD << "," << transverse[i]
                  << std::endl;
    }
    transFile.close();
}

// Creates data files representing histograms.
int main() {
    auto multithreadedHistograms = Multithread::Simulate(GOLD, 1000000);
    auto referenceHistograms = Reference::Simulate(GOLD, 1000000);
    //    std::vector<real_type> referenceLongi(
    //        referenceHistograms.longiHist,
    //        referenceHistograms.longiHist + longiDistNumBin);
    //    std::vector<real_type> referenceTrans(
    //        referenceHistograms.transHist,
    //        referenceHistograms.transHist + transDistNumBin);

    createCSV(multithreadedHistograms);
    createCSV(referenceHistograms);
    return EXIT_SUCCESS;
}