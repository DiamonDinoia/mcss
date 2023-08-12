// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by D. Chen 2020
// Modified by M. Barbone 2020
#ifndef MCSS_ORIGINAL_H
#define MCSS_ORIGINAL_H

#include "common.h"

namespace Reference {
Histograms Simulate(Material material = GOLD, int numHists = 1000000);
}  // namespace Reference

#endif
