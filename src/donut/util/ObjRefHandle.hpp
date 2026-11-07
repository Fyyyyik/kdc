#ifndef DONUT_UTIL_OBJREFHANDLE_HPP
#define DONUT_UTIL_OBJREFHANDLE_HPP

#include <macros.h>
#include <types.h>

// clang-format off
namespace util {

template <typename T>
class ObjRefHandle {
public:
    class Owner {
    private:
        STRUCT_FILL(0x14);
    };
};

}
// clang-format on

#endif
