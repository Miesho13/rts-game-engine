#include "game.h"
#include "common/macro.h"
#include "game/scene/scene.h"

#include "common/file.h"
#include "model.h"

#include <print>

using std::println;
using scene::Scene;

namespace game {
    Core::Core()  { }
    Core::~Core() { }

    Core& Core::inst() {
        static Core inst_;
        return inst_;
    }

    Core::RetType Core::init() {
        /*
        global_game_state.game_run = true;
        global_game_state.scene_picker = CAST(0, i32);

        render.init(DEF_WIN_WIDTH, DEF_WIN_HEIGHT, DEF_WIN_NAME);
        */
        return RetType::OK;
    }

    void Core::pick_scene(i32 scene) {
        if (global_game_state.scene_picker >= 0 && global_game_state.scene_picker < Scene::COUNT) {
            global_game_state.scene_picker = scene;
        }
    }

    void Core::close_game() {
        //Optionally, we can save some state for the player or
        // do any action for a graceful game close.
        global_game_state.game_run = false;
    }

    bool Core::is_game_run() {
        return global_game_state.game_run && !render.win_shoud_close();
    }

    Core::RetType Core::run() {
        // string f_str = common::read_file_to_string("/home/miesho/programming/cpp/rts_engine/assets/penger.obj");
        // println("{}", f_str);

        model::Obj obj("/home/miesho/programming/cpp/rts_engine/assets/penger.obj");
        
        while (is_game_run())  {
            i32 ret = scene::scene_table[global_game_state.scene_picker](*this, render);
            UNUSED(ret);
        }
        return RetType::OK;
    }
}
