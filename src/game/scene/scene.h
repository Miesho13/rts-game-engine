#ifndef __SCENE__
#define __SCENE__

#include "../engine/render.h"
#include "game/game.h"
#include "common/type.h"

#include <functional>

using std::function;

namespace scene {
    using scene_ptr = i32 (*)(game::Core &core, engine::Render &win);

    enum Scene : i32  {
        LOG_IN_SCENE,
        GAME_MAIN_SCENE,

        COUNT,
    };

    // all available scene
    i32 menu_screan_service(game::Core &core, engine::Render &win);

    constexpr array<scene_ptr, Scene::COUNT> scene_table = {
        menu_screan_service,
    };

}

#endif // __SCENE__
