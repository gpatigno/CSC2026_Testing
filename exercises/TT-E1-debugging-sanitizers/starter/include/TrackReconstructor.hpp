#pragma once

#include <vector>
#include <cstddef>

namespace tt_e1 {

struct Hit {
    double x{};
    double y{};
    double z{};
    double energy{};
};

struct Track {
    double pt{};
    std::vector<Hit> hits{};
};

// ======================================================================
// CSC Latin America 2026 - Tools & Techniques
// Exercise TT-E1: Debugging with Sanitizers
//
// IMPORTANT: This is intentionally buggy student starter code.
// The goal is to use ASan/UBSan to find and fix:
//  - Heap buffer overflow (off-by-one)
//  - Memory leak
//  - Use-after-free
// ======================================================================
class TrackReconstructor {
public:
    explicit TrackReconstructor(double minPt);

    void addHit(const Hit& hit);

    // Intentionally buggy implementation (see .cpp)
    std::vector<Track> reconstruct();

    // Intentionally buggy: returns pointer to freed memory (use-after-free)
    const Track* getBestTrack() const;

private:
    double m_minPt{0.0};
    std::vector<Hit> m_hits{};
};

} // namespace tt_e1

