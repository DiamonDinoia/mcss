#include "../include/mcss.h"

std::vector<std::vector<real_type>> initialiseHistogram(int numThreads,
                                                        int numBins) {
    std::vector<std::vector<real_type>> histogram;
    for (int i = 0; i < numThreads; i++) {
        std::vector<real_type> sub_vector(numBins, 0.0);
        histogram.push_back(sub_vector);
    }
    return histogram;
}

Histograms Simulate() {
    omp_set_num_threads(NUM_THREADS);

    std::vector<real_type> globalLongiDistr(longiDistNumBin);
    std::vector<real_type> globalTransDistr(transDistNumBin);

    std::vector<std::vector<real_type>> threadsLongiHists =
        initialiseHistogram(NUM_THREADS, longiDistNumBin);
    std::vector<std::vector<real_type>> threadsTransHists =
        initialiseHistogram(NUM_THREADS, transDistNumBin);

#pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < theNumHists; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1.0);

        Track aTrack;
        aTrack.Reset();
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
                const real_type cost = SampleCosTheta(theScrPar, dis(gen));
                const real_type dum0 = 1.0 - cost;
                const real_type sint = std::sqrt(dum0 * (2.0 - dum0));
                const real_type phi = 2.0 * kPI * dis(gen);
                real_type u1 = sint * std::cos(phi);
                real_type u2 = sint * std::sin(phi);
                real_type u3 = cost;
                RotateToLabFrame(u1, u2, u3, aTrack.fDirection[0],
                                 aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while (!stop);

        const real_type longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        real_type lIndx = (longi + 1.0) * longiDistInvD;
        threadsLongiHists[omp_get_thread_num()][lIndx]++;

        const real_type trans =
            std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                      aTrack.fPosition[1] * aTrack.fPosition[1]) /
            aTrack.fTrackLength;
        real_type tIndx = trans * transDistInvD;
        threadsTransHists[omp_get_thread_num()][tIndx]++;
    }

    real_type longiNormFactor = 1.0 / theNumHists * longiDistInvD;
    real_type transNormFactor = 1.0 / theNumHists * transDistInvD;
    for (int i = 0; i < NUM_THREADS; i++) {
        for (int j = 0; j < longiDistNumBin; j++) {
            globalLongiDistr[j] += threadsLongiHists[i][j] * longiNormFactor;
        }
        for (int j = 0; j < transDistNumBin; j++) {
            globalTransDistr[j] += threadsTransHists[i][j] * transNormFactor;
        }
    }

    Histograms histograms = {globalLongiDistr, globalTransDistr};
    return histograms;
}
