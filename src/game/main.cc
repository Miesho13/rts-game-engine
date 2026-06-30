#include "game.h"

using namespace common::type;
using game::Core;

int main() {
    Core::RetType ret = Core::inst().init();
    if (ret != Core::RetType::OK) { return ret; }
    return Core::inst().run();
}
