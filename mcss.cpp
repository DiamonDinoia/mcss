#include <unistd.h>

#include <chrono>  //for high_resolution_clock, now, duration
#include <cstdlib>
#include <fstream>
#include <iostream>

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
    auto longitudinal = histograms.longiHist;
    auto transverse = histograms.transHist;
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

int main(int argc, char* argv[]) {
    int opt;
    Material material = GOLD;
    int numHists = 1e6;
    std::string filename;
#ifdef FPGA_BUILD
    bool use_dfe = false;
#endif
#ifdef GPU
    bool use_gpu = false;
#endif

    unsigned int numThreads = std::thread::hardware_concurrency();
    // Input flag options.
    while ((opt = getopt(argc, argv, "m:n:t:f:d:g")) != -1) {
        switch (opt) {
            // Material
            case 'm':
                material = (Material)std::stoi(optarg);
                if (material < 0 || material > 4) {
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
#ifdef FPGA_BUILD
            case 'd':
                use_dfe = true;
                break;
#endif
#ifdef GPU
            case 'g':
                use_gpu = true;
                break;
#endif
            default:
                std::cerr << "Invalid program options" << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    Histograms histograms;
    const auto start = std::chrono::steady_clock::now();  // get the time...
#ifdef FPGA_BUILD
    if (use_dfe) {
        histograms = Dfe::Simulate(material, numHists);
    } else
#endif
#ifdef GPU
    if (use_gpu) {
        histograms = Gpu::Simulate(material, numHists);
    } else
#endif
    if (numThreads > 1) {
        histograms = Multithread::Simulate(material, numHists, numThreads);
    } else {
        histograms = Reference::Simulate(material, numHists);
    }

    const auto end = std::chrono::steady_clock::now();  // get the time...
    std::chrono::duration<double, std::milli> timeRequired = (end - start);
    std::cout << "Monte Carlo Simulation required " << timeRequired.count()
              << " milliseconds.\n";

    if (!filename.empty()) {
        createCSV(histograms, filename);
    }
    exit(EXIT_SUCCESS);
}