#ifndef DONUT_SCN_STEP_HERO_HANG_HPP
#define DONUT_SCN_STEP_HERO_HANG_HPP

#include "hel/math/Vector3.hpp"
#include "scn/step/common/Param.hpp"
#include "scn/step/hero/Hero.hpp"
#include "hel/common/PointerWrapper.hpp"
#include "types.h"

// clang-format off
namespace scn { namespace step { namespace hero {

class Hang {
public:
    Hang(Hero& rHero);
    ~Hang(); // Merged into scn::IScene::~IScene()

    void setChild(Hang& rChild);
    void clearParent();
    void clearChild();
    void unlinkParent();
    void unlinkChild();
    void unlinkAll();
    void update();
    void chkCollide(Hang& rOther);
    bool canHang() const;
    hel::math::Vector3 getRootPos() const;
    hel::math::Vector3 getConstraintOffsetParent() const;
    // Merged into homebutton::gui::EventHandler::setManager(homebutton::gui::Manager*)
    void setParent(Hang& rParent);
    // Merged into mem::ExplicitScopedPtr<app::HIDErrorMenuImpl>::isConstruct() const
    bool isExistParent() const;
private:
    /* 0x0 */ Hero *mHero;
    /* 0x4 */ hel::common::PointerWrapper<Hang> mParent;
    /* 0x8 */ hel::common::PointerWrapper<Hang> mChild;
    /* 0xC */ bool mCanReceive;
    /* 0xD */ bool mCanHang;
    /* 0xE */ bool mIsHangNow;
    /* 0x10 */ s32 mInterval;
};

}}}
// clang-format on

#endif
