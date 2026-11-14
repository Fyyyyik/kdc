#include "scn/step/hero/MoveLimitResponseCtrl.hpp"

using namespace scn::step::hero;

MoveLimitResponseCtrl::MoveLimitResponseCtrl()
    : mSpaceJumpTargetPos(0.0f)
{
    mResponse = 0;
}

// https://decomp.me/scratch/r5ZXI
void MoveLimitResponseCtrl::setResponseSpaceJumpToPos(const hel::math::Vector3 &rSpaceJumpPos) {
    mResponse = 3;
    mSpaceJumpTargetPos = rSpaceJumpPos;
}

void MoveLimitResponseCtrl::setResponseDeadLoose() {
    mResponse = 1;
}

void MoveLimitResponseCtrl::resetResponse() {
    mResponse = 0;
}

s32 MoveLimitResponseCtrl::getResponse() const {
    return mResponse;
}

hel::math::Vector3 MoveLimitResponseCtrl::getSpaceJumpTargetPos() const {
    return mSpaceJumpTargetPos;
}
