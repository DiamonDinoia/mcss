#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include "../include/mcssMultithreaded.h"
#include "../include/mcssOriginal.h"
#include "../include/test/compareDistributions.h"

Original::Histograms calculateOriginalDistribution() {
    return Original::Simulate();
}

Histograms calculateMultithreadedDistribution() {
    return Simulate();
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
    BENCHMARK("Original") {
        return calculateOriginalDistribution();
    };

    BENCHMARK("Multithreaded") {
        return calculateMultithreadedDistribution();
    };
}