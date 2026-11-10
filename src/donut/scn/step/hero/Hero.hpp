#ifndef DONUT_SCN_STEP_HERO_HERO_HPP
#define DONUT_SCN_STEP_HERO_HERO_HPP

#include "hel/math/Vector2.hpp"
#include "macros.h"
#include "mem/ExplicitScopedPtr.hpp"
#include "scn/step/Component.hpp"
#include "scn/step/hero/Kind.hpp"
#include "scn/step/ContextHeroIndivi.hpp"
#include "scn/step/hero/Heap.hpp"
#include "scn/step/hero/Param.hpp"
#include "scn/step/hero/Counter.hpp"
#include "hid/RumbleRequestor.hpp"
#include "gobj/Target.hpp"
#include "gobj/FootState.hpp"
#include "scn/step/chara/Location.hpp"
#include "gobj/Move.hpp"
#include "scn/step/hero/Model.hpp"
#include "scn/step/hero/Effect.hpp"
#include "scn/step/hero/ObjStop.hpp"
#include "scn/step/chara/LandConstraint.hpp"
#include "scn/step/hero/MapColl.hpp"
#include "scn/step/hero/CameraTarget.hpp"
#include "scn/step/hero/Hid.hpp"
#include "scn/step/hero/RunChecker.hpp"
#include "scn/step/hero/ObjColl.hpp"
#include "scn/step/hero/ObjCollReact.hpp"
#include "scn/step/hero/HitStopCallback.hpp"
#include "scn/step/chara/HitStop.hpp"
#include "scn/step/hero/VacuumAttackerCallback.hpp"
#include "scn/step/vacuum/Attacker.hpp"
#include "scn/step/hero/AbilityManager.hpp"
#include "scn/step/hero/StateChecker.hpp"
#include "scn/step/chara/HitPoint.hpp"
#include "scn/step/hero/ItemCatcher.hpp"
#include "scn/step/hero/Dead.hpp"
#include "scn/step/hero/SoundSE.hpp"
#include "scn/step/hero/ItemCollReact.hpp"
#include "scn/step/hero/Flash.hpp"
#include "scn/step/hero/Pinch.hpp"
#include "scn/step/hero/CaptureAttacker.hpp"
#include "scn/step/hero/GatherItem.hpp"
#include "scn/step/hero/Nururi.hpp"
#include "scn/step/chara/WorldCage.hpp"
#include "scn/step/hero/AdditionalMove.hpp"
#include "scn/step/hero/DamageFlash.hpp"
#include "scn/step/hero/DamageFeedback.hpp"
#include "scn/step/chara/GroundChecker.hpp"
#include "scn/step/chara/Shadow.hpp"
#include "scn/step/hero/Water.hpp"
#include "scn/step/hero/CaptureHeroReceiver.hpp"
#include "scn/step/hero/LogoutController.hpp"
#include "scn/step/hero/Stepping.hpp"
#include "scn/step/sfx/DarknessLight.hpp"
#include "scn/step/hero/PowerCharge.hpp"
#include "scn/step/hero/Kiss.hpp"
#include "scn/step/hero/ShakeCharge.hpp"
#include "scn/step/chara/Knockback.hpp"
#include "scn/step/hero/DamageFieldReact.hpp"
#include "scn/step/hero/InvisibleControl.hpp"
#include "scn/step/hero/ScriptData.hpp"
#include "scn/step/debug/EnemyKiller.hpp"
#include "scn/step/boss/ScriptCallback.hpp"
#include "scn/step/hero/Door.hpp"
#include "scn/step/hero/Mahoroa.hpp"
#include "scn/step/hero/Blink.hpp"
#include "scn/step/hero/PosNotifier.hpp"
#include "scn/step/hero/Hat.hpp"
#include "scn/step/hero/CommandManager.hpp"
#include "scn/step/hero/WearBack.hpp"
#include "scn/step/hero/InertialMove.hpp"
#include "scn/step/hero/Squash.hpp"
#include "scn/step/hero/VacuumReceiver.hpp"
#include "scn/step/hero/RotCtrl.hpp"
#include "scn/step/hero/ChargeFlash.hpp"
#include "scn/step/hero/Cry.hpp"
#include "scn/step/hero/NodeAttach.hpp"
#include "scn/step/hero/LandAttribute.hpp"
#include "scn/step/hero/AbilityCrashCtrl.hpp"
#include "scn/step/hero/StagingCtrl.hpp"
#include "scn/step/hero/ZNururi.hpp"
#include "scn/step/hero/MapCollProducer.hpp"
#include "scn/step/hero/RoofChecker.hpp"
#include "scn/step/hero/MoveLimit.hpp"
#include "scn/step/hero/Landing.hpp"
#include "scn/step/hero/ChallengeBattleCtrl.hpp"
#include "scn/step/hero/StateCallback.hpp"
#include "scn/step/hero/IState.hpp"
#include "util/StateChanger.hpp"
#include "util/ObjRefHandle.hpp"
#include "types.h"

