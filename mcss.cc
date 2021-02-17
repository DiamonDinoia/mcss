
// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------


#include <cstdio>
#include <cmath>
#include <random>

#include <ctime>
#include <iostream>

//
// ============================================================================
// Definitions of some constants:
//

// G4_WATER, G4_AIR, G4_TISSUE_SOFT_ICRP, G4_TISSUE_SOFT_ICRP and G4_Au                
enum Material { WATER, AIR, BONE, TISSUE, GOLD};
static const double kMolierBc[]  = {  877.879, 1.02281,     1645.05,   888.813, 12481.2 }; // 1/mm
static const double kMolierXc2[] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072, 9.72643 }; // MeV^2/mm

static const double kPI          =  3.14159265358979323846; // Pi 
static const double kMASS        =  0.510998910;            // electron mass [MeV]


//
// ============================================================================
// Auxiliary functions to compute the screening parameter, the mean free path,
// sample the angular deflections and rotate the direction, computed in the
// scattering frame, to the lab frame. A simple track data structure is also 
// defined to keep track of position and direction information.
 
//
// Computes the A `screening parameter` value for the screened Rutherford DCS 
// in the given `mat` material at the given `ptot2` e- total momentum square. 
// (Eq. (52) in the DOC)
double ComputeScrParam(Material mat, double ptot2) {
  return kMolierXc2[mat] / (4.0 * ptot2 * kMolierBc[mat]);
}

//
// Computes the elastic mean free path according to the screened Rutherford DCS 
// in the given `mat` material at the given `beta2` beta square. The 
// screening parameter is assumed to be already known `scrpar`. 
// (Eq. (50) in DOC)
double ComputeMFP(Material mat, double beta2, double scrpar) {
  return beta2 * (1.0 + scrpar) / kMolierBc[mat];
}

//
// Provides samples of angular deflection, i.e. `cos(\theta)` in single scattering
// according to the screened Rutherford DCS characterised by the `scrpar` screening
// parameter. The additional input `rn` is a uniformly random value in [0,1).
// (Eq. (26) in DOC)
double SampleCosTheta(double scrpar, double rn) {
  double cost = 1.0 - 2 * scrpar * rn / (1.0 - rn + scrpar);
  // could be omitted just a bad habit
  return std::max(-1.0, std::min(1.0, cost));
}

//
// A simple track data structure to keep positon, direction and accumulated track 
// length information.
struct Track {
  double fPosition[3]{};   // rx, ry, rz
  double fDirection[3]{};  // dx, dy, dz normalised to 1
  double fTrackLength{};   // cumulative track length

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

//
// Roate the direction [u,v,w] given in the scattering frame to the lab frame.
// Details: scattering is described relative to the [0,0,1] direction (i.e. scattering 
// frame). Therefore, after the new direction is computed relative to this [0,0,1]
// original direction, the real original direction [u1,u2,u3] in the lab frame 
// needs to be accounted and the final new direction, i.e. in the lab frame is 
// computed.
void RotateToLabFrame(double &u, double &v, double &w, double u1, double u2, double u3) {
  double up = u1 * u1 + u2 * u2;
  if (up > 0.) {
    up = std::sqrt(up);
    double px = u;
    double py = v;
    double pz = w;
    u = (u1 * u3 * px - u2 * py) / up + u1 * pz;
    v = (u2 * u3 * px + u1 * py) / up + u2 * pz;
    w = -up * px + u3 * pz;
  } else if (u3 < 0.) {       // phi=0  teta=pi
    u = -u;
    w = -w;
  }
}

//
// ============================================================================
// The main simulation happens here. This function contains the tracking loop.
void Simulate(std::size_t theNumHists, double theMFP, double theScrPar, double theLimit) {
  // Create histogram (i.e. array) for longitudinal distribution of final position
  const int longiDistNumBin   = 201;
  const double longiDistInvD  = (longiDistNumBin - 1.0) / 2.0;
  std::size_t* theLongiDistr  = new std::size_t[longiDistNumBin]; // on [-1,1]
  // same for the transverse distribution
  const int transDistNumBin   = 101;
  const double transDistInvD  = (transDistNumBin - 1.0) / 1.0;
  std::size_t* theTransDistr  = new std::size_t[transDistNumBin]; // on [0,1]
  //
  // Create a c++11 RNG for getting uniformly random values in [0,1)
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1.0);
  //
  // === Preparation and start of the simulation loop to generate `theNumHists` histories
  //
  // create a Track 
  Track aTrack;
  printf(" ==== Starts the simulation of %u trajectory histories...\n", theNumHists);
  for (std::size_t ih = 0; ih < theNumHists; ++ih) {
    // init the history
    aTrack.Reset();
    double trackLength = 0.0;
    double        xDir = 0.0;
    double        yDir = 0.0;
    double        zDir = 1.0;
    bool          stop = false; 
    do {
      // how far we go in the current direction till the next elastic interaction:
      // - samples from exponential distribution p(x) = Sig exp(-Sig x) where 
      // Sig=1/mfp is the macroscopic cross section and x is the step length.
      double stepLength = -theMFP*std::log(dis(gen));
      // update cumulative track length
      trackLength += stepLength;
      // stop tracking if the track length limit is reached (the track will be 
      // propagated its final position)
      if (trackLength>theLimit) {
        stepLength = theLimit-aTrack.fTrackLength;
        stop = true; 
      }
      // update track position,
      aTrack.fPosition[0] += aTrack.fDirection[0] * stepLength;
      aTrack.fPosition[1] += aTrack.fDirection[1] * stepLength;
      aTrack.fPosition[2] += aTrack.fDirection[2] * stepLength;
      // update cumulative track length
      aTrack.fTrackLength += stepLength;
      // keep tracking: sample angular deflection and update propagation direction 
      if (!stop) {
        // sample cos(\theta)
        const double cost = SampleCosTheta(theScrPar, dis(gen));
        const double dum0 = 1.0 - cost;
        const double sint = std::sqrt(dum0 * (2.0 - dum0));
        // sample \phi: uniform in [0,2Pi] <== spherical symmetry of the scattering potential
        const double phi  = 2.0 * kPI * dis(gen);
        // compute new direction (relative to 0,0,1 i.e. in the scattering frame)
        double u1 = sint * std::cos(phi);
        double u2 = sint * std::sin(phi);
        double u3 = cost;
        // rotate new direction from the scattering to the lab frame
        RotateToLabFrame(u1, u2, u3, aTrack.fDirection[0], aTrack.fDirection[1], aTrack.fDirection[2]);
        // update track direction
        aTrack.fDirection[0] = u1;
        aTrack.fDirection[1] = u2;
        aTrack.fDirection[2] = u3;
      }
    } while(!stop);
    //
    // Record final track position in the longitudinal and transverse distributions
    // ==> z/track-length ==> [-1,1]
    const double longi = aTrack.fPosition[2] / aTrack.fTrackLength;
    std::size_t  lIndx = (std::size_t) ((longi + 1.0) * longiDistInvD);
    ++theLongiDistr[lIndx];
    // ==> r_{xy}/track-length ==> [0,1] 
    const double trans = std::sqrt(aTrack.fPosition[0] * aTrack.fPosition[0] + aTrack.fPosition[1] * aTrack.fPosition[1]) / aTrack.fTrackLength;
    std::size_t  tIndx = (std::size_t) (trans * transDistInvD);
    ++theTransDistr[tIndx];
  }
  printf(" ==== Completed the simulation of %u trajectory histories.\n", theNumHists);
  printf(" ==== Writing results to files...\n");
  // 
  // == Write distributions into file with normalisation (to integral = 1.0) 
  double longiNormFactor = 1.0 / theNumHists * longiDistInvD;
  FILE* f = fopen("Res_Longi.dat", "w");
  for (int i = 0; i < longiDistNumBin - 1; ++i) {
    double longiMid = ((i + 0.5) / longiDistInvD - 1.0);
    fprintf(f, "%g %g\n", longiMid, theLongiDistr[i] * longiNormFactor);
  }
  fclose(f);
  //
  double transNormFactor = 1.0 / theNumHists * transDistInvD;
  f = fopen("Res_Trans.dat", "w");
  for (int i = 0; i < transDistNumBin - 1; ++i) {
    double transMid = (i + 0.5) / transDistInvD;
    fprintf(f, "%g %g\n", transMid, theTransDistr[i]*transNormFactor);
  }
  fclose(f);
  printf(" ==== Completed.\n");
  //
  // == Clean dynamically allocate auxiliary memory
  delete[] theLongiDistr;
  delete[] theTransDistr;
}


