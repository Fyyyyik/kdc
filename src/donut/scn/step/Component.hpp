#ifndef DONUT_SCN_STEP_COMPONENT_HPP
#define DONUT_SCN_STEP_COMPONENT_HPP

#include "g3d/ResFileRepository.hpp"
#include "scn/step/Context.hpp"
#include "scn/step/core/SphereAccessor.hpp"
#include "scn/step/debug/GeneralDrawer.hpp"
#include "scn/step/debug/ObjInfoRepos.hpp"
#include "scn/step/debug/ShowGrid.hpp"
#include "scn/step/debug/ShowPegFrame.hpp"
#include "scn/step/hero/Manager.hpp"
#include "scn/step/map/DataFile.hpp"
#include "scn/step/spstop/Manager.hpp"
#include <hel/common/ScopedPtr.hpp>

// clang-format off

namespace scn { namespace step {
    namespace core {
        class SceneChanger { };
        class G3DRootSet { };
        class AreaLightManager { };
        class MintManager { };
        class PermSoundSE { };
        class AreaOperation { };
        class BGMController { };
        class PauseTrigger { };
        class PermEffect { };
        class PreLoadReq { };
        class PauseManager { };
        class MoveLimit { };
    }

    namespace effect {
        class Manager { };
    }

    namespace ostop {
        class Manager { };
    }

    namespace sfx {
        class BGFade { };
        class ScreenFade { };
        class Wipe { };
        class CinemaScope { };
        class AbilityGetFade { };
        class SuperFade { };
        class SuperBackPicture { };
        class Manager { };
        class ShadowRoot { };
        class DarknessRoot { };
        class DarknessAdjust { };
    }

    namespace info {
        class Manager { };
    }

    namespace camera {
        class CameraController { };
        class BgCamera { };
        class CameraAccessor { };
        class DebugCamera { };
        class MainCamera { };
        class InvidiCameraManager { };
    }

    namespace ocoll {
        class Manager { };
    }

    namespace vacuum {
        class Manager { };
    }

    namespace nururi {
        class Manager { };
    }

    namespace map {
        class MemManager { };
        class LandManager { };
    }

    namespace bg {
        class Manager { };
        class DecorationManager { };
    }

    namespace gimmick {
        class Manager { };
    }

    namespace ogen {
        class Manager { };
    }

    namespace weapon {
        class Manager { };
    }

    namespace enemy {
        class Manager { };
    }

    namespace boss {
        class Manager { };
    }

    namespace ghost {
        class Manager { };
    }

    namespace challenge {
        class Manager { };
    }

    namespace debug {
        class ObjPlacement { };
    }

    namespace hid {
        class RumbleManager { };
    }

    namespace item {
        class Manager { };
    }
}}

using hel::common::ScopedPtr;

namespace scn { namespace step {

class Component {
public:
    ~Component();

