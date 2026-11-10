#ifndef DONUT_SCN_STEP_HERO_DEAD_HPP
#define DONUT_SCN_STEP_HERO_DEAD_HPP

// clang-format off
namespace scn { namespace step { namespace hero {

class Dead {
public:
    // Merged into pause::ButtonPanel::isEnable() const
    bool isDead() const;
};

}}}
// clang-format on

#endif
