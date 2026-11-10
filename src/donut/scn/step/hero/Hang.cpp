#include "scn/step/hero/Hang.hpp"
#include "hel/math/Math.hpp"
#include "hel/math/Vector3.hpp"
#include "scn/step/hero/Piggyback.hpp"

using namespace scn::step::hero;

#pragma dont_inline on
Hang::Hang(Hero& rHero) 
    : mHero(&rHero)
    , mCanReceive(false)
    , mCanHang(false)
    , mIsHangNow(false)
    , mInterval(0)
{}
#pragma dont_inline reset

Hang::~Hang() {}

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

void Hang::setChild(Hang &rChild) {
    if (!mChild.isEmpty() && !rChild.isExistParent()) {
        mChild.set(rChild);
        rChild.setParent(*this);
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
    } else {
        return mParent.getRef().getRootPos();
    }
}

hel::math::Vector3 Hang::getConstraintPos() const {
    hel::math::Vector3 pos = hel::math::Vector3();
    if (mParent.isEmpty()) {
        pos = mHero->location()->pos();
    } else {
        pos = mHero->location()->pos();
        hel::math::Vector3 offsetChild = getConstraintOffsetChild();
        hel::math::Vector3 offsetParent = mParent.getRef().getConstraintOffsetParent();
        hel::math::Vector3 copyParent = hel::math::Vector3(offsetParent); // won't be a perfect match unless this is changed to use stw and lwz
        copyParent += offsetChild;
        hel::math::Vector3 savedPos = hel::math::Vector3(pos); // same here
        savedPos.x *= mParent.getRef().mHero->target()->getSign();
        pos += savedPos;
    }
    return pos;
}

bool Hang::isParentRightDir() const {
    return mParent.getRef().mHero->target()->isRightDir();
}

// All functions below are merged into others, see the header for more info.

void Hang::setParent(Hang &rParent) {
    mParent.set(rParent);
}

bool Hang::isExistParent() const {
    return !mParent.isEmpty();
}

void Hang::setCanReceive(bool canReceive) {
    mCanReceive = canReceive;
}

void Hang::setCanHang(bool canHang) {
    mCanHang = canHang;
}

void Hang::setIsHangNow(bool isHangNow) {
    mIsHangNow = isHangNow;
}

void Hang::setInterval(s32 interval) {
    mInterval = interval;
}

bool Hang::canReceive() const {
    return mCanReceive;
}
