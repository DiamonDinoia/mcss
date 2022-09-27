#include "mcss_multithread.h"

#include <omp.h>

#include <algorithm>
#include <random>
#include <array>
#include "common.h"

namespace Multithread {

// Create and initialise histograms with correct dimensions.
std::vector<std::vector<real_type>> initialiseHistogram(int numThreads,
                                                        int numBins) {
    std::vector<std::vector<real_type>> histogram;
    for (int i = 0; i < numThreads; i++) {
        std::vector<real_type> sub_vector(numBins, 0.0);
        histogram.push_back(sub_vector);
    }
    return histogram;
}

// Simulates a given number of particle histories and plots the outputs
// on transverse and longitudinal histograms.
Histograms Simulate(Material material, int numHists, unsigned int numThreads) {
    const real_type theScrPar = computeScrParam(material, thePC2);
    const real_type theMFP = computeMFP(material, theBeta2, theScrPar);
    const real_type theLimit = theMFP * 33.5;

    omp_set_num_threads(numThreads);

    // Final longitudinal and transverse histograms.
    std::vector<real_type> globalLongiDistr(longiDistNumBin, 0);
    std::vector<real_type> globalTransDistr(transDistNumBin, 0);

    // A vector of num_threads histograms, each dedicated to a
    // different thread. Each histogram is independently thread-safe.

    // Main loop to simulate a particle history.
    // Multi-threaded using OpenMP threading.
#pragma omp parallel num_threads(numThreads)
    {
        unsigned int seed;
        seed = std::random_device()();
        std::mt19937 gen(seed);
        std::uniform_real_distribution<> dis(0, 1.0);
        std::array<real_type, longiDistNumBin> threadsLongiHist{0};
        std::array<real_type, transDistNumBin> threadsTransHist{0};
#pragma omp for
        for (int i = 0; i < numHists; i++) {
            // Generate a random decimal between 0 and 1.
            Track aTrack{};
            real_type trackLength = 0.0;
            bool stop = false;
            do {
                real_type stepLength = -theMFP * std::log(dis(gen));
                trackLength += stepLength;
                if (trackLength > theLimit) {
                    stepLength = theLimit - aTrack.fTrackLength;
                    stop = true;
                }
                aTrack.fPosition[0] += aTrack.fDirection[0] * stepLength;
                aTrack.fPosition[1] += aTrack.fDirection[1] * stepLength;
                aTrack.fPosition[2] += aTrack.fDirection[2] * stepLength;
                aTrack.fTrackLength += stepLength;
                if (!stop) {
                    const real_type cost = sampleCosTheta(theScrPar, dis(gen));
                    const real_type dum0 = 1.0 - cost;
                    const real_type sint = std::sqrt(dum0 * (2.0 - dum0));
                    const real_type phi = 2.0 * kPI * dis(gen);
                    real_type u1 = sint * std::cos(phi);
                    real_type u2 = sint * std::sin(phi);
                    real_type u3 = cost;
                    rotateToLabFrame(u1, u2, u3, aTrack.fDirection[0],
                                     aTrack.fDirection[1],
                                     aTrack.fDirection[2]);
                    aTrack.fDirection[0] = u1;
                    aTrack.fDirection[1] = u2;
                    aTrack.fDirection[2] = u3;
                }
            } while (!stop);

            // Calculate final longitudinal location.
            const real_type longi = aTrack.fPosition[2] / aTrack.fTrackLength;
            const unsigned lIndx = (longi + 1.0) * longiDistInvD;
            // Increment the relevent element of the thread-specific
            // longitudinal histogram.
            threadsLongiHist[lIndx]++;
            const real_type trans =
                std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                          aTrack.fPosition[1] * aTrack.fPosition[1]) /
                aTrack.fTrackLength;
            const unsigned tIndx = trans * transDistInvD;
            threadsTransHist[tIndx]++;
        }
        for (int j = 0; j < longiDistNumBin; j++) {
#pragma omp atomic
            globalLongiDistr[j] += threadsLongiHist[j];
        }
        for (int j = 0; j < transDistNumBin; j++) {
#pragma omp atomic
            globalTransDistr[j] += threadsTransHist[j];
        }
    } // parallel region end

    for (int j = 0; j < longiDistNumBin; j++) {
        globalLongiDistr[j] *= (longiDistInvD / numHists);
    }
    for (int j = 0; j < transDistNumBin; j++) {
        globalTransDistr[j] *= (transDistInvD / numHists);
    }
    return {globalLongiDistr, globalTransDistr};

    // Thread-specific histograms are combined and normalised
    // to form the overall distributions.
}
}  // namespace Multithread
