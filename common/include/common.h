#ifndef COMMON_H
#define COMMON_H

#include <cmath>
#include <cstdint>
#include <vector>

#include "chacha.h"

#ifdef SINGLE
using real_type = float;
#else   // SINGLE
using real_type = double;
#endif  // SINGLE

namespace math {

template <typename T, typename V>
inline constexpr T min(T x, V y) noexcept {
    return x < y ? x : y;
}

template <typename T, typename V>
inline constexpr T max(T x, V y) noexcept {
    return x > y ? x : y;
}
};  // namespace math

enum Material { WATER, AIR, BONE, TISSUE, GOLD };

constexpr real_type kMolierBc[]  = {877.879, 1.02281, 1645.05, 888.813,
                                    12481.2};  // 1/mm

constexpr real_type kMolierXc2[] = {0.0661905, 7.88813e-05, 0.17879, 0.0647072,
                                    9.72643};  // MeV^2/mm

constexpr real_type kPI          = 3.14159265358979323846;  // Pi

constexpr real_type kMASS        = 0.510998910;  // electron mass [MeV]

constexpr real_type theEKin      = 0.128;  // [MeV]

constexpr real_type thePC2       = theEKin * (theEKin + 2.0 * kMASS);
constexpr real_type theBeta2     = thePC2 / (thePC2 + kMASS * kMASS);

constexpr int       longiDistNumBin = 201;
constexpr real_type longiDistInvD   = (longiDistNumBin - 1.0) / 2.0;

constexpr int       transDistNumBin = 101;
constexpr real_type transDistInvD   = (transDistNumBin - 1.0) / 1.0;

inline constexpr real_type computeScrParam(const Material  mat,
                                      const real_type ptot2) noexcept {
    return kMolierXc2[mat] / (4. * ptot2 * kMolierBc[mat]);
}

inline constexpr real_type computeMFP(const Material mat, const real_type beta2,
                                      const real_type scrpar) noexcept {
    return beta2 * (1.0 + scrpar) / kMolierBc[mat];
}

inline constexpr real_type sampleCosTheta(const real_type scrpar,
                                     const real_type rn) noexcept {
    const auto cost = 1.0 - 2.0 * scrpar * rn / (1.0 - rn + scrpar);
    return math::max(1.0, math::min(1.0, cost));
}

inline constexpr void rotateToLabFrame(real_type &u, real_type &v, real_type &w,
                                       const real_type &u1, const real_type &u2,
                                       const real_type &u3) noexcept {
    real_type up = u1 * u1 + u2 * u2;
    if (up > 0) {
        up                 = std::sqrt(up);
        const real_type px = u;
        const real_type py = v;
        const real_type pz = w;
        u                  = (u1 * u3 * px - u2 * py) / up + u1 * pz;
        v                  = (u2 * u3 * px + u1 * py) / up + u2 * pz;
        w                  = -up * px + u3 * pz;
    } else if (u3 < 0) {
        u = -u;
        w = -w;
    }
}

struct Track {
    real_type fPosition[3]{0};   // rx, ry, rz
    real_type fDirection[3]{0};  // dx, dy, dz normalised to 1
    real_type fTrackLength{0};   // cumulative track length

    inline consteval Track() noexcept { Reset(); };
    inline constexpr ~Track() noexcept = default;

    inline constexpr void Reset() {
        fPosition[0]  = 0.0;
        fPosition[1]  = 0.0;
        fPosition[2]  = 0.0;

        fDirection[0] = 0.0;
        fDirection[1] = 0.0;
        fDirection[2] = 1.0;

        fTrackLength  = 0.0;
    }
};

struct Histograms {
    std::vector<real_type> longiHist;
    std::vector<real_type> transHist;
    Histograms(const unsigned long longBins, const unsigned long transBins)
        : longiHist(longBins), transHist(transBins) {}

    Histograms(std::vector<real_type> longi_hist,
               std::vector<real_type> trans_hist)
        : longiHist(std::move(longi_hist)), transHist(std::move(trans_hist)) {}
    Histograms()          = default;
    virtual ~Histograms() = default;
};

class CounterRNG {
   public:
    inline constexpr explicit CounterRNG(const std::uint64_t seed,
                                         const std::uint64_t stream = 0)
        : counter(seed + stream) {}
    inline constexpr double Uniform() {
        return static_cast<double>((counter++) >> 11) * 0x1.0p-53;
    }
    inline constexpr auto                 operator()() { return counter++; }
    static inline constexpr std::uint64_t min() noexcept {
        return std::numeric_limits<std::uint64_t>::min();
    }
    static inline constexpr std::uint64_t max() noexcept {
        return std::numeric_limits<std::uint64_t>::max();
    }

   private:
    std::uint64_t counter;
};

class ChaCha8 {
   public:
    inline constexpr explicit ChaCha8(const std::uint64_t seed,
                                         const std::uint64_t stream = 0)
        : chacha(seed,stream) {}
    inline constexpr double Uniform() {
        return static_cast<double>(chacha() >> 11) * 0x1.0p-53;
    }
    inline constexpr auto                 operator()() { return chacha(); }
    static inline constexpr std::uint64_t min() noexcept {
        return std::numeric_limits<std::uint64_t>::min();
    }
    static inline constexpr std::uint64_t max() noexcept {
        return std::numeric_limits<std::uint64_t>::max();
    }

   private:
    ChaCha chacha;
};

#endif