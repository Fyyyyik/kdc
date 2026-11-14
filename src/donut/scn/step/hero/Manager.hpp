#ifndef DONUT_SCN_STEP_HERO_MANAGER_HPP
#define DONUT_SCN_STEP_HERO_MANAGER_HPP

#include "scn/step/hero/MoveLimitResponseCtrl.hpp"

namespace scn { namespace step { namespace hero {

class Manager {
public:
    MoveLimitResponseCtrl *moveLimitResponseCtrl();
};

}}}

#endif
