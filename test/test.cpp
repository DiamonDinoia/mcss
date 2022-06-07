#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include "ksTest.h"
#include "mcss_multithread.h"
#include "mcss_reference.h"

#ifdef FPGA_BUILD
#include "mcss_dfe.h"
#endif

#ifdef GPU
#include "mcss_gpu.h"
#endif

// Compare the distributions of the original MCSS program with the
// multi-threaded implementation in order to check correctness.
// Returns a vector including the longitudinal and transverse
// values of the K-S test.
std::vector<double> compareDistributions(const Histograms& originalHistograms,
                                         const Histograms& histograms) {
    double pLong = ks_test(originalHistograms.longiHist, histograms.longiHist);
    double pTrans = ks_test(originalHistograms.transHist, histograms.transHist);
    return std::vector<double>{pLong, pTrans};
}

TEST_CASE("Correctness") {
    const Material material = GOLD;
    const int histories = 1e6;
    std::cout << "Starting correctness tests" << std::endl;
    auto referenceHistograms = Reference::Simulate();
    auto multithreadedHistograms = Multithread::Simulate(material, histories);
#ifdef FPGA_BUILD
    auto dfeHistograms = Dfe::Simulate(material, histories);
#endif

#ifdef GPU
    auto gpuHistograms = Gpu::Simulate(material, histories);
#endif

    std::cout << "Finished simulations" << std::endl;

    SECTION("Default K-S test p values are statistically significant") {
        auto pValues =
            compareDistributions(referenceHistograms, multithreadedHistograms);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
        std::cout << std::fixed;
        std::cout << "Multithread: Longitudinal K-S test p-value is "
                  << pValues[0] << "." << std::endl;
        std::cout << "Multithread: Transverse K-S test p-value is "
                  << pValues[1] << "." << std::endl;
#ifdef FPGA_BUILD

        pValues = compareDistributions(referenceHistograms, dfeHistograms);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
        std::cout << "DFE: Longitudinal K-S test p-value is " << pValues[0]
                  << "." << std::endl;
        std::cout << "DFE: Transverse K-S test p-value is " << pValues[1] << "."
                  << std::endl;
#endif

#ifdef GPU
        pValues = compareDistributions(referenceHistograms, gpuHistograms);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
        std::cout << "GPU: Longitudinal K-S test p-value is " << pValues[0]
                  << "." << std::endl;
        std::cout << "GPU: Transverse K-S test p-value is " << pValues[1] << "."
                  << std::endl;
#endif
    }

    SECTION(
        "Longitudinal and transverse distributions disagree with each other") {
        auto pValues = ks_test(multithreadedHistograms.transHist,
                               multithreadedHistograms.longiHist);
        REQUIRE(pValues < 0.1);
    }

    SECTION("Histogram lengths are consistent") {
        REQUIRE(referenceHistograms.longiHist.size() ==
                multithreadedHistograms.longiHist.size());
        REQUIRE(referenceHistograms.transHist.size() ==
                multithreadedHistograms.transHist.size());
    }

    SECTION("Water, 1,000,000 histories") {
        auto reference = Reference::Simulate(WATER, 1000000);
        auto multithreaded = Multithread::Simulate(WATER, 1000000);
#ifdef FPGA_BUILD
        auto dfe = Dfe::Simulate(WATER, 1000000);
#endif

#ifdef GPU
        auto gpu = Gpu::Simulate(WATER, 1000000);
#endif

        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#ifdef FPGA_BUILD
        pValues = compareDistributions(reference, dfe);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif

#ifdef GPU
        pValues = compareDistributions(reference, gpu);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif
    }

    SECTION("Air, 1,000,000 histories") {
        auto reference = Reference::Simulate(AIR, 1000000);
        auto multithreaded = Multithread::Simulate(AIR, 1000000);
#ifdef FPGA_BUILD
        auto dfe = Dfe::Simulate(AIR, 1000000);
#endif

#ifdef GPU
        auto gpu = Gpu::Simulate(AIR, 1000000);
#endif

        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#ifdef FPGA_BUILD
        pValues = compareDistributions(reference, dfe);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif

#ifdef GPU
        pValues = compareDistributions(reference, gpu);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif
    }

    SECTION("Bone, 1,000,000 histories") {
        auto reference = Reference::Simulate(BONE, 1000000);
        auto multithreaded = Multithread::Simulate(BONE, 1000000);
#ifdef FPGA_BUILD
        auto dfe = Dfe::Simulate(BONE, 1000000);
#endif

#ifdef GPU
        auto gpu = Gpu::Simulate(BONE, 1000000);
#endif
        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#ifdef FPGA_BUILD
        pValues = compareDistributions(reference, dfe);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif
#ifdef GPU
        pValues = compareDistributions(reference, gpu);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif
    }

    SECTION("Tissue, 1,000,000 histories") {
        auto reference = Reference::Simulate(TISSUE, 1000000);
        auto multithreaded = Multithread::Simulate(TISSUE, 1000000);
#ifdef FPGA_BUILD

        auto dfe = Dfe::Simulate(TISSUE, 1000000);
#endif

#ifdef GPU
        auto gpu = Gpu::Simulate(TISSUE, 1000000);
#endif

        auto pValues = compareDistributions(reference, multithreaded);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#ifdef FPGA_BUILD
        pValues = compareDistributions(reference, dfe);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif

#ifdef GPU
        pValues = compareDistributions(reference, gpu);
        REQUIRE(pValues[0] >= 0.95);
        REQUIRE(pValues[1] >= 0.95);
#endif
    }
}

TEST_CASE("Benchmarking numHists = 1e8") {
    int numHists = 1e8;
    Material material = GOLD;
    BENCHMARK("Reference") { return Reference::Simulate(material, numHists); };
#ifdef FPGA_BUILD
    BENCHMARK("DFE") { return Dfe::Simulate(material, numHists); };
#endif

#ifdef GPU
    BENCHMARK("GPU") { return Gpu::Simulate(material, numHists); };
#endif

    BENCHMARK("Multithreaded") {
        return Multithread::Simulate(material, numHists);
    };
}

TEST_CASE("Benchmarking numHists = 1e9") {
    int numHists = 1e9;
    Material material = GOLD;
    BENCHMARK("Reference") { return Reference::Simulate(material, numHists); };
#ifdef FPGA_BUILD
    BENCHMARK("DFE") { return Dfe::Simulate(material, numHists); };
#endif

#ifdef GPU
    BENCHMARK("GPU") { return Gpu::Simulate(material, numHists); };
#endif

    BENCHMARK("Multithreaded") {
        return Multithread::Simulate(material, numHists);
    };
}