#ifndef DONUT_SCN_STEP_HERO_WATER_HPP
#define DONUT_SCN_STEP_HERO_WATER_HPP

// clang-format off
namespace scn { namespace step { namespace hero {

class Water {
public:
    // Merged into pause::ButtonPanel::isEnable() const
    bool isInWater() const;
};

}}}
// clang-format on

#endif
