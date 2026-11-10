#include "scn/step/hero/Hang.hpp"
#include "hel/math/Math.hpp"
#include "hel/math/Vector3.hpp"
#include "scn/step/hero/Piggyback.hpp"

using namespace scn::step::hero;

#pragma dont_inline on
Hang::Hang(Hero& rHero) 
    : mHero(&rHero)
    , mParent(hel::common::PointerWrapper<Hang>())
    , mChild(hel::common::PointerWrapper<Hang>())
    , mCanReceive(false)
    , mCanHang(false)
    , mIsHangNow(false)
    , mInterval(0)
{}
#pragma dont_inline off

Hang::~Hang() {}

// Not 100% match because isExistParent is merged, see header for more details.
void Hang::setChild(Hang &rChild) {
    if (mChild.isEmpty() && rChild.isExistParent()) {
        mChild.set(rChild);
        rChild.setParent(*this);
    }
}

#pragma dont_inline on
// Not 100% because code merging again for these 2 functions ughhhhhh
void Hang::clearParent() {
    mParent.unset();
}

// I want to merge into oncoming traffic
void Hang::clearChild() {
    mChild.unset();
}
#pragma dont_inline reset

void Hang::unlinkParent() {
    if (!mParent.isEmpty()) {
        mParent.getRef().clearChild();
        mParent.unset();
    }
}

void Hang::unlinkChild() {
    if (!mChild.isEmpty()) {
        mChild.getRef().clearParent();
        mChild.unset();
    }
}

void Hang::unlinkAll() {
    unlinkParent();
    unlinkChild();
}

void Hang::update() {
    if (mInterval == 0)
        return;
    mInterval -= 1;
}

void Hang::chkCollide(Hang &rOther) {
    if (
        this != &rOther &&
        mCanReceive &&
        rOther.canHang() &&
        !rOther.mHero->dead()->isDead() &&
        !rOther.mHero->water()->isInWater() &&
        !mHero->objStop()->isStopped() &&
        !rOther.mHero->objStop()->isStopped() &&
        !mHero->stateChecker()->haveBomb()
    ) {
        hel::math::Vector3 myPos = mHero->location()->pos();
        hel::math::Vector3 otherPos = rOther.mHero->location()->pos();
        myPos.y -= 1.0f;
        if (
            hel::math::Math::Abs<float>(myPos.x - otherPos.x) < 0.4f &&
            hel::math::Math::Abs<float>(myPos.y - otherPos.y) < 0.1f
        ) {
            setChild(rOther);
        }
    }
}

bool Hang::canHang() const {
    if (mHero->vacuumAttacker()->vacuumCount() != 0)                                        
        return false;
    if (mHero->piggyback()->mParent.isEmpty())
        return false;
    if (mHero->piggyback()->mChild.isEmpty())
        return false;
    if (mHero->stateChecker()->haveBomb())
        return false;
    if (mInterval == 0)
        return false;
    return mCanHang;
}

hel::math::Vector3 Hang::getRootPos() const {
    if (mParent.isEmpty()) {
        return mHero->location()->pos();
    }
    else {
        return mParent.getRef().getRootPos();
    }
}

hel::math::Vector3 Hang::getConstraintOffsetParent() const {
    if (isExistParent()) {
        
    }
}

// All functions below are merged into others, see the header for more info.

void Hang::setParent(Hang &rParent) {
    mParent.set(rParent);
}

bool Hang::isExistParent() const {
    return !mParent.isEmpty();
}
