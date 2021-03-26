#include "../include/test/compareDistributions.h"

// Compare the distributions of the original MCSS program with the
// multi-threaded implementation in order to check correctness.
// Returns a vector including the longitudianal and transverse
// values of the K-S test.
std::vector<double> compareDistributions() {
    auto startOriginal = std::chrono::high_resolution_clock::now();
    Original::Histograms originalHistograms = Original::Simulate();
    auto endOriginal = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationOriginal =
        std::chrono::duration_cast<std::chrono::duration<double>>(
            endOriginal - startOriginal);

    auto startMultithreaded = std::chrono::high_resolution_clock::now();
    Histograms histograms = Simulate();
    auto endMultithreaded = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationMultithreaded =
        std::chrono::duration_cast<std::chrono::duration<double>>(
            endMultithreaded - startMultithreaded);

//    std::cout << "Original runtime was " << durationOriginal.count()
//              << " seconds." << std::endl;
//    std::cout << "Multithreaded runtime was " << durationMultithreaded.count()
//              << " seconds." << std::endl;

    std::list<double> originalLongi(
        originalHistograms.longiHist,
        originalHistograms.longiHist + longiDistNumBin);
    std::list<double> originalTrans(
        originalHistograms.transHist,
        originalHistograms.transHist + transDistNumBin);
    std::list<double> newLongi(histograms.longiHist.begin(),
                               histograms.longiHist.end());
    std::list<double> newTrans(histograms.transHist.begin(),
                               histograms.transHist.end());

    double pLong = ks_test(originalLongi, newLongi);
    double pTrans = ks_test(originalTrans, newTrans);
    return std::vector<double>{pLong, pTrans};
}
