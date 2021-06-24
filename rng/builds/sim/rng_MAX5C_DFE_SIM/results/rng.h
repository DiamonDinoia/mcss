/**\file */
#ifndef SLIC_DECLARATIONS_rng_H
#define SLIC_DECLARATIONS_rng_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define rng_MersenneTwister_seedOffset (8256754)
#define rng_rngKernelgen (3)
#define rng_PCIE_ALIGNMENT (16)
#define rng_MersenneTwister_n (624)


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/




/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] ticks_processingKernel The number of ticks for which kernel "processingKernel" will run.
 * \param [in] inscalar_processingKernel_numHists Input scalar parameter "processingKernel.numHists".
 * \param [out] outstream_output Stream "output".
 * \param [in] outstream_size_output The size of the stream outstream_output in bytes.
 * \param [in] inmem_rngKernel_rngKernelgen_seeds0 Mapped ROM inmem_rngKernel_rngKernelgen_seeds0, should be of size (624 * sizeof(uint64_t)).
 * \param [in] inmem_rngKernel_rngKernelgen_seeds1 Mapped ROM inmem_rngKernel_rngKernelgen_seeds1, should be of size (624 * sizeof(uint64_t)).
 * \param [in] inmem_rngKernel_rngKernelgen_seeds2 Mapped ROM inmem_rngKernel_rngKernelgen_seeds2, should be of size (624 * sizeof(uint64_t)).
 */
void rng(
	uint64_t ticks_processingKernel,
	uint64_t inscalar_processingKernel_numHists,
	void *outstream_output,
	size_t outstream_size_output,
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds0,
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds1,
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds2);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] ticks_processingKernel The number of ticks for which kernel "processingKernel" will run.
 * \param [in] inscalar_processingKernel_numHists Input scalar parameter "processingKernel.numHists".
 * \param [out] outstream_output Stream "output".
 * \param [in] outstream_size_output The size of the stream outstream_output in bytes.
 * \param [in] inmem_rngKernel_rngKernelgen_seeds0 Mapped ROM inmem_rngKernel_rngKernelgen_seeds0, should be of size (624 * sizeof(uint64_t)).
 * \param [in] inmem_rngKernel_rngKernelgen_seeds1 Mapped ROM inmem_rngKernel_rngKernelgen_seeds1, should be of size (624 * sizeof(uint64_t)).
 * \param [in] inmem_rngKernel_rngKernelgen_seeds2 Mapped ROM inmem_rngKernel_rngKernelgen_seeds2, should be of size (624 * sizeof(uint64_t)).
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *rng_nonblock(
	uint64_t ticks_processingKernel,
	uint64_t inscalar_processingKernel_numHists,
	void *outstream_output,
	size_t outstream_size_output,
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds0,
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds1,
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds2);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_processingKernel; /**<  [in] The number of ticks for which kernel "processingKernel" will run. */
	uint64_t inscalar_processingKernel_numHists; /**<  [in] Input scalar parameter "processingKernel.numHists". */
	void *outstream_output; /**<  [out] Stream "output". */
	size_t outstream_size_output; /**<  [in] The size of the stream outstream_output in bytes. */
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds0; /**<  [in] Mapped ROM inmem_rngKernel_rngKernelgen_seeds0, should be of size (624 * sizeof(uint64_t)). */
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds1; /**<  [in] Mapped ROM inmem_rngKernel_rngKernelgen_seeds1, should be of size (624 * sizeof(uint64_t)). */
	const uint64_t *inmem_rngKernel_rngKernelgen_seeds2; /**<  [in] Mapped ROM inmem_rngKernel_rngKernelgen_seeds2, should be of size (624 * sizeof(uint64_t)). */
} rng_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void rng_run(
	max_engine_t *engine,
	rng_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *rng_run_nonblock(
	max_engine_t *engine,
	rng_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void rng_run_group(max_group_t *group, rng_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *rng_run_group_nonblock(max_group_t *group, rng_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void rng_run_array(max_engarray_t *engarray, rng_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *rng_run_array_nonblock(max_engarray_t *engarray, rng_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* rng_convert(max_file_t *maxfile, rng_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* rng_init(void);

/* Error handling functions */
int rng_has_errors(void);
const char* rng_get_errors(void);
void rng_clear_errors(void);
/* Free statically allocated maxfile data */
void rng_free(void);
/* returns: -1 = error running command; 0 = no error reported */
int rng_simulator_start(void);
/* returns: -1 = error running command; 0 = no error reported */
int rng_simulator_stop(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_rng_H */