using namespace hid;

// clang-format off
namespace scn { namespace step { namespace hero {

    class Invincible;
    class Guard;
    class Hang;
    class Piggyback;

    class Hero {
    public:
        Param* param() const;
        Dead *dead();
        Water *water();
        ObjStop *objStop();
        scn::step::chara::Location *location() const;
        scn::step::vacuum::Attacker *vacuumAttacker();
        Piggyback *piggyback();
        // NOTE: Is merged into mcoll::detail::CollidedDetectionInfo::collideTargetIndex() const
        Kind kind() const;
        // Merged into scn::step::hero::Hero::stateChecker()
        StateChecker *stateChecker() const;
        // Merged into scn::step::hero::Hero::dead()
        Dead *dead() const;
        // Merged into scn::step::hero::Hero::vacuumAttacker()
        scn::step::vacuum::Attacker *vacuumAttacker() const;
    private:
        /* 0x0 */ scn::step::Component* mComponent;
        /* 0x4 */ STRUCT_FILL(0x8); // todo: replace with a HeapExpArrayUser
        /* 0xC */ scn::step::ContextHeroIndivi mContext;
        /* 0x48 */ hel::math::Vector2 m_48;
        /* 0x50 */ scn::step::hero::Kind mKind;
        /* 0x54 */ s32 m_54;
        /* 0x58 */ u32 m_58;
        /* 0x5C */ u32 m_5C;
        /* 0x60 */ bool mIsRenderFore;
        /* 0x61 */ bool mCanReactGimmick;
        /* 0x62 */ bool mCanCatchItem;
        /* 0x63 */ bool mIsVisible;
        /* 0x64 */ bool mIsVacuum;
        /* 0x65 */ bool mNeedModelProcFixPos;
        /* 0x66 */ bool m_66;
        /* 0x68 */ mem::ExplicitScopedPtr<Heap*> mHeap;
        /* 0x70 */ mem::ExplicitScopedPtr<Param*> mParam;
        /* 0x78 */ mem::ExplicitScopedPtr<Counter*> mCounter;
        /* 0x80 */ mem::ExplicitScopedPtr<RumbleRequestor*> mRumbleRequestor;
        /* 0x88 */ mem::ExplicitScopedPtr<gobj::Target*> mTarget;
        /* 0x90 */ mem::ExplicitScopedPtr<gobj::FootState*> mFootState;
        /* 0x98 */ mem::ExplicitScopedPtr<scn::step::chara::Location*> mLocation;
        /* 0xA0 */ mem::ExplicitScopedPtr<gobj::Move*> mMove;
        /* 0xA8 */ mem::ExplicitScopedPtr<Model*> mModel;
        /* 0xB0 */ mem::ExplicitScopedPtr<Effect*> mEffect;
        /* 0xB8 */ mem::ExplicitScopedPtr<ObjStop*> mObjStop;
        /* 0xC0 */ mem::ExplicitScopedPtr<scn::step::chara::LandConstraint*> mLandConstraint;
        /* 0xC8 */ mem::ExplicitScopedPtr<MapColl*> mMapColl;
        /* 0xD0 */ mem::ExplicitScopedPtr<CameraTarget*> mCameraTarget;
        /* 0xD8 */ mem::ExplicitScopedPtr<Hid*> mHid;
        /* 0xE0 */ mem::ExplicitScopedPtr<RunChecker*> mRunChecker;
        /* 0xE8 */ mem::ExplicitScopedPtr<ObjColl*> mObjColl;
        /* 0xF0 */ mem::ExplicitScopedPtr<ObjCollReact*> mObjCollReact;
        /* 0xF8 */ mem::ExplicitScopedPtr<HitStopCallback*> mHitStopCallback;
        /* 0x100 */ mem::ExplicitScopedPtr<scn::step::chara::HitStop*> mHitStop;
        /* 0x108 */ mem::ExplicitScopedPtr<VacuumAttackerCallback*> mVacuumAttackerCallback;
        /* 0x110 */ mem::ExplicitScopedPtr<scn::step::vacuum::Attacker*> mVacuumAttacker;
        /* 0x118 */ mem::ExplicitScopedPtr<AbilityManager*> mAbilityManager;
        /* 0x120 */ mem::ExplicitScopedPtr<Invincible*> mInvincible;
        /* 0x128 */ mem::ExplicitScopedPtr<StateChecker*> mStateChecker;
        /* 0x130 */ mem::ExplicitScopedPtr<scn::step::chara::HitPoint*> mHitPoint;
        /* 0x138 */ mem::ExplicitScopedPtr<ItemCatcher*> mItemCatcher;
        /* 0x140 */ mem::ExplicitScopedPtr<Dead*> mDead;
        /* 0x148 */ mem::ExplicitScopedPtr<SoundSE*> mSoundSE;
        /* 0x150 */ mem::ExplicitScopedPtr<ItemCollReact*> mItemCollReact;
        /* 0x158 */ mem::ExplicitScopedPtr<Flash*> mFlash;
        /* 0x160 */ mem::ExplicitScopedPtr<Pinch*> mPinch;
        /* 0x168 */ mem::ExplicitScopedPtr<Guard*> mGuard;
        /* 0x170 */ mem::ExplicitScopedPtr<CaptureAttacker*> mCaptureAttacker;
        /* 0x178 */ mem::ExplicitScopedPtr<GatherItem*> mGatherItem;
        /* 0x180 */ mem::ExplicitScopedPtr<Nururi*> mNururi;
        /* 0x188 */ mem::ExplicitScopedPtr<scn::step::chara::WorldCage*> mWorldCage;
        /* 0x190 */ mem::ExplicitScopedPtr<AdditionalMove*> mAdditionalMove;
        /* 0x198 */ mem::ExplicitScopedPtr<DamageFlash*> mDamageFlash;
        /* 0x1A0 */ mem::ExplicitScopedPtr<DamageFeedback*> mDamageFeedback;
        /* 0x1A8 */ mem::ExplicitScopedPtr<scn::step::chara::GroundChecker*> mGroundChecker;
        /* 0x1B0 */ mem::ExplicitScopedPtr<scn::step::chara::Shadow*> mShadow;
        /* 0x1B8 */ mem::ExplicitScopedPtr<Water*> mWater;
        /* 0x1C0 */ mem::ExplicitScopedPtr<CaptureHeroReceiver*> mCaptureHeroReceiver;
        /* 0x1C8 */ mem::ExplicitScopedPtr<Piggyback*> mPiggyback;
        /* 0x1D0 */ mem::ExplicitScopedPtr<LogoutController*> mLogoutController;
        /* 0x1D8 */ mem::ExplicitScopedPtr<Stepping*> mStepping;
        /* 0x1E0 */ mem::ExplicitScopedPtr<scn::step::sfx::DarknessLight*> mDarknessLight;
        /* 0x1E8 */ mem::ExplicitScopedPtr<PowerCharge*> mPowerCharge;
        /* 0x1F0 */ mem::ExplicitScopedPtr<Kiss*> mKiss;
        /* 0x1F8 */ mem::ExplicitScopedPtr<ShakeCharge*> mShakeCharge;
        /* 0x200 */ mem::ExplicitScopedPtr<scn::step::chara::Knockback*> mKnockback;
        /* 0x208 */ mem::ExplicitScopedPtr<DamageFieldReact*> mDamageFieldReact;
        /* 0x210 */ mem::ExplicitScopedPtr<InvisibleControl*> mInvisibleControl;
        /* 0x218 */ mem::ExplicitScopedPtr<ScriptData*> mScriptData;
        /* 0x220 */ mem::ExplicitScopedPtr<scn::step::debug::EnemyKiller*> mEnemyKiller;
        /* 0x228 */ mem::ExplicitScopedPtr<scn::step::boss::ScriptCallback*> mBossScriptCallback;
        /* 0x230 */ mem::ExplicitScopedPtr<Door*> mDoor;
        /* 0x238 */ mem::ExplicitScopedPtr<Mahoroa*> mMahoroa;
        /* 0x240 */ mem::ExplicitScopedPtr<Blink*> mBlink;
        /* 0x248 */ mem::ExplicitScopedPtr<PosNotifier*> mPosNotifier;
        /* 0x250 */ mem::ExplicitScopedPtr<Hat*> mHat;
        /* 0x258 */ mem::ExplicitScopedPtr<CommandManager*> mCommandManager;
        /* 0x260 */ mem::ExplicitScopedPtr<WearBack*> mWearBack;
        /* 0x268 */ mem::ExplicitScopedPtr<InertialMove*> mInertialMove;
        /* 0x270 */ mem::ExplicitScopedPtr<Squash*> mSquash;
        /* 0x278 */ mem::ExplicitScopedPtr<Hang*> mHang;
        /* 0x280 */ mem::ExplicitScopedPtr<VacuumReceiver*> mVacuumReceiver;
        /* 0x288 */ mem::ExplicitScopedPtr<RotCtrl*> mRotCtrl;
        /* 0x290 */ mem::ExplicitScopedPtr<ChargeFlash*> mChargeFlash;
        /* 0x298 */ mem::ExplicitScopedPtr<Cry*> mCry;
        /* 0x2A0 */ mem::ExplicitScopedPtr<NodeAttach*> mNodeAttach;
        /* 0x2A8 */ mem::ExplicitScopedPtr<LandAttribute*> mLandAttribute;
        /* 0x2B0 */ mem::ExplicitScopedPtr<AbilityCrashCtrl*> mAbilityCrashCtrl;
        /* 0x2B8 */ mem::ExplicitScopedPtr<StagingCtrl*> mStagingCtrl;
        /* 0x2C0 */ mem::ExplicitScopedPtr<ZNururi*> mZNururi;
        /* 0x2C8 */ mem::ExplicitScopedPtr<MapCollProducer*> mMapCollProducer;
        /* 0x2D0 */ mem::ExplicitScopedPtr<RoofChecker*> mRoofChecker;
        /* 0x2D8 */ mem::ExplicitScopedPtr<MoveLimit*> mMoveLimit;
        /* 0x2E0 */ mem::ExplicitScopedPtr<Landing*> mLanding;
        /* 0x2E8 */ mem::ExplicitScopedPtr<ChallengeBattleCtrl*> mChallengeBattleCtrl;
        /* 0x2F0 */ mem::ExplicitScopedPtr<StateCallback*> mStateCallback;
        /* 0x2F8 */ mem::ExplicitScopedPtr<util::StateChanger<IState*, 256> > mStateChanger;
        /* 0x300 */ util::ObjRefHandle<Hero>::Owner mOwner;
    };
}}}
// clang-format on

#endif
