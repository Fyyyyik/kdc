#ifndef DONUT_SCN_STEP_HERO_PARAM_HPP
#define DONUT_SCN_STEP_HERO_PARAM_HPP

#include "scn/step/common/Param.hpp"

// clang-format off
namespace scn { namespace step { namespace hero {

class Param {
public:
    common::Param* common() const;
    common::Param* indiviKirby() const;
    common::Param* indiviMeta() const;
    common::Param* indiviDedede() const;
    common::Param* indiviDee() const;
};

}}}
// clang-format on

#endif
