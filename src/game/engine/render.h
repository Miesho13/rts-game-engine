#ifndef __GAME_WIN__
#define __GAME_WIN__

#include "common/type.h"
#include <functional>

using namespace common::type;
using std::function;

namespace engine {
    class Render {
        public :
            Render();
            ~Render();

            Render(const Render&) = delete;
            Render& operator=(const Render&) = delete;
            bool operator==(const Render&) const = delete;
            bool operator!=(const Render&) const = delete;
            bool operator<(const Render&) const = delete;

            static Render& inst();
            void init(i32 width, i32 height, const c8 *title);
            //
            bool win_shoud_close();
            // Function shoud handle win event, input and draw in frame
            void step(function<void()> draw_frame);

            void begin_frame();
            void end_frame();
            void clear_frame(uint32_t rgb32);

            // Draw
            void draw_text(const c8 *msg, i32 posx, i32 posy, i32 font_size, u32 color);

            static i32 get_render_text_width(const c8 *text, i32 font_size);
        private :
            struct  {
                i32 width;
                i32 height;
                bool close;
            } win_stats;
    };


}

#endif // __GAME_WIN__
