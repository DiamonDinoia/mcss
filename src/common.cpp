#include "../include/common.h"

// Default values
int numHists = 1000000;
Material theMaterial = GOLD;

real_type computeScrParam(const Material &mat, const real_type ptot2) {
    return kMolierXc2[mat] / (4.0 * ptot2 * kMolierBc[mat]);
}

real_type computeMFP(const Material &mat, const real_type beta2,
                     const real_type scrpar) {
    return beta2 * (1.0 + scrpar) / kMolierBc[mat];
}

real_type sampleCosTheta(const real_type scrpar, const real_type rn) {
    real_type cost = 1.0 - 2 * scrpar * rn / (1.0 - rn + scrpar);
    return std::max((real_type)-1.0, std::min((real_type)1.0, cost));
}

void rotateToLabFrame(real_type &u, real_type &v, real_type &w,
                      const real_type &u1, const real_type &u2,
                      const real_type &u3) {
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