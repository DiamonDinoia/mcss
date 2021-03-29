#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include "compareDistributions.h"
#include "mcss_multithread.h"
#include "mcss_reference.h"

Reference::Histograms calculateOriginalDistribution() {
    return Reference::Simulate();
}

multithread::Histograms calculateMultithreadedDistribution() {
    return multithread::Simulate();
}

TEST_CASE("Correctness") {
    std::vector<double> pValues = compareDistributions();
    REQUIRE(pValues[0] >= 0.95);
    REQUIRE(pValues[1] >= 0.95);
    std::cout << std::fixed;
    std::cout << "Longitudinal K-S test p-value is " << pValues[0] << "."
              << std::endl;
    std::cout << "Transverse K-S test p-value is " << pValues[1] << "."
              << std::endl;
}

TEST_CASE("Benchmarking") {
    BENCHMARK("Original") { return calculateOriginalDistribution(); };

    BENCHMARK("Multithreaded") { return calculateMultithreadedDistribution(); };
}