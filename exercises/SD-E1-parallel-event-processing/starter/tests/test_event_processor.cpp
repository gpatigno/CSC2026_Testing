#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "EventProcessor.hpp"

namespace {

struct Totals {
    int tracks{0};
    double energy{0.0};
};

Totals referenceTotals(const std::vector<csc2026::Event>& events) {
    Totals out;
    for (const auto& e : events) {
        out.tracks += static_cast<int>(e.particles.size());
        for (const auto& p : e.particles) {
            out.energy += p.energy();
        }
    }
    return out;
}

} // namespace

TEST_CASE("EventProcessor sums tracks and energy deterministically") {
    const auto events = csc2026::EventProcessor::generateSampleEvents(500);
    const auto ref = referenceTotals(events);

    csc2026::EventProcessor processor;

#ifndef CSC2026_USE_OPENMP
    WARN("OpenMP is not enabled; this test may not expose races.");
#endif

    // Repeat a few times to amplify race detection in the buggy starter.
    for (int trial = 0; trial < 5; ++trial) {
        processor.reset();
        processor.processEvents(events);

        REQUIRE(processor.totalTracks() == ref.tracks);
        REQUIRE(processor.totalEnergy() == Catch::Approx(ref.energy).epsilon(1e-9));
    }
}
