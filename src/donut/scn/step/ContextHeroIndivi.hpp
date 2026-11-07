#ifndef DONUT_SCN_STEP_CONTEXTHEROINDIVI_HPP
#define DONUT_SCN_STEP_CONTEXTHEROINDIVI_HPP

#include "scn/step/hero/Kind.hpp"
#include "macros.h"
#include "types.h"

// clang-format off
namespace scn { namespace step {

class ContextHeroIndivi {
private:
    STRUCT_FILL(0x4);
    scn::step::hero::Kind mKind;
    STRUCT_FILL(0x3C - 0x8);
};

}}
// clang-format on

#endif
