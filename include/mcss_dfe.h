#include <vector>

#include "common.h"

namespace Dfe {
struct Histograms {
	std::vector<real_type> longiHist;
	std::vector<real_type> transHist;
};

Histograms Simulate(Material material = GOLD, int numHists = 1000000);
}
