#include "Maxfiles.h"
#include "random_mt.h"

#include "../../../include/mcss_dfe.h"

namespace Dfe {
Histograms Simulate(Material material, int numHists) {
    int dataOut[302];

    double kMolierBc[5] = {877.879, 1.02281, 1645.05, 888.813, 12481.2};
    double kMolierXc2[5] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072, 9.72643};

    double materialMolierBc = kMolierBc[material];
    double materialMolierXc2 = kMolierXc2[material];

	max_file_t    *maxfile = MCSS_init();
	max_actions_t *actions = max_actions_init( maxfile, NULL );
	max_engine_t  *engine  = max_load( maxfile, "*" );

	max_set_ticks   ( actions, "processingKernel", numHists );
	max_set_uint64t ( actions, "processingKernel", "numHists", numHists);
	max_set_double  ( actions, "loopKernel", "molierBc", materialMolierBc );
	max_set_double  ( actions, "loopKernel", "molierXc2", materialMolierXc2 );
	max_queue_output( actions, "output", dataOut, 304 * sizeof(int) );
	random_mt_init(maxfile, actions, "rngKernel", "gen1", rand());
	random_mt_init(maxfile, actions, "rngKernel", "gen2", rand());
	random_mt_init(maxfile, actions, "rngKernel", "gen3", rand());
	std::cout << "Starting simulation" << std::endl;
	max_run ( engine, actions );
	max_actions_free( actions );
	max_unload( engine );

	std::vector<real_type> longiDistr(201);
	std::vector<real_type> transDistr(101);

    for (int i = 0; i < 201; i++) {
    	longiDistr[i] = dataOut[i] * 100.0 / numHists;
        std::cout << "longitudinal[" << i << "]: " << longiDistr[i] << std::endl;
    }

    for (int i = 0; i < 101; i++) {
    	transDistr[i] = dataOut[i + 201] * 100.0 / numHists;
    	std::cout << "transverse[" << i << "]: " << transDistr[i] << std::endl;
	}

    return {longiDistr, transDistr};
}
}
