#include <stdlib.h>
#include <MaxSLiCInterface.h>

/**
 * Creates all seeds for the mapped ROMs
 * @param maxfile Pointer to the maxfile
 * @param actions Pointer to the actions to be executed on the DFE. The mapped ROMs will be set by this function
 * @param kernel_name Name of the kernel containing the random number generator
 * @param name Name of the random number generator. If gaussianRng gets used add "_mt" to the name
 * @param seed Seed for the random number generator
 *
 * @return Number of generated ROMs (size of the array)
 */

#ifdef __cplusplus
extern "C" {
#endif
void random_mt_init(max_file_t* maxfile, max_actions_t* actions, const char* kernel_name, const char* name, const long seed);
#ifdef __cplusplus
}
#endif
