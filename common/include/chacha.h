/*
chacha-ref.c version 20080118
D. J. Bernstein
Public domain.
*/

#include <stdint.h>
#include <string.h>

static inline constexpr uint32_t ROTL32(const uint32_t x, int k) {
    return (x << k) | (x >> (32 - k));
}

typedef union {
    uint32_t u32[16];
    uint64_t u64[8];
} uint32_64_t;

typedef struct chacha8 {
    uint32_64_t state;
    uint32_64_t block;
} chacha8;


#define ROTATE(v, c) (ROTL32(v,c))
#define XOR(v, w) ((v) ^ (w))
#define PLUS(v, w) ((uint32_t)((v) + (w)))
#define PLUSONE(v) (PLUS((v),1))

#define QUARTERROUND(a, b, c, d) \
  x[a] = PLUS(x[a],x[b]); x[d] = ROTATE(XOR(x[d],x[a]),16); \
  x[c] = PLUS(x[c],x[d]); x[b] = ROTATE(XOR(x[b],x[c]),12); \
  x[a] = PLUS(x[a],x[b]); x[d] = ROTATE(XOR(x[d],x[a]), 8); \
  x[c] = PLUS(x[c],x[d]); x[b] = ROTATE(XOR(x[b],x[c]), 7);

constexpr static void chacha8_round(chacha8 *chacha8) {
    chacha8->block = chacha8->state;
    uint32_t *const x = chacha8->block.u32;
    for (int i = 0; i < 4; i++) {
        QUARTERROUND(0, 4, 8, 12)
        QUARTERROUND(1, 5, 9, 13)
        QUARTERROUND(2, 6, 10, 14)
        QUARTERROUND(3, 7, 11, 15)
        QUARTERROUND(0, 5, 10, 15)
        QUARTERROUND(1, 6, 11, 12)
        QUARTERROUND(2, 7, 8, 13)
        QUARTERROUND(3, 4, 9, 14)
    }
}

static constexpr void init(chacha8 *chacha8, uint64_t stream, uint64_t seed) {
    memset(chacha8, 0, sizeof *chacha8);
    chacha8->state.u64[1] = stream;
    chacha8->state.u64[2] = seed;
}

static constexpr uint64_t gen_uint64(chacha8 *chacha8) {
    const auto idx = chacha8->state.u64[0] & 7U;
    if (idx == 0) chacha8_round(chacha8);
    chacha8->state.u64[0]++;
    return chacha8->block.u64[idx];
}

class ChaCha {
public:
    inline constexpr ChaCha(uint64_t seed, uint64_t stream) {
        init(&m_rng, stream, seed);
    }

    inline constexpr std::uint64_t operator()() {
        return gen_uint64(&m_rng);
    }

private:
    chacha8 m_rng;

};