#include "scn/step/hero/MoveLimit.hpp"

using namespace scn::step::hero;

MoveLimit::MoveLimit(Hero& rHero)
    : mHero(&rHero)
    , m_4(0)
    , m_10(0.0f)
    , m_8(0.0f)
    , m_C(0.0f)
{}

MoveLimit::~MoveLimit() {}

bool MoveLimit::isDead() const {
    bool dead = false;
    if (
        isOut() &&
        (
            mHero->comp()->heroManager()->moveLimitResponseCtrl()->getResponse() ||
            mHero->comp()->heroManager()->moveLimitResponseCtrl()->getResponse() == 1
        )
    ) {
        dead = true;
    }
    return dead;
}

bool MoveLimit::isSpaceJumpToMainPlayer() const {
    bool spaceJump = false;
    if (
        isOut() &&
        mHero->comp()->heroManager()->moveLimitResponseCtrl()->getResponse() == 2
    ) {
        spaceJump = true;
    }
    return spaceJump;
}

bool MoveLimit::isSpaceJumpToPos() const {
    bool spaceJump = false;
    if (
        isOut() &&
        mHero->comp()->heroManager()->moveLimitResponseCtrl()->getResponse() == 3
    ) {
        spaceJump = true;
    }
    return spaceJump;
}

hel::math::Vector3 MoveLimit::spaceJumpTargetPos() const {
    return mHero->comp()->heroManager()->moveLimitResponseCtrl()->getSpaceJumpTargetPos();
}

void MoveLimit::setWorldCageLimitRect(const hel::geo::Rect &rRect) {
    mWorldCageLimit = rRect;
}
