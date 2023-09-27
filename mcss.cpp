// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by D. Chen 2020
// Modified by R. Brandt 2022
// Modified by M. Barbone 2022
#include <VectorXoshiro/xoshiroPlusPlus.h>
#include <mixmax/mixmax.h>
#include <unistd.h>

#include <chrono>  //for high_resolution_clock, now, duration
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>

#include "mcss_multithread.h"
#include "mcss_reference.h"

#ifdef FPGA_BUILD
#include "mcss_dfe.h"
#endif

#ifdef GPU
#include "mcss_gpu.h"
#endif

// Overloaded function to create and save a histogram to a CSV file.
void createCSV(const Histograms& histograms, const std::string& filename) {
    auto          longitudinal = histograms.longiHist;
    auto          transverse   = histograms.transHist;
    std::ofstream longFile;
    longFile.open(filename + "_longitudinal.csv");
    for (int i = 0; i < longiDistNumBin; i++) {
        longFile << ((i + 0.5) / longiDistInvD - 1.0) << "," << longitudinal[i]
                 << std::endl;
    }
    longFile.close();

    std::ofstream transFile;
    transFile.open(filename + "_transverse.csv");
    for (int i = 0; i < transDistNumBin; i++) {
        transFile << (i + 0.5) / transDistInvD << "," << transverse[i]
                  << std::endl;
    }
    transFile.close();
}

namespace RNGs {
static const std::string MT{"mt"};
static const std::string MixMax{"mixmax"};
static const std::string Xoshiro{"xoshiro"};
static const std::string Philox{"philox"};
static const std::string MRG32{"mrg32"};
static const std::string Counter{"counter"};
static const std::string Chacha{"chacha"};
}  // namespace RNGs

template <typename T>
void callSimulate(const bool use_dfe, const bool use_gpu,
                  const unsigned int numThreads, const Material material,
                  const int numHists, Histograms& histograms) {
#ifdef FPGA_BUILD
    if (use_dfe) {
        histograms = Dfe::Simulate(material, numHists);
        return;
    }
#endif
#ifdef GPU
    if (use_gpu) {
        if constexpr (!std::is_same_v<T, std::mt19937_64>) {
            histograms = Gpu::Simulate<T>(material, numHists);
        } else {
            throw std::runtime_error("GPU not supported for this RNG");
        }
        return;
    }
    if constexpr (std::is_same_v<T, curandStatePhilox4_32_10> ||
                  std::is_same_v<T, curandStateMRG32k3a>) {
        throw std::runtime_error("CPU not supported for this RNG");
    }
#endif
    if (numThreads > 1) {
        histograms = Multithread::Simulate<T>(material, numHists, numThreads);
        return;
    } else {
        histograms = Reference::Simulate<T>(material, numHists);
        return;
    }
}

auto runSimulation(const std::string& generator, auto&... args) {
    if (generator == RNGs::MixMax) {
        callSimulate<MIXMAX::MixMaxRng8>(args...);
        return;
    }
    if (generator == RNGs::Xoshiro) {
        callSimulate<XoshiroPlusPlus>(args...);
        return;
    }
#ifdef GPU
    if (generator == RNGs::Philox) {
        callSimulate<curandStatePhilox4_32_10_t>(args...);
        return;
    }
    if (generator == RNGs::MRG32) {
        callSimulate<curandStateMRG32k3a>(args...);
        return;
    }
#endif
    if (generator == RNGs::MT) {
        callSimulate<std::mt19937_64>(args...);
        return;
    }
    if (generator == RNGs::Counter) {
        callSimulate<CounterRNG>(args...);
        return;
    }
    if (generator == RNGs::Chacha) {
        callSimulate<ChaCha8>(args...);
        return;
    }
    throw std::runtime_error("Invalid RNG selected " + generator);
}

int main(int argc, char* argv[]) {
    int          opt;
    Material     material = WATER;
    int          numHists = 1e9;
    std::string  filename;
    std::string  generator  = RNGs::MT;
    bool         use_dfe    = false;
    bool         use_gpu    = false;

    unsigned int numThreads = std::thread::hardware_concurrency();
    // Input flag options.
    while ((opt = getopt(argc, argv, "m:n:t:f:d:gr:")) != -1) {
        switch (opt) {
            // Material
            case 'm':
                material = (Material)std::stoi(optarg);
                if (material > 4) {
                    std::cerr << "Invalid material" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            // Number of histories
            case 'n':
                numHists = std::stoi(optarg);
                if (numHists < 0) {
                    std::cerr << "Negative number of histories entered"
                              << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            // Number of threads
            case 't':
                numThreads = std::stoi(optarg);
                if (numThreads == 0) {
                    std::cerr << "Negative number of threads entered"
                              << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            case 'f':
                filename = optarg;
                break;
            case 'd':
                use_dfe = true;
                break;
            case 'g':
                use_gpu = true;
                break;
            case 'r':
                generator = optarg;
                std::transform(generator.begin(), generator.end(),
                               generator.begin(),
                               [](unsigned char c) { return std::tolower(c); });
                std::cout << "Using " << generator << " RNG" << std::endl;
                break;
            default:
                std::cerr << "Invalid program options" << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    Histograms histograms;
    const auto start = std::chrono::steady_clock::now();  // get the time...
    runSimulation(generator, use_dfe, use_gpu, numThreads, material, numHists,
                  histograms);
    const auto end = std::chrono::steady_clock::now();  // get the time...
    std::chrono::duration<double, std::milli> timeRequired = (end - start);
    std::cout << "Monte Carlo Simulation required " << timeRequired.count()
              << " milliseconds.\n";

    if (!filename.empty()) { createCSV(histograms, filename); }
    exit(EXIT_SUCCESS);
}