    core::SphereAccessor* sphereAccessor();
    core::SceneChanger* sceneChanger();
    spstop::Manager* superStopManager();
    debug::GeneralDrawer* debugGeneralDrawer();
    debug::ObjInfoRepos* debugObjInfoRepos();
    hero::Manager* heroManager();
private:
    /* 0x00 */ ScopedPtr<Context> mContext;
    /* 0x04 */ ScopedPtr<map::DataFile> mDataFile;
    /* 0x08 */ ScopedPtr<core::SphereAccessor> mSphereAccessor;
    /* 0x0C */ ScopedPtr<core::SceneChanger> mSceneChanger;
    /* 0x10 */ ScopedPtr<g3d::ResFileRepository> mResFileRepository;
    /* 0x14 */ ScopedPtr<core::G3DRootSet> mG3DRootSet;
    /* 0x18 */ ScopedPtr<effect::Manager> mEffectManager;
    /* 0x1C */ ScopedPtr<core::AreaLightManager> mAreaLightManager;
    /* 0x20 */ ScopedPtr<core::MintManager> mMintManager;
    /* 0x24 */ ScopedPtr<hid::RumbleManager> mRumbleManager;
    /* 0x28 */ ScopedPtr<core::PermSoundSE> mPermSoundSE;
    /* 0x2C */ ScopedPtr<core::AreaOperation> mAreaOperation;
    /* 0x30 */ ScopedPtr<core::BGMController> mBGMController;
    /* 0x34 */ ScopedPtr<core::PauseTrigger> mPauseTrigger;
    /* 0x38 */ ScopedPtr<ostop::Manager> mOstopManager;
    /* 0x3C */ ScopedPtr<spstop::Manager> mSuperStopManager;
    /* 0x40 */ ScopedPtr<core::PermEffect> mPermEffect;
    /* 0x44 */ ScopedPtr<core::PreLoadReq> mPreLoadReq;
    /* 0x48 */ ScopedPtr<sfx::BGFade> mBgFadeWithoutLand;
    /* 0x4C */ ScopedPtr<sfx::BGFade> mBgFade;
    /* 0x50 */ ScopedPtr<sfx::BGFade> mBgFadeOverGimmick;
    /* 0x54 */ ScopedPtr<sfx::BGFade> mFgFade;
    /* 0x58 */ ScopedPtr<sfx::ScreenFade> mScreenFade;
    /* 0x5C */ ScopedPtr<sfx::Wipe> mWipe;
    /* 0x60 */ ScopedPtr<sfx::CinemaScope> mCinemaScope;
    /* 0x64 */ ScopedPtr<sfx::AbilityGetFade> mAbilityGetFade;
    /* 0x68 */ ScopedPtr<sfx::SuperFade> mSuperFade;
    /* 0x6C */ ScopedPtr<sfx::SuperBackPicture> mSuperBackPicture;
    /* 0x70 */ ScopedPtr<sfx::Manager> mSfxManager;
    /* 0x74 */ ScopedPtr<sfx::ShadowRoot> mShadowRoot;
    /* 0x78 */ ScopedPtr<sfx::DarknessRoot> mDarknessRoot;
    /* 0x7C */ ScopedPtr<sfx::DarknessAdjust> mDarknessAdjust;
    /* 0x80 */ ScopedPtr<info::Manager> mInfoManager;
    /* 0x84 */ ScopedPtr<core::PauseManager> mPauseManager;
    /* 0x88 */ ScopedPtr<camera::CameraController> mCameraController;
    /* 0x8C */ ScopedPtr<camera::BgCamera> mBgCamera;
    /* 0x90 */ ScopedPtr<camera::CameraAccessor> mCameraAccessor;
    /* 0x94 */ ScopedPtr<camera::DebugCamera> mDebugCamera;
    /* 0x98 */ ScopedPtr<camera::MainCamera> mMainCamera;
    /* 0x9C */ ScopedPtr<camera::InvidiCameraManager> mIndiviCameraManager;
    /* 0xA0 */ ScopedPtr<ocoll::Manager> mObjCollManager;
    /* 0xA4 */ ScopedPtr<vacuum::Manager> mVacuumManager;
    /* 0xA8 */ ScopedPtr<nururi::Manager> mNururiManager;
    /* 0xAC */ ScopedPtr<map::MemManager> mMapMemManager;
    /* 0xB0 */ ScopedPtr<bg::DecorationManager> mMapDecorationManager;
    /* 0xB4 */ ScopedPtr<map::LandManager> mMapLandManager;
    /* 0xB8 */ ScopedPtr<gimmick::Manager> mGimmickManager;
    /* 0xBC */ ScopedPtr<core::MoveLimit> mMoveLimit;
    /* 0xC0 */ ScopedPtr<ogen::Manager> mObjGenManager;
    /* 0xC4 */ ScopedPtr<weapon::Manager> mWeaponManager;
    /* 0xC8 */ ScopedPtr<hero::Manager> mHeroManager;
    /* 0xCC */ ScopedPtr<item::Manager> mItemManager;
    /* 0xD0 */ ScopedPtr<enemy::Manager> mEnemyManager;
    /* 0xD4 */ ScopedPtr<boss::Manager> mBossManager;
    /* 0xD8 */ ScopedPtr<ghost::Manager> mGhostManager;
    /* 0xDC */ ScopedPtr<challenge::Manager> mChallengeManager;
    /* 0xE0 */ ScopedPtr<debug::GeneralDrawer> mDebugGeneralDrawer;
    /* 0xE4 */ ScopedPtr<debug::ObjInfoRepos> mDebugObjInfoRepos;
    /* 0xE8 */ ScopedPtr<debug::ObjPlacement> mObjPlacement;
    /* 0xEC */ ScopedPtr<debug::ShowGrid> mShowGrid;
    /* 0xF0 */ ScopedPtr<debug::ShowPegFrame> mShowPegFrame;
};

}}

// clang-format on

#endif
