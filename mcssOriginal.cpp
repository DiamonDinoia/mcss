#include <cstdio>
#include <cmath>
#include <random>
#include <chrono>
#include <iostream>

enum Material { WATER, AIR, BONE, TISSUE, GOLD};
static const double kMolierBc[]  = {  877.879, 1.02281,     1645.05,   888.813, 12481.2 }; // 1/mm
static const double kMolierXc2[] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072, 9.72643 }; // MeV^2/mm

static const double kPI          =  3.14159265358979323846; // Pi
static const double kMASS        =  0.510998910;            // electron mass [MeV]

double ComputeScrParam(Material mat, double ptot2) {
    return kMolierXc2[mat]/(4.0*ptot2*kMolierBc[mat]);
}

double ComputeMFP(Material mat, double beta2, double scrpar) {
    return beta2*(1.0+scrpar)/kMolierBc[mat];
}

double SampleCosTheta(double scrpar, double rn) {
    double cost = 1.0-2*scrpar*rn/(1.0-rn+scrpar);
    return std::max(-1.0, std::min(1.0, cost));
}

struct Track {
    double fPosition[3];   // rx, ry, rz
    double fDirection[3];  // dx, dy, dz normalised to 1
    double fTrackLength;   // cummulative track length
    //
    Track() {
        Reset();
    }
    //
    void Reset() {
        fPosition[0]  = 0.0;
        fPosition[1]  = 0.0;
        fPosition[2]  = 0.0;
        //
        fDirection[0] = 0.0;
        fDirection[1] = 0.0;
        fDirection[2] = 1.0;
        //
        fTrackLength  = 0.0;
    }
};

void RotateToLabFrame(double &u, double &v, double &w, double u1, double u2, double u3) {
    double up = u1*u1 + u2*u2;
    if (up>0.) {
        up = std::sqrt(up);
        double px = u;
        double py = v;
        double pz = w;
        u = (u1*u3*px - u2*py)/up + u1*pz;
        v = (u2*u3*px + u1*py)/up + u2*pz;
        w =    -up*px +             u3*pz;
    } else if (u3<0.) {       // phi=0  teta=pi
        u = -u;
        w = -w;
    }
}

void Simulate(std::size_t theNumHists, double theMFP, double theScrPar, double theLimit) {
    // Create histogram (i.e. array) for longitudinal distribution of final position
    const int longiDistNumBin   = 201;
    const double longiDistInvD  = (longiDistNumBin-1.0)/2.0;
    std::size_t* theLongiDistr  = new std::size_t[longiDistNumBin]; // on [-1,1]
    // same for the transverse distribution
    const int transDistNumBin   = 101;
    const double transDistInvD  = (transDistNumBin-1.0)/1.0;
    std::size_t* theTransDistr  = new std::size_t[transDistNumBin]; // on [0,1]

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0);

    Track aTrack;
    printf(" ==== Starts the simulation of %lu trajectory histories...\n", theNumHists);
    for (std::size_t ih = 0; ih < theNumHists; ++ih) {
        aTrack.Reset();
        double trackLength = 0.0;
        bool          stop = false;
        do {
            double stepLength = -theMFP*std::log(dis(gen));
            trackLength += stepLength;
            if (trackLength>theLimit) {
                stepLength = theLimit-aTrack.fTrackLength;
                stop = true;
            }

            aTrack.fPosition[0] += aTrack.fDirection[0]*stepLength;
            aTrack.fPosition[1] += aTrack.fDirection[1]*stepLength;
            aTrack.fPosition[2] += aTrack.fDirection[2]*stepLength;
            aTrack.fTrackLength += stepLength;

            if (!stop) {
                const double cost = SampleCosTheta(theScrPar, dis(gen));
                const double dum0 = 1.0-cost;
                const double sint = std::sqrt(dum0*(2.0-dum0));
                const double phi  = 2.0*kPI*dis(gen);
                double u1 = sint*std::cos(phi);
                double u2 = sint*std::sin(phi);
                double u3 = cost;

                RotateToLabFrame(u1, u2, u3, aTrack.fDirection[0], aTrack.fDirection[1], aTrack.fDirection[2]);
                aTrack.fDirection[0] = u1;
                aTrack.fDirection[1] = u2;
                aTrack.fDirection[2] = u3;
            }
        } while(!stop);

        const double longi = aTrack.fPosition[2]/aTrack.fTrackLength;
        std::size_t  lIndx = (std::size_t) ((longi+1.0)*longiDistInvD);
        ++theLongiDistr[lIndx];

        const double trans = std::sqrt(aTrack.fPosition[0]*aTrack.fPosition[0] + aTrack.fPosition[1]*aTrack.fPosition[1])/aTrack.fTrackLength;
        std::size_t  tIndx = (std::size_t) (trans*transDistInvD);
        ++theTransDistr[tIndx];
    }
    printf(" ==== Completed the simulation of %lu trajectory histories.\n", theNumHists);
    printf(" ==== Writing results to files...\n");
    double longiNormFactor = 1.0/theNumHists*longiDistInvD;
    FILE* f = fopen("Original_Res_Longi.dat","w");
    for (int i=0; i<longiDistNumBin-1; ++i) {
        double longiMid = ((i+0.5)/longiDistInvD - 1.0);
        fprintf(f, "%g\r\n", theLongiDistr[i]*longiNormFactor);
    }
    fclose(f);

    double transNormFactor = 1.0/theNumHists*transDistInvD;
    f = fopen("Original_Res_Trans.dat","w");
    for (int i=0; i<transDistNumBin-1; ++i) {
        double transMid = (i+0.5)/transDistInvD;
        fprintf(f, "%g\r\n", theTransDistr[i]*transNormFactor);
    }
    fclose(f);
    printf(" ==== Completed.\n");
    delete[] theLongiDistr;
    delete[] theTransDistr;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    Material    theMaterial =   GOLD;  // WATER, AIR, BONE, TISSUE or GOLD
    double      theEKin     =   0.128; // [MeV]
    double      theLimit    =    33.5; // limit of cummulative track lenght in units of MFP
    std::size_t theNumHists = 1000000; // #histories to simulate

    double   thePC2      = theEKin*(theEKin + 2.0*kMASS);
    double   theBeta2    = thePC2/(thePC2 + kMASS*kMASS);
    double   theScrPar   = ComputeScrParam(theMaterial, thePC2);
    double   theMFP      = ComputeMFP(theMaterial, theBeta2, theScrPar);
    theLimit *= theMFP;
    Simulate(theNumHists, theMFP, theScrPar, theLimit);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << time_span.count() << " seconds" << std::endl;
    return 0;
}