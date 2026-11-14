#ifndef DONUT_SCN_STEP_HERO_MOVELIMIT_HPP
#define DONUT_SCN_STEP_HERO_MOVELIMIT_HPP

#include <hel/geo/Rect.hpp>
#include <hel/math/Vector3.hpp>
#include "scn/step/hero/Hero.hpp"

// clang-format off
namespace scn { namespace step { namespace hero {

class MoveLimit {
public:
    MoveLimit(Hero& rHero);
    ~MoveLimit();

    bool isDead() const;
    bool isOut() const;
    bool isSpaceJumpToMainPlayer() const;
    bool isSpaceJumpToPos() const;
    hel::math::Vector3 spaceJumpTargetPos() const;
    void setWorldCageLimitRect(const hel::geo::Rect& rRect);
private:
    /* 0x0 */ Hero *mHero;
    /* 0x4 */ u32 m_4;
    /* 0x8 */ float m_8;
    /* 0xC */ float m_C;
    /* 0x10 */ float m_10;
    /* 0x14 */ hel::geo::Rect mWorldCageLimit;
};

}}}
// clang-format on

#endif
