#include "MCSS_DFE.h"

#include <random_mt.h>

#include <chrono>
#include <cstring>

#include "common.h"
#include "mcss_dfe.h"

#define PARALLELISM 15

namespace Dfe {
Histograms Simulate(Material material, int numHists) {
  real_type normalisationFactor = 100.0 / numHists;

  numHists /= PARALLELISM;
  int dataOut[PARALLELISM][304];

  double kMolierBc[5]  = {877.879, 1.02281, 1645.05, 888.813, 12481.2};
  double kMolierXc2[5] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072, 9.72643};

  double materialMolierBc  = kMolierBc[material];
  double materialMolierXc2 = kMolierXc2[material];

  std::chrono::high_resolution_clock::time_point start =
	  std::chrono::high_resolution_clock::now();

  max_file_t *maxfile	 = MCSS_DFE_init();
  max_actions_t *actions = max_actions_init(maxfile, NULL);
  max_engine_t *engine	 = max_load(maxfile, "*");

  for (int i = 0; i < PARALLELISM; i++) {
	std::string rng		   = "rngKernel" + std::to_string(i);
	std::string loop	   = "loopKernel" + std::to_string(i);
	std::string processing = "processingKernel" + std::to_string(i);
	std::string out		   = "output" + std::to_string(i);
	char rngKernel[32];
	char loopKernel[32];
	char processingKernel[32];
	char output[32];
	strcpy(rngKernel, rng.c_str());
	strcpy(loopKernel, loop.c_str());
	strcpy(processingKernel, processing.c_str());
	strcpy(output, out.c_str());

	max_set_ticks(actions, processingKernel, numHists);
	max_set_uint64t(actions, processingKernel, "numHists", numHists);
	max_set_double(actions, loopKernel, "molierBc", materialMolierBc);
	max_set_double(actions, loopKernel, "molierXc2", materialMolierXc2);
	max_queue_output(actions, output, dataOut[i], 304 * sizeof(int));
	random_mt_init(maxfile, actions, rngKernel, "gen1", rand());
	random_mt_init(maxfile, actions, rngKernel, "gen2", rand());
	random_mt_init(maxfile, actions, rngKernel, "gen3", rand());
  }
  std::cout << "Starting simulation" << std::endl;
  max_run(engine, actions);
  max_actions_free(actions);
  max_unload(engine);

  std::vector<real_type> longiDistr(201, 0);
  std::vector<real_type> transDistr(101, 0);

  for (int i = 0; i < PARALLELISM; i++) {
	for (int j = 0; j < 201; j++) {
	  longiDistr[j] += dataOut[i][j] * normalisationFactor;
	}

	for (int j = 0; j < 101; j++) {
	  transDistr[j] += dataOut[i][j + 201] * normalisationFactor;
	}
  }

  std::chrono::high_resolution_clock::time_point end =
	  std::chrono::high_resolution_clock::now();

  for (int j = 0; j < 201; j++) {
	std::cout << "longitudinal[" << j << "]: " << longiDistr[j] << std::endl;
  }

  for (int j = 0; j < 101; j++) {
	std::cout << "transverse[" << j << "]: " << transDistr[j] << std::endl;
  }

  std::chrono::duration<double> window =
	  std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
  std::cout << "Time taken: " << window.count() << " seconds" << std::endl;

  return {longiDistr, transDistr};
}
}  // namespace Dfe
