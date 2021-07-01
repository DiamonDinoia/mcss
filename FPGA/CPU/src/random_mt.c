#include <stdio.h>
#include "random_mt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char name[512];
	unsigned long* data;
	size_t size;
} mapped_rom_contents;

static void* malloc_wrapper(size_t size) {
	void * pointer = malloc(size);
	if (pointer == NULL) {
		fprintf(stderr, "Was not able to allocate enough memory");
		exit(-1);
	}
	return pointer;
}

static unsigned long* get_seeds(unsigned long seed, int mt_size) {
	unsigned long* mt = (unsigned long *) malloc_wrapper(mt_size * sizeof(unsigned long));
	long UPPER_MASK = 0x80000000UL;
	long LOWER_MASK = 0x7fffffffUL;
	mt[0] = seed;
	// Original code from http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/MT2002/CODES/mt19937ar.c
	for (int i = 1; i < mt_size; i++) {
		mt[i] = (1812433253UL * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i) & 0xFFFFFFFFUL;
	}
	// The original paper does not initialize the array this way
	// But the original implementation (link above),
	// and the c++ standard library perform this extra step.
	for (int i = 0; i < mt_size; i++) {
		long x = (mt[i] & UPPER_MASK) + (mt[(i+1) % mt_size] & LOWER_MASK);
		long xa = x >> 1;
		if (x % 2 != 0) xa = xa ^ 0x9908B0DFUL;
		mt[i] = mt[(i+397)% mt_size] ^ xa;
	}
	return mt;
}

/**
 * Creates all seeds for the mapped ROMs
 * @param maxfile Pointer to the maxfile
 * @param rom_data The addressed point is used to store the pointer to the Array with all data about the different ROMs (has to be freed by caller).
 * @param kernel_name Name of the kernel containing the random number generator
 * @param name Name of the random number generator. If gaussianRng gets used add "_mt" to the name
 * @param seed Seed for the random number generator
 *
 * @return Number of generated ROMs (size of the array)
 */
static int get_mapped_roms_mersenne_twister(max_file_t* maxfile, mapped_rom_contents** rom_data, const char* kernel_name, const char* name, const long seed) {
	int mt_size = max_get_constant_uint64t(maxfile, "MersenneTwister_n");
	int mt_seed_offset = max_get_constant_uint64t(maxfile, "MersenneTwister_seedOffset");

	int string_length = snprintf(NULL, 0, "%s%s", kernel_name, name);
	char* full_name = (char *) malloc_wrapper((string_length + 1) * sizeof(char));
	snprintf(full_name, string_length + 1, "%s%s", kernel_name, name);

	int count = max_get_constant_uint64t(maxfile, full_name);

	*rom_data = (mapped_rom_contents*) malloc_wrapper(count * sizeof(mapped_rom_contents));

	for (int i = 0; i < count; i++) {
		snprintf((*rom_data)[i].name, sizeof((*rom_data)[i].name), "%s_seeds%d", full_name, i);
		(*rom_data)[i].data = get_seeds(seed + i * mt_seed_offset, mt_size);
		(*rom_data)[i].size = mt_size;
	}

	free(full_name);

	return count;
}

void random_mt_init(max_file_t* maxfile, max_actions_t* actions, const char* kernel_name, const char* name, const long seed) {
	mapped_rom_contents* rom_data = NULL;
	int count = get_mapped_roms_mersenne_twister(maxfile, &rom_data, kernel_name, name, seed);

	for (int i = 0; i < count; i++) {
		max_set_mem_range_uint64t(actions, kernel_name, rom_data[i].name, 0, rom_data[i].size, rom_data[i].data);
		free(rom_data[i].data);
	}
	free(rom_data);
}

#ifdef __cplusplus
}
#endif
