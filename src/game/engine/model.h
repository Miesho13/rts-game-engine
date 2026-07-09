#ifndef _MODEL_
#define _MODEL_

#include "common/type.h" 

#include <string_view>
#include <vector>

using namespace common::type;
using std::string_view;
using std::vector;

namespace engine {
    struct Vertex   { f32 x; f32 y; f32 z; };
    struct Faces    { i32 x; i32 y; i32 z; };
    struct Triangle { Vertex v1; Vertex v2; Vertex v3; };

    class Obj {
        public:
            Obj(string_view path);

        private:
            vector<Vertex> vertices;
            vector<Faces>  faces;
    };

    struct Model;
    Model load_model(string_view path);
}

#endif // _MODEL_
 
