#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <random>

#include "mcssOriginal.h"

enum Material { WATER, AIR, BONE, TISSUE, GOLD };
static const double OriginalkMolierBc[] = {877.879, 1.02281, 1645.05, 888.813,
                                           12481.2};  // 1/mm
static const double OriginalkMolierXc2[] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072,
                                            9.72643};  // MeV^2/mm

static const double OriginalkPI = 3.14159265358979323846;  // Pi
static const double OriginalkMASS = 0.510998910;           // electron mass [MeV]

double OriginalComputeScrParam(Material mat, double ptot2) {
    return OriginalkMolierXc2[mat] / (4.0 * ptot2 * OriginalkMolierBc[mat]);
}

double OriginalComputeMFP(Material mat, double beta2, double scrpar) {
    return beta2 * (1.0 + scrpar) / OriginalkMolierBc[mat];
}

double OriginalSampleCosTheta(double scrpar, double rn) {
    double cost = 1.0 - 2 * scrpar * rn / (1.0 - rn + scrpar);
    return std::max(-1.0, std::min(1.0, cost));
}

struct OriginalTrack {
    double fPosition[3];   // rx, ry, rz
    double fDirection[3];  // dx, dy, dz normalised to 1
    double fTrackLength;   // cummulative track length
    //
    OriginalTrack() { Reset(); }
    //
    void Reset() {
        fPosition[0] = 0.0;
        fPosition[1] = 0.0;
        fPosition[2] = 0.0;
        //
        fDirection[0] = 0.0;
        fDirection[1] = 0.0;
        fDirection[2] = 1.0;
        //
        fTrackLength = 0.0;
    }
};

void OriginalRotateToLabFrame(double& u, double& v, double& w, double u1, double u2,
                              double u3) {
    double up = u1 * u1 + u2 * u2;
    if (up > 0.) {
        up = std::sqrt(up);
        double px = u;
        double py = v;
        double pz = w;
        u = (u1 * u3 * px - u2 * py) / up + u1 * pz;
        v = (u2 * u3 * px + u1 * py) / up + u2 * pz;
        w = -up * px + u3 * pz;
    } else if (u3 < 0.) {  // phi=0  teta=pi
        u = -u;
        w = -w;
    }
}

OriginalHistograms OriginalSimulate() {
    OriginalHistograms histograms = {};

    Material theMaterial = GOLD;  // WATER, AIR, BONE, TISSUE or GOLD
    double theEKin = 0.128;       // [MeV]
    double theLimit =
            33.5;  // limit of cummulative track lenght in units of MFP
    std::size_t theNumHists = 1000000;  // #histories to simulate

    double thePC2 = theEKin * (theEKin + 2.0 * OriginalkMASS);
    double theBeta2 = thePC2 / (thePC2 + OriginalkMASS * OriginalkMASS);
    double theScrPar = OriginalComputeScrParam(theMaterial, thePC2);
    double theMFP = OriginalComputeMFP(theMaterial, theBeta2, theScrPar);
    theLimit *= theMFP;
    // Create histogram (i.e. array) for longitudinal distribution of final
    // position
    const double longiDistInvD = (OriginalLongiDistNumBin - 1.0) / 2.0;
    double* theLongiDistr = new double[OriginalLongiDistNumBin];  // on [-1,1]
    // same for the transverse distribution
    const double transDistInvD = (OriginalTransDistNumBin - 1.0) / 1.0;
    double* theTransDistr = new double[OriginalTransDistNumBin];  // on [0,1]

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0);

    OriginalTrack aTrack;
    printf(" ==== Starts the simulation of %lu trajectory histories...\n",
           theNumHists);
    for (std::size_t ih = 0; ih < theNumHists; ++ih) {
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
                const double cost = OriginalSampleCosTheta(theScrPar, dis(gen));
                const double dum0 = 1.0 - cost;
                const double sint = std::sqrt(dum0 * (2.0 - dum0));
                const double phi = 2.0 * OriginalkPI * dis(gen);
                double u1 = sint * std::cos(phi);
                double u2 = sint * std::sin(phi);
                double u3 = cost;

                OriginalRotateToLabFrame(u1, u2, u3, aTrack.fDirection[0],
                                         aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while (!stop);

        const double longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        std::size_t lIndx = (std::size_t) ((longi + 1.0) * longiDistInvD);
        ++theLongiDistr[lIndx];

        const double trans =
            std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                      aTrack.fPosition[1] * aTrack.fPosition[1]) /
            aTrack.fTrackLength;
        std::size_t tIndx = (std::size_t) (trans * transDistInvD);
        ++theTransDistr[tIndx];
    }

    double longiNormFactor = 1.0 / theNumHists * longiDistInvD;
    double transNormFactor = 1.0 / theNumHists * transDistInvD;

    for (int i = 0; i < OriginalLongiDistNumBin; i++) {
        histograms.longiHist[i] = theLongiDistr[i] * longiNormFactor;
    }

    for (int i = 0; i < OriginalTransDistNumBin; i++) {
        histograms.transHist[i] = theTransDistr[i] * transNormFactor;
        std::cout << histograms.transHist[i] << std::endl;
    }

    delete[] theLongiDistr;
    delete[] theTransDistr;
    return histograms;
}

//int main() {
//    auto start = std::chrono::high_resolution_clock::now();
//    Histograms histograms = Simulate();
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> time_span =
//        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
//    std::cout << time_span.count() << " seconds" << std::endl;
//    return 0;
//}