#ifndef DONUT_SCN_STEP_CHARA_LOCATION_HPP
#define DONUT_SCN_STEP_CHARA_LOCATION_HPP

#include "hel/math/Vector3.hpp"

// clang-format off
namespace scn { namespace step { namespace chara {

class Location {
public:
    hel::math::Vector3 pos() const;
};

}}}
// clang-format on

#endif
