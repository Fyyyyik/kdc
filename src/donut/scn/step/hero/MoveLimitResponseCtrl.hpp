#ifndef DONUT_SCN_STEP_HERO_MOVELIMITRESPONSECTRL_HPP
#define DONUT_SCN_STEP_HERO_MOVELIMITRESPONSECTRL_HPP

#include <hel/math/Vector3.hpp>
#include <types.h>

// clang-format off
namespace scn { namespace step { namespace hero {

class MoveLimitResponseCtrl {
public:
    MoveLimitResponseCtrl();

    void setResponseSpaceJumpToPos(const hel::math::Vector3& rSpaceJumpPos);
    // Merged into gfx::GameScreen::GameScreen()
    void setResponseDeadLoose();
    // Merged into nw4r::g3d::LightObj::LightObj()
    void resetResponse();
    // Merged into GKI_getfirst
    s32 getResponse() const;
    // Merged into gobj::Move::velocity() const
    hel::math::Vector3 getSpaceJumpTargetPos() const;
private:
    /* 0x0 */ s32 mResponse;
    /* 0x4 */ hel::math::Vector3 mSpaceJumpTargetPos;
};

}}}
// clang-format on

#endif
