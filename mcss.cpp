
// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------


#include <cstdio>
#include <cmath>
#include <random>

#include <omp.h>
#include <ctime>
#include <iostream>
#include <chrono>

using real_type = float;

enum Material { WATER, AIR, BONE, TISSUE, GOLD};

real_type ComputeScrParam(const Material &mat, real_type ptot2);
real_type ComputeMFP(const Material &mat, real_type beta2, real_type scrpar);

static const real_type kMolierBc[]  = {877.879, 1.02281, 1645.05, 888.813, 12481.2 }; // 1/mm
static const real_type kMolierXc2[] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072, 9.72643 }; // MeV^2/mm

static const real_type kPI          =  3.14159265358979323846; // Pi
static const real_type kMASS        =  0.510998910;            // electron mass [MeV]

Material    theMaterial =   GOLD;  // WATER, AIR, BONE, TISSUE or GOLD
real_type      theEKin     =   0.128; // [MeV]
std::size_t theNumHists = 1000000; // #histories to simulate

real_type   thePC2      = theEKin * (theEKin + 2.0 * kMASS);
real_type   theBeta2    = thePC2 / (thePC2 + kMASS * kMASS);
real_type   theScrPar   = ComputeScrParam(theMaterial, thePC2);
real_type   theMFP      = ComputeMFP(theMaterial, theBeta2, theScrPar);
real_type   theLimit = theMFP * 33.5; // limit of cumulative track length in units of MFP

real_type ComputeScrParam(const Material &mat, const real_type ptot2) {
    return kMolierXc2[mat] / (4.0 * ptot2 * kMolierBc[mat]);
}

real_type ComputeMFP(const Material &mat, const real_type beta2, const real_type scrpar) {
    return beta2 * (1.0 + scrpar) / kMolierBc[mat];
}

real_type SampleCosTheta(const real_type scrpar, const real_type rn) {
    real_type cost = 1.0 - 2 * scrpar * rn / (1.0 - rn + scrpar);
    return std::max((real_type) -1.0, std::min((real_type) 1.0, cost));
}

struct Track {
    real_type fPosition[3]{};   // rx, ry, rz
    real_type fDirection[3]{};  // dx, dy, dz normalised to 1
    real_type fTrackLength{};   // cumulative track length

    Track() {
    Reset();
    }

    void Reset() {
    fPosition[0]  = 0.0;
    fPosition[1]  = 0.0;
    fPosition[2]  = 0.0;

    fDirection[0] = 0.0;
    fDirection[1] = 0.0;
    fDirection[2] = 1.0;

    fTrackLength  = 0.0;
    }
};

void RotateToLabFrame(real_type &u, real_type &v, real_type &w, real_type u1, real_type u2, real_type u3) {
    real_type up = u1 * u1 + u2 * u2;
    if (up > 0.) {
        up = std::sqrt(up);
        const real_type px = u;
        const real_type py = v;
        const real_type pz = w;
        u = (u1 * u3 * px - u2 * py) / up + u1 * pz;
        v = (u2 * u3 * px + u1 * py) / up + u2 * pz;
        w = -up * px + u3 * pz;
    } else if (u3 < 0.) {       // phi=0  teta=pi
        u = -u;
        w = -w;
    }
}

void addLocalDistrToGlobal(int size, std::size_t *targetDistr, const std::size_t *sourceDistr) {
    for (int i = 0; i < size - 1; i++) {
        targetDistr[i] += sourceDistr[i];
    }
}

void Simulate() {
    const int longiDistNumBin   = 201;
    const real_type longiDistInvD  = (longiDistNumBin - 1.0) / 2.0;

    const int transDistNumBin   = 101;
    const real_type transDistInvD  = (transDistNumBin - 1.0) / 1.0;

    std::size_t* globalLongiDistr  = new std::size_t[longiDistNumBin];
    std::size_t* globalTransDistr  = new std::size_t[transDistNumBin];

#pragma omp parallel for shared(globalLongiDistr, globalTransDistr)
    for (int i = 0; i < theNumHists; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1.0);

        std::size_t* theLongiDistr  = new std::size_t[longiDistNumBin]; // on [-1,1]

        std::size_t* theTransDistr  = new std::size_t[transDistNumBin]; // on [0,1]

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
                RotateToLabFrame(u1, u2, u3, aTrack.fDirection[0], aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while (!stop);

        const real_type longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        std::size_t lIndx = (std::size_t) ((longi + 1.0) * longiDistInvD);
        ++theLongiDistr[lIndx];

        const real_type trans =
                std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] + aTrack.fPosition[1] * aTrack.fPosition[1]) /
                aTrack.fTrackLength;
        std::size_t tIndx = (std::size_t) (trans * transDistInvD);
        ++theTransDistr[tIndx];

#pragma omp critical
        addLocalDistrToGlobal(longiDistNumBin, globalLongiDistr, theLongiDistr);
        delete[] theLongiDistr;

#pragma omp critical
        addLocalDistrToGlobal(transDistNumBin, globalTransDistr, theTransDistr);
        delete[] theTransDistr;
    }

    printf(" ==== Completed the simulation of %lu trajectory histories.\n", theNumHists);
    printf(" ==== Writing results to files...\n");

    real_type longiNormFactor = 1.0 / theNumHists * longiDistInvD;
    FILE* f = fopen("Res_Longi.dat", "w");
    for (int i = 0; i < longiDistNumBin - 1; ++i) {
        real_type longiMid = ((i + 0.5) / longiDistInvD - 1.0);
        fprintf(f, "%g %g\n", longiMid, globalLongiDistr[i] * longiNormFactor);
    }
    delete[] globalLongiDistr;
    fclose(f);

    real_type transNormFactor = 1.0 / theNumHists * transDistInvD;
    f = fopen("Res_Trans.dat", "w");
    for (int i = 0; i < transDistNumBin - 1; ++i) {
        real_type transMid = (i + 0.5) / transDistInvD;
        fprintf(f, "%g %g\n", transMid, globalTransDistr[i] * transNormFactor);
    }
    delete[] globalTransDistr;
    fclose(f);
    printf(" ==== Completed.\n");
}

void runSimulation() {
    auto start = std::chrono::high_resolution_clock::now();

    printf(" ==== Starts the simulation of %lu trajectory histories...\n", theNumHists);
    Simulate();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << time_span.count() << " seconds" << std::endl;
}

int main() {
    runSimulation();
//    int i;
//    int threadID = 0;
//#pragma omp parallel for private(i, threadID)
//    for(i = 0; i < 16; i++ )
//    {
//        threadID = omp_get_thread_num();
//#pragma omp critical
//        {
//            printf("Thread %d reporting\n", threadID);
//        }
//    }
//    return 0;

    return 0;
}

