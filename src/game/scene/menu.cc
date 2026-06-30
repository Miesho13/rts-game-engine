#include "common/type.h"
#include "../engine/render.h"
#include "game/game.h"
#include "./scene.h"
#include "common/macro.h"

#include <string> 

using engine::Render;
using game::Core;
using std::string;

namespace scene {

    static struct _CORE { 
        static constexpr i32 FONT_SIZE = 42;

        struct {
            int start_pos;
            int size;
        } pos_set;

    } CORE;

    struct {
        Scene id;
        string msg;

        struct {
            int x_beg;
            int x_end;
            int y_beg;
            int y_end;
        } pos;
    } options[] = {
        {
            Scene::GAME_MAIN_SCENE, "GAME_MAIN_SCENE", 
            {
                0, 
                Render::get_render_text_width("GAME_MAIN_SCENE", _CORE::FONT_SIZE), 
                0*_CORE::FONT_SIZE, 
                _CORE::FONT_SIZE
            } 
        },
        {
            Scene::GAME_MAIN_SCENE, "KABALA", 
            {
                0, 
                Render::get_render_text_width("KABALA", _CORE::FONT_SIZE), 
                1*_CORE::FONT_SIZE, 
                _CORE::FONT_SIZE
            } 
        },
        {
            Scene::GAME_MAIN_SCENE, "KABALA", 
            {
                0, 
                Render::get_render_text_width("KABALA", _CORE::FONT_SIZE), 
                2*_CORE::FONT_SIZE, 
                _CORE::FONT_SIZE
            } 
        },
    };

    static void draw_scene_picker(Core &game_core, Render &render) {
        UNUSED(game_core);

        render.begin_frame(); {
            render.clear_frame();

            for (u32 scene = 0; scene < sizeof(options)/sizeof(options[0]); scene++) {
                render.draw_text(options[scene].msg.data(), 
                                 options[scene].pos.x_beg, 
                                 options[scene].pos.y_beg, 
                                 _CORE::FONT_SIZE, 0xb51b1bff);
            }

        } render.end_frame();
    }

    i32 menu_screan_service(Core &game_core, Render &render) {
        draw_scene_picker(game_core, render);
        return 0;
    }
}
