#include "Maxfiles.h"
#include "random_mt.h"

#include "../../../include/mcss_dfe.h"

// Input and output array size
#define SIZE 302

namespace Dfe {

//std::vector<std::vector<real_type>> initialiseHistogram(int numThreads,
//                                                        int numBins) {
//    std::vector<std::vector<real_type>> histogram;
//    for (int i = 0; i < numThreads; i++) {
//        std::vector<real_type> sub_vector(numBins, 0.0);
//        histogram.push_back(sub_vector);
//    }
//    return histogram;
//}

Histograms Simulate(Material material, int numHists) {
    int dataOut[SIZE];
//    double longitudinal[201];
//    double transverse[101];
//    long seed = 42;

//    int numHists = 10000;
//    int material = 4;

	max_file_t    *maxfile = MCSS_init();
	max_actions_t *actions = max_actions_init( maxfile, NULL );
	max_engine_t  *engine  = max_load( maxfile, "*" );

	max_set_ticks   ( actions, "processingKernel", numHists );
	max_set_uint64t ( actions, "processingKernel", "numHists", numHists);
	max_queue_output( actions, "output", dataOut, 304 * sizeof(int) );
	random_mt_init(maxfile, actions, "rngKernel", "gen1", rand());
	random_mt_init(maxfile, actions, "rngKernel", "gen2", rand());
	random_mt_init(maxfile, actions, "rngKernel", "gen3", rand());
//	random_mt_init(maxfile, actions, "rngKernel", "gen", seed);
	std::cout << "Starting simulation" << std::endl;
	max_run ( engine, actions );
	max_actions_free( actions );
	max_unload( engine );

	std::vector<real_type> longiDistr(201);
	std::vector<real_type> transDistr(101);


//	for (int i = 0; i < 201; i++) {
//		longitudinal[i] = dataOut[i] * 100.0 / numHists;
//	}
//
//	for (int i = 0; i < 101; i++) {
//		transverse[i] = dataOut[i + 201] * 100.0 / numHists;
//	}

    for (int i = 0; i < 201; i++) {
    	longiDistr[i] = dataOut[i] * 100.0 / numHists;
        std::cout << "longitudinal[" << i << "]: " << longiDistr[i] << std::endl;
    }

    for (int i = 0; i < 101; i++) {
    	transDistr[i] = dataOut[i + 201] * 100.0 / numHists;
    	std::cout << "transverse[" << i << "]: " << transDistr[i] << std::endl;
	}

//    for (int i = 0; i < 302; i++) {
//		printf("dataOut[%i]: %i\n", i, dataOut[i]);
//	}

    return {longiDistr, transDistr};
}
}

//int main(void) {
//	Dfe::Simulate(GOLD, 100000);
//	return 0;
//}
