#include "../model.h"
#include "raylib.h"

namespace engine {

    struct Model { 
        ::Model model; 
    };

    Model load_model(string_view path) {
        ::Model load = LoadModel(path.data());
        return { .model = load };
    }
}
