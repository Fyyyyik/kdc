#ifndef DONUT_SCN_STEP_HERO_NODEATTACH_HPP
#define DONUT_SCN_STEP_HERO_NODEATTACH_HPP

#include <hel/math/Vector3.hpp>

// clang-format off
namespace scn { namespace step { namespace hero {

class NodeAttach {
public:
    void setOffset(const hel::math::Vector3& rOffset);
    void setRotate(const hel::math::Vector3& rRotate);
    void setScale(float scale);
};

struct NodeAttachParam {
    /* 0x00 */ hel::math::Vector3 mOffset;
    /* 0x0C */ hel::math::Vector3 mRotate;
    /* 0x18 */ float mScale;
};

}}}
// clang-format on

#endif
