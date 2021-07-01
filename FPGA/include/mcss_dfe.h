#ifndef DFE_MCSS_H
#define DFE_MCSS_H

#include <vector>

#include "../../include/common.h"

namespace Dfe {
struct Histograms {
	std::vector<real_type> longiHist;
	std::vector<real_type> transHist;
};

Histograms Simulate(Material material = GOLD, int numHists = 1000000);
}

#endif
