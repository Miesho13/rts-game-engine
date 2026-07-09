#ifndef __INFO__
#define __INFO__

#include "common/type.h"

using namespace common::type;

namespace game {
    constexpr struct {
        i32 major;
        i32 minor;
        i32 patch;
    } version = { 0, 1, 0};
}

#endif // __INFO__
