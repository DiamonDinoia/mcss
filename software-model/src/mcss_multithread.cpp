// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by D. Chen 2020
// Modified by M. Barbone 2020

#include "mcss_multithread.h"

#include <VectorXoshiro/xoshiroPlusPlus.h>
#include <mixmax/mixmax.h>
#include <omp.h>

#include <array>
#include <random>

#include "common.h"

namespace Multithread {

// Simulates a given number of particle histories and plots the outputs
// on transverse and longitudinal histograms.
template <typename T>
Histograms Simulate(Material material, int numHists, unsigned int numThreads) {
    const real_type theScrPar = computeScrParam(material, thePC2);
    const real_type theMFP    = computeMFP(material, theBeta2, theScrPar);
    const real_type theLimit  = theMFP * 33.5;

    omp_set_num_threads(numThreads);

    auto getGenerator = [](const std::uint64_t seed) {
        if constexpr (std::is_same_v<T, std::mt19937_64>) {
            std::seed_seq              seq{seed};
            std::vector<std::uint32_t> seeds(omp_get_thread_num()+1);
            seq.generate(seeds.begin(), seeds.end());
            return std::mt19937_64{seeds.back()};
        } else
            return T{seed, static_cast<uint64_t>(omp_get_thread_num())};
    };

    // Final longitudinal and transverse histograms.
    std::vector<real_type> globalLongiDistr(longiDistNumBin, 0);
    std::vector<real_type> globalTransDistr(transDistNumBin, 0);

    // A vector of num_threads histograms, each dedicated to a
    // different thread. Each histogram is independently thread-safe.

    // Main loop to simulate a particle history.
    // Multi-threaded using OpenMP threading.
#pragma omp parallel num_threads(numThreads) default(none)                  \
    shared(globalLongiDistr, globalTransDistr, numHists, theScrPar, theMFP, \
               theLimit, getGenerator)
    {
        const auto                             seed = std::random_device()();
        T                                      gen  = getGenerator(42);
        std::uniform_real_distribution<>       dis(0, 1.0);
        std::array<real_type, longiDistNumBin> threadsLongiHist{0};
        std::array<real_type, transDistNumBin> threadsTransHist{0};
#pragma omp for
        for (int i = 0; i < numHists; i++) {
            // Generate a random decimal between 0 and 1.
            Track     aTrack{};
            real_type trackLength = 0.0;
            bool      stop        = false;
            do {
                real_type stepLength = -theMFP * std::log(dis(gen));
                trackLength += stepLength;
                if (trackLength > theLimit) {
                    stepLength = theLimit - aTrack.fTrackLength;
                    stop       = true;
                }
                aTrack.fPosition[0] += aTrack.fDirection[0] * stepLength;
                aTrack.fPosition[1] += aTrack.fDirection[1] * stepLength;
                aTrack.fPosition[2] += aTrack.fDirection[2] * stepLength;
                aTrack.fTrackLength += stepLength;
                if (!stop) {
                    const real_type cost = sampleCosTheta(theScrPar, dis(gen));
                    const real_type dum0 = 1.0 - cost;
                    const real_type sint = std::sqrt(dum0 * (2.0 - dum0));
                    const real_type phi  = 2.0 * kPI * dis(gen);
                    real_type       u1   = sint * std::cos(phi);
                    real_type       u2   = sint * std::sin(phi);
                    real_type       u3   = cost;
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
            const unsigned  lIndx = (longi + 1.0) * longiDistInvD;
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
    }  // parallel region end

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
template Histograms Simulate<XoshiroPlusPlus>(Material, int, unsigned int);
template Histograms Simulate<MIXMAX::MixMaxRng8>(Material, int, unsigned int);
template Histograms Simulate<std::mt19937_64>(Material, int, unsigned int);
template Histograms Simulate<CounterRNG>(Material, int, unsigned int);
template Histograms Simulate<ChaCha8>(Material, int, unsigned int);

}  // namespace Multithread
