#include "game.h"
#include "info.h"
#include "common/log.h"

using namespace common::type;
using game::Core;

int main() {
    log_inf("Game run {}.{}.{}", game::version.major, 
                                 game::version.minor, 
                                 game::version.patch);

    Core::RetType ret = Core::inst().init();
    if (ret != Core::RetType::OK) { return ret; }
    return Core::inst().run();
}
