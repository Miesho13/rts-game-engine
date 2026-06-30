#ifndef __GAME__
#define __GAME__

#include "./engine/render.h"

#include "common/type.h"
#include <array>

using namespace common::type;
using engine::Render;
using std::array;

namespace game {

    class Core {
        public:
            // UNUSED OPERATOR
            Core(const Core&) = delete;
            Core& operator=(const Core&) = delete;
            bool operator==(const Core&) const = delete;
            bool operator!=(const Core&) const = delete;
            bool operator<(const Core&) const = delete;
            // Game render def context
            static constexpr i32 DEF_WIN_WIDTH  = 800;
            static constexpr i32 DEF_WIN_HEIGHT = 600;
            static constexpr const c8* DEF_WIN_NAME = "Pyk";
            // Scene def

            // Game context
            enum RetType : i32 {
                OK,
                INIT_ERROR,
                RUN_ERROR,
            };

            Core();
            ~Core();
            static Core& inst();

            RetType init();
            RetType run();

            bool is_game_run();

            void close_game();

            void pick_scene(i32 scene);
        private:
            struct {
                bool game_run;
                i32  scene_picker;
            } global_game_state;

            Render render;
    };
}

#endif // __GAME__
