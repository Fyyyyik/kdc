#ifndef DONUT_SCN_STEP_HERO_STATECHECKER_HPP
#define DONUT_SCN_STEP_HERO_STATECHECKER_HPP

// clang-format off
namespace scn { namespace step { namespace hero {

class StateChecker {
public:
    // Merged into scn::step::bg::ResPart::gridHeight() const
    bool haveBomb() const;
};

}}}
// clang-format on

#endif
