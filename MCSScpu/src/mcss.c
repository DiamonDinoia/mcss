#include <stdio.h>
#include <stdint.h>

#include "Maxfiles.h"
#include "random_mt.h"

// Input and output array size
#define SIZE 302

int main(void) {
    int dataOut[SIZE];
    double longitudinal[201];
    double transverse[101];
    long seed = 42;

    int numHists = 10000;
    int material = 4;

	max_file_t    *maxfile = MCSS_init();
	max_actions_t *actions = max_actions_init( maxfile, NULL );
	max_engine_t  *engine  = max_load( maxfile, "*" );

	max_set_ticks   ( actions, "processingKernel", numHists );
	max_set_uint64t ( actions, "processingKernel", "numHists", numHists);
	max_queue_output( actions, "output", dataOut, 304 * sizeof(int) );
	random_mt_init(maxfile, actions, "rngKernel", "gen1", seed);
	random_mt_init(maxfile, actions, "rngKernel", "gen2", seed);
	random_mt_init(maxfile, actions, "rngKernel", "gen3", seed);
	printf("Starting simulation\n");
	max_run ( engine, actions );

	max_actions_free( actions );
	max_unload( engine );

	printf("Seed: %ld\n", seed);

	for (int i = 0; i < 201; i++) {
		longitudinal[i] = dataOut[i] * 100.0 / numHists;
	}

	for (int i = 0; i < 101; i++) {
		transverse[i] = dataOut[i + 201] * 100.0 / numHists;
	}

    for (int i = 0; i < 201; i++) {
        printf("longitudinal[%i]: %.10f\n", i, longitudinal[i]);
    }

    for (int i = 0; i < 101; i++) {
		printf("transverse[%i]: %.10f\n", i, transverse[i]);
	}

    for (int i = 0; i < 302; i++) {
		printf("dataOut[%i]: %i\n", i, dataOut[i]);
	}

    return 0;
}
