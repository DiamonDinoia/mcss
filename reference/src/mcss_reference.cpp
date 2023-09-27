// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by D. Chen 2020
// Modified by M. Barbone 2020

#include "mcss_reference.h"

#include <VectorXoshiro/xoshiroPlusPlus.h>
#include <mixmax/mixmax.h>

#include <cmath>
#include <random>

#include "common.h"

// Minimally-altered, single-threaded MCSS implementation.
namespace Reference {
template <typename T>
Histograms Simulate(const Material material, const int numHists) {
    const real_type theScrPar = computeScrParam(material, thePC2);
    const real_type theMFP    = computeMFP(material, theBeta2, theScrPar);
    const real_type theLimit  = theMFP * 33.5;
    //
    real_type          theLongiDistr[longiDistNumBin] = {0.0};
    real_type          theTransDistr[transDistNumBin] = {0.0};

    std::random_device rd;
    T       gen(42);
    std::uniform_real_distribution<real_type> dis(0, 1.0);
    Track                                     aTrack;
    for (int ih = 0; ih < numHists; ih++) {
        aTrack.Reset();
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
                                 aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while (!stop);
        const real_type longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        const int       lIndx = (int)((longi + 1.0) * longiDistInvD);
        ++theLongiDistr[lIndx];

        const real_type trans =
            std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                      aTrack.fPosition[1] * aTrack.fPosition[1]) /
            aTrack.fTrackLength;
        const int tIndx = (int)(trans * transDistInvD);
        ++theTransDistr[tIndx];
    }

    real_type  longiNormFactor = 1.0 / numHists * longiDistInvD;
    real_type  transNormFactor = 1.0 / numHists * transDistInvD;

    Histograms histograms{longiDistNumBin, transDistNumBin};
    for (int i = 0; i < longiDistNumBin; i++) {
        histograms.longiHist[i] = theLongiDistr[i] * (longiDistInvD / numHists);
    }

    for (int i = 0; i < transDistNumBin; i++) {
        histograms.transHist[i] = theTransDistr[i] * (transDistInvD / numHists);
    }

    return histograms;
}
template Histograms Simulate<XoshiroPlusPlus>(Material, int);
template Histograms Simulate<MIXMAX::MixMaxRng8>(Material, int);
template Histograms Simulate<std::mt19937_64>(Material, int);
template Histograms Simulate<CounterRNG>(Material, int);
template Histograms Simulate<ChaCha8>(Material, int);

}  // namespace Reference