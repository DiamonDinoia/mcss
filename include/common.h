#ifndef COMMON_H
#define COMMON_H

#include <omp.h>

#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>

#if defined(SINGLE)
using real_type = float;
#else  // SINGLE
using real_type = double;
#endif  // SINGLE

extern int numThreads;
enum Material { WATER, AIR, BONE, TISSUE, GOLD };

real_type computeScrParam(const Material &mat, real_type ptot2);

real_type computeMFP(const Material &mat, real_type beta2,
                     real_type scrpar);

real_type sampleCosTheta(real_type scrpar, real_type rn);

void rotateToLabFrame(real_type &u, real_type &v, real_type &w,
                      const real_type &u1, const real_type &u2,
                      const real_type &u3);

const real_type kMolierBc[] = {877.879, 1.02281, 1645.05, 888.813,
                               12481.2};  // 1/mm

const real_type kMolierXc2[] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072,
                                9.72643};      // MeV^2/mm
const real_type kPI = 3.14159265358979323846;  // Pi

const real_type kMASS = 0.510998910;  // electron mass [MeV]
extern Material theMaterial;    // WATER, AIR, BONE, TISSUE or GOLD
const real_type theEKin = 0.128;      // [MeV]

extern int numHists;  // #histories to simulate
const real_type thePC2 = theEKin * (theEKin + 2.0 * kMASS);
const real_type theBeta2 = thePC2 / (thePC2 + kMASS * kMASS);
const real_type theScrPar = computeScrParam(theMaterial, thePC2);
const real_type theMFP = computeMFP(theMaterial, theBeta2, theScrPar);

const real_type theLimit =
    theMFP * 33.5;  // limit of cumulative track length in units of MFP
const int longiDistNumBin = 201;
const real_type longiDistInvD = (longiDistNumBin - 1.0) / 2.0;
const int transDistNumBin = 101;

const real_type transDistInvD = (transDistNumBin - 1.0) / 1.0;

struct Track {
    real_type fPosition[3]{};   // rx, ry, rz
    real_type fDirection[3]{};  // dx, dy, dz normalised to 1
    real_type fTrackLength{};   // cumulative track length

    Track() { Reset(); }

    void Reset() {
        fPosition[0] = 0.0;
        fPosition[1] = 0.0;
        fPosition[2] = 0.0;

        fDirection[0] = 0.0;
        fDirection[1] = 0.0;
        fDirection[2] = 1.0;

        fTrackLength = 0.0;
    }
};

#endif