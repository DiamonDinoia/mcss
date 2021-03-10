#include <fstream>
#include <iostream>

#include "mcssOriginal.h"
#include "MultithreadedMCSS.h"
#include "Utils/Utils.h"
#include "Utils/ks-test.h"

// Compare the distributions of the original MCSS program with the
// multi-threaded implementation in order to check correctness.
int main() {
    Histograms histograms = Simulate();
    OriginalHistograms originalHistograms= OriginalSimulate();

    std::list<double> originalLongi(originalHistograms.longiHist, originalHistograms.longiHist + longiDistNumBin);
    std::list<double> originalTrans(originalHistograms.transHist, originalHistograms.transHist + transDistNumBin);
    std::list<double> newLongi(histograms.longiHist.begin(), histograms.longiHist.end());
    std::list<double> newTrans(histograms.transHist.begin(), histograms.transHist.end());

//    for (int i = 0; i < transDistNumBin; i++) {
//        std::cout << originalTrans.front() << " " << newTrans.front() << std::endl;
//        originalTrans.pop_front();
//        newTrans.pop_front();
//    }

    double pLong = ks_test(originalLongi, newLongi);
    double pTrans = ks_test(originalTrans, newTrans);
    std::cout << "Longitudinal K-S test p-value is " << pLong << std::endl;
    std::cout << "Transverse K-S test p-value is " << pTrans << std::endl;

    return 0;
}
