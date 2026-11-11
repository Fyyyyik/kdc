#ifndef DONUT_SCN_STEP_HERO_KISS_HPP
#define DONUT_SCN_STEP_HERO_KISS_HPP

#include "scn/step/hero/Hero.hpp"
#include <types.h>
#include <macros.h>
#include <hel/common/MutableArray.hpp>

// clang-format off
namespace scn { namespace step { namespace hero {

class Kiss {
private:
    /* 0x0 */ Hero *mHero;
    /* 0x4 */ bool mCanKiss;
    /* 0x5 */ bool mCanReceive;
    /* 0x8 */ u32 mReadyToKiss;
    /* 0xC */ hel::common::MutableArray<hel::common::MutableArray<u32, 8>, 1> m_C;
    /* 0x34 */ hel::common::MutableArray<u32, 8> m_34;
    /* 0x58 */ u32 m_58;
    /* 0x5C */ hel::common::MutableArray<bool, 1> m_5C;
    /* 0x64 */ hel::common::MutableArray<bool, 1> m_64;
    /* 0x6C */ bool mPause;
    /* 0x70 */ u32 m_70;
};

}}}
// clang-format on

#endif
