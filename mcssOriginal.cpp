#include <cmath>
#include <random>

#include "mcssOriginal.h"

OriginalHistograms OriginalSimulate() {
    double theLongiDistr[longiDistNumBin] = {0.0};
    double theTransDistr[transDistNumBin] = {0.0};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0);
    Track aTrack;

    for (int ih = 0; ih < theNumHists; ih++) {
        aTrack.Reset();
        double trackLength = 0.0;
        bool stop = false;
        do {
            double stepLength = -theMFP * std::log(dis(gen));
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
                const double cost = SampleCosTheta(theScrPar, dis(gen));
                const double dum0 = 1.0 - cost;
                const double sint = std::sqrt(dum0 * (2.0 - dum0));
                const double phi = 2.0 * kPI * dis(gen);
                double u1 = sint * std::cos(phi);
                double u2 = sint * std::sin(phi);
                double u3 = cost;

                RotateToLabFrame(u1, u2, u3, aTrack.fDirection[0],
                                         aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while (!stop);

        const double longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        const int lIndx = (int) ((longi + 1.0) * longiDistInvD);
        ++theLongiDistr[lIndx];

        const double trans =
            std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                      aTrack.fPosition[1] * aTrack.fPosition[1]) /
            aTrack.fTrackLength;
        const int tIndx = (int) (trans * transDistInvD);
        ++theTransDistr[tIndx];
    }

    double longiNormFactor = 1.0 / theNumHists * longiDistInvD;
    double transNormFactor = 1.0 / theNumHists * transDistInvD;

    OriginalHistograms originalHistograms = {};
    for (int i = 0; i < longiDistNumBin; i++) {
        originalHistograms.longiHist[i] = theLongiDistr[i] * longiNormFactor;
    }

    for (int i = 0; i < transDistNumBin; i++) {
        originalHistograms.transHist[i] = theTransDistr[i] * transNormFactor;
    }

    return originalHistograms;
}