int main() {
  std::clock_t start = std::clock();

  // Define settings
  Material    theMaterial =   GOLD;  // WATER, AIR, BONE, TISSUE or GOLD
  double      theEKin     =   0.128; // [MeV]
  double      theLimit    =    33.5; // limit of cummulative track lenght in units of MFP
  std::size_t theNumHists = 1000000; // #histories to simulate
  
  
  // Compute paramters according to the above settings:
  // - total momentum square [MeV]^2
  double   thePC2      = theEKin * (theEKin + 2.0 * kMASS);
  // - beta2
  double   theBeta2    = thePC2 / (thePC2 + kMASS * kMASS);
  // - screening parameter
  double   theScrPar   = ComputeScrParam(theMaterial, thePC2);
  // - elastic mfp [mm]
  double   theMFP      = ComputeMFP(theMaterial, theBeta2, theScrPar);
  // get the track length limit in [mm]
  theLimit *= theMFP;
    
  // Compute total-track lenght / firsr-transport-mfp just for checking
//  double g1      = 2.0*theScrPar*((1.0+theScrPar)*std::log(1.0/theScrPar+1.0)-1.0);
//  double lambda1 = theMFP/g1;  // first transport mean free path
//  printf("theLimit/lambda1 = %g\n", theLimit/lambda1);
  
  //
  // The simulation with the tracking loop inside:
  //  `theNumHists` trajectory histories will be generated. Each trajectory starts 
  //  at the [0,0,0] position and the track points to the [0,0,1] direction. 
  //  The only interaction of the e- is elastic scattering and each trajectory 
  //  is followed untill the cumulative track length reaches `theLimit`.
  //  Therefore, each trajectory will have exactly `theLimit` length but the 
  //  final position will be different. This final position is used to generate 
  //  the longitudinal (along the <z> axes) and the transverse (perpendicualr 
  //  to the <z> axes i.e. along the <x><y> plane) position distributions. 
  //
  // The default settings reproduce the distributions shown in page #25 and #26 
  // in my very old presentation (see below). NOTE: there is a typo in the 
  // presentation below: 128 [MeV] should be 128 [keV] which is correct here above.
  // https://indico.fnal.gov/event/9717/contributions/115128/attachments/74561/89448/MihalyNovakGeant4CollaborationMeetingNewEMModels.pdf
  Simulate(theNumHists, theMFP, theScrPar, theLimit);


  double duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
  std::cout << duration << std::endl;
  return 0;
}

