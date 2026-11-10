#ifndef DONUT_SCN_STEP_HERO_PIGGYBACK_HPP
#define DONUT_SCN_STEP_HERO_PIGGYBACK_HPP

#include "hel/common/PointerWrapper.hpp"
#include "macros.h"
#include "scn/step/hero/Hero.hpp"

// clang-format off
namespace scn { namespace step { namespace hero {

class Piggyback {
public:
    /* 0x0 */ Hero *mHero;
    /* 0x4 */ hel::common::PointerWrapper<Piggyback> mParent;
    /* 0x8 */ hel::common::PointerWrapper<Piggyback> mChild;
    STRUCT_FILL(0x58 - 0xC);
};

}}}
// clang-format on

#endif
