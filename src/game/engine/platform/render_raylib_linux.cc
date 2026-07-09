#include "../render.h"
#include "raylib.h"

#include <functional>

using namespace common::type;
using std::function;

namespace engine
{
    Render::Render()  { }
    Render::~Render() { }

    static Color RGB32_TO_COLOR(u32 color) {
        return {
            .r = (u8)((color >> 24) & 0xFF),
            .g = (u8)((color >> 16) & 0xFF),
            .b = (u8)((color >> 8) & 0xFF),
            .a = (u8)(color & 0xFF)
        };
    }

    void Render::init(i32 width, i32 height, const c8 *title) {
        win_stats.height = height;
        win_stats.width  = width;
        win_stats.close  = false;

        InitWindow(width, height, title);
    }

    bool Render::win_shoud_close() {
         return WindowShouldClose();
    }

    void Render::begin_frame() {
        BeginDrawing();
    }

    void Render::end_frame() {
        EndDrawing();
    }

    void Render::clear_frame(uint32_t rgb32) {
        ClearBackground(RGB32_TO_COLOR(rgb32));
    }

    void Render::draw_text(const c8 *msg, i32 posx, i32 posy, i32 font_size, u32 color) {
        Color c = RGB32_TO_COLOR(color);
        DrawText(msg, posx, posy, font_size, c);
    }

    i32 Render::get_render_text_width(const c8 *text, i32 font_size) {
        return MeasureText(text, font_size);
    }


    void Render::step(function<void()> draw_frame) { }
}
