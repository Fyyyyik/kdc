#ifndef DONUT_SCN_STEP_HERO_HANG_HPP
#define DONUT_SCN_STEP_HERO_HANG_HPP

#include <hel/math/Vector3.hpp>
#include "scn/step/hero/Hero.hpp"
#include <hel/common/PointerWrapper.hpp>
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
    hel::math::Vector3 getConstraintOffsetChild() const;
    hel::math::Vector3 getConstraintPos() const;
    bool isParentRightDir() const;
    // Merged into homebutton::gui::EventHandler::setManager(homebutton::gui::Manager*)
    void setParent(Hang& rParent);
    // Merged into mem::ExplicitScopedPtr<app::HIDErrorMenuImpl>::isConstruct() const
    bool isExistParent() const;
    // Merged into mcoll::detail::DetectArg::setIsPassThroughLand(bool)
    void setCanReceive(bool canReceive);
    // Merged into mcoll::detail::DetectArg::setIsGenerateFloorToOneSpaceGrid(bool)
    void setCanHang(bool canHang);
    // Merged into mcoll::detail::DetectArg::setIsGenerateFloorToTwoSpaceGrid(bool)
    void setIsHangNow(bool isHangNow);
    // Merged into GXInitTexObjUserData
    void setInterval(s32 interval);
    // Merged into mcoll::detail::DetectArg::isPassThroughLand() const
    bool canReceive() const;
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
