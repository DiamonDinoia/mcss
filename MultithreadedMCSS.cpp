#include "MultithreadedMCSS.h"

real_type ComputeScrParam(const Material &mat, const real_type ptot2) {
    return kMolierXc2[mat] / (4.0 * ptot2 * kMolierBc[mat]);
}

real_type ComputeMFP(const Material &mat, const real_type beta2,
                     const real_type scrpar) {
    return beta2 * (1.0 + scrpar) / kMolierBc[mat];
}

real_type SampleCosTheta(const real_type scrpar, const real_type rn) {
    real_type cost = 1.0 - 2 * scrpar * rn / (1.0 - rn + scrpar);
    return std::max((real_type)-1.0, std::min((real_type)1.0, cost));
}

void RotateToLabFrame(real_type &u, real_type &v, real_type &w, real_type u1,
                      real_type u2, real_type u3) {
    real_type up = u1 * u1 + u2 * u2;
    if (up > 0.) {
        up = std::sqrt(up);
        real_type px = u;
        real_type py = v;
        real_type pz = w;
        u = (u1 * u3 * px - u2 * py) / up + u1 * pz;
        v = (u2 * u3 * px + u1 * py) / up + u2 * pz;
        w = -up * px + u3 * pz;
    } else if (u3 < 0.) {
        u = -u;
        w = -w;
    }
}

void addLocalDistrToGlobal(int size, std::vector<real_type> &targetDistr,
                           std::vector<real_type> &sourceDistr) {
    for (int i = 0; i < size - 1; i++) {
        targetDistr[i] += sourceDistr[i];
    }
}

void Simulate() {
    std::vector<real_type> globalLongiDistr(longiDistNumBin);
    std::vector<real_type> globalTransDistr(transDistNumBin);

#pragma omp parallel for
    for (int i = 0; i < theNumHists; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1.0);

        std::vector<real_type> theLongiDistr(longiDistNumBin);
        std::vector<real_type> theTransDistr(transDistNumBin);

        Track aTrack;
        aTrack.Reset();
        real_type trackLength = 0.0;
        bool stop = false;
        while (!stop) {
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
        }

        const real_type longi = aTrack.fPosition[2] / aTrack.fTrackLength;
        std::size_t lIndx = (std::size_t)((longi + 1.0) * longiDistInvD);
        ++theLongiDistr[lIndx];

        const real_type trans =
            std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] +
                      aTrack.fPosition[1] * aTrack.fPosition[1]) /
            aTrack.fTrackLength;
        std::size_t tIndx = (std::size_t)(trans * transDistInvD);
        ++theTransDistr[tIndx];

#pragma omp critical
        addLocalDistrToGlobal(longiDistNumBin, globalLongiDistr, theLongiDistr);
#pragma omp critical
        addLocalDistrToGlobal(transDistNumBin, globalTransDistr, theTransDistr);
    }

    printf(" ==== Completed the simulation of %lu trajectory histories.\n",
           theNumHists);
    printf(" ==== Writing results to files...\n");

    real_type longiNormFactor = 1.0 / theNumHists * longiDistInvD;
    std::ofstream f;
    f.open("Res_Longi.dat");
    if (f.is_open())  {
        for (int i = 0; i < longiDistNumBin - 1; i++) {
            real_type longiMid = ((i + 0.5) / longiDistInvD - 1.0);
            f << globalLongiDistr[i] * longiNormFactor << std::endl;
        }
    }
    f.close();

    real_type transNormFactor = 1.0 / theNumHists * transDistInvD;
    f.open("Res_Trans.dat");
    if (f.is_open()) {
        for (int i = 0; i < transDistNumBin - 1; i++) {
            real_type transMid = (i + 0.5) / transDistInvD;
            f << globalTransDistr[i] * transNormFactor << std::endl;
        }
    }
    f.close();
    printf(" ==== Completed.\n");
}

void runSimulation() {
    auto start = std::chrono::high_resolution_clock::now();

    printf(" ==== Starts the simulation of %lu trajectory histories...\n",
           theNumHists);
    Simulate();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<real_type> time_span =
        std::chrono::duration_cast<std::chrono::duration<real_type>>(end -
                                                                     start);
    std::cout << time_span.count() << " seconds" << std::endl;
}