#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <ksTest.h>
#include <mcss_multithread.h>
#include <mcss_reference.h>

#include <catch2/catch.hpp>

// Compare the distributions of the original MCSS program with the
// multi-threaded implementation in order to check correctness.
// Returns a vector including the longitudinal and transverse
// values of the K-S test.
std::vector<double> compareDistributions(Reference::Histograms originalHistograms, Multithread::Histograms multithreadHistograms) {
    std::vector<real_type> originalLongi(
        originalHistograms.longiHist,
        originalHistograms.longiHist + longiDistNumBin);
    std::vector<real_type> originalTrans(
        originalHistograms.transHist,
        originalHistograms.transHist + transDistNumBin);

    double pLong = ks_test(originalLongi, multithreadHistograms.longiHist);
    double pTrans = ks_test(originalTrans, multithreadHistograms.transHist);
    return std::vector<double>{pLong, pTrans};
}

Reference::Histograms calculateReferenceDistribution() {
    return Reference::Simulate();
}

Multithread::Histograms calculateMultithreadedDistribution() {
    return Multithread::Simulate();
}

TEST_CASE("Correctness") {
    auto referenceHistograms = calculateReferenceDistribution();
    auto multithreadedHistograms = calculateMultithreadedDistribution();

    SECTION("Default K-S test p values are statistically significant") {
        auto pValues = compareDistributions(referenceHistograms, multithreadedHistograms);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
        std::cout << std::fixed;
        std::cout << "Longitudinal K-S test p-value is " << pValues[0] << "."
                  << std::endl;
        std::cout << "Transverse K-S test p-value is " << pValues[1] << "."
                  << std::endl;
    }

    SECTION("Longitudinal and transverse distributions disagree with each other") {
        auto pValues = ks_test(multithreadedHistograms.transHist, multithreadedHistograms.longiHist);
        REQUIRE(pValues < 0.1);
    }

    SECTION("Histogram lengths are consistent") {
        REQUIRE(sizeof(referenceHistograms.longiHist) / sizeof(referenceHistograms.longiHist[0]) == multithreadedHistograms.longiHist.size());
        REQUIRE(sizeof(referenceHistograms.transHist) / sizeof(referenceHistograms.transHist[0]) == multithreadedHistograms.transHist.size());
        REQUIRE(multithreadedHistograms.longiHist.size() != multithreadedHistograms.transHist.size());
    }

    SECTION("Water, 1,000,000 histories") {
        theMaterial = WATER;
        numHists = 1000000;
        auto reference = calculateReferenceDistribution();
        auto multithreaded = calculateMultithreadedDistribution();
        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
    }

    SECTION("Air, 100,000 histories") {
        theMaterial = AIR;
        numHists = 100000;
        auto reference = calculateReferenceDistribution();
        auto multithreaded = calculateMultithreadedDistribution();
        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
    }

    SECTION("Bone, 100,000 histories") {
        theMaterial = BONE;
        numHists = 100000;
        auto reference = calculateReferenceDistribution();
        auto multithreaded = calculateMultithreadedDistribution();
        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
    }

    SECTION("Tissue, 500,000 histories") {
        theMaterial = TISSUE;
        numHists = 500000;
        auto reference = calculateReferenceDistribution();
        auto multithreaded = calculateMultithreadedDistribution();
        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
    }

    //TODO: Test floats and doubles
    //TODO: Edge cases?
    SECTION("Floats work") {

    }

    SECTION("Doubles work") {

    }
}

TEST_CASE("Benchmarking") {
    BENCHMARK("Reference") {
        return calculateReferenceDistribution();
    };

    BENCHMARK("Multithreaded") {
        return calculateMultithreadedDistribution();
    };
}