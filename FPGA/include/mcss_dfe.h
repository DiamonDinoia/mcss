// M. Novak, 9 October 2020 (NOTE: energy is in [MeV] and length in [mm].)
// -----------------------------------------------------------------------
// Modified by D. Chen 2021
// Modified by M. Barbone 2022
#ifndef DFE_MCSS_H
#define DFE_MCSS_H

#include <vector>

#include "common.h"

namespace Dfe {
Histograms Simulate(Material material = GOLD, int numHists = 1000000);
}

#endif