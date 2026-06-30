#include "model.h"
#include "common/file.h"

#include <string>
#include <string_view>
#include <print>

using std::vector;
using std::string;
using common::read_file_to_string;
using std::println;

namespace model {

// v -0.086914 0.777547 0.400041
    static i32 get_vertex(string line, Vertex &v) {
        std::vector<string> value(3);
        c8 *ptr = line.data();
        i32 value_idx = 0;
        i32 line_idx = 0;
        for (;;) {
            if (*ptr == '\n') { break; }
            if (*ptr == 'v')  { continue; }

            if (*ptr == ' ' && *(ptr - 1) == 'v') { 
                continue; 
            }
            else if (*ptr == ' ') {
                value_idx++;
            }

            value.at(value_idx) += *ptr;
            line_idx++;
            ptr++;
        }

        v.x = atof(value[0].data());
        v.y = atof(value[1].data());
        v.z = atof(value[2].data());

        println("v {} {} {}", v.x, v.y, v.z);
        return line_idx; 
    }


    static void parse_obj(string &buffer, vector<Vertex> &vertices, vector<Faces> &faces) {
        buffer = common::skip_line(buffer);
        buffer = common::skip_line(buffer);
        buffer = common::skip_line(buffer);
        buffer = common::skip_line(buffer);

        c8 *ptr  = buffer.data();
        u32 size = buffer.size();

        println("{}", *ptr);

        while (*ptr != '\0') {
            switch (*ptr) {
                case 'v': {
                    Vertex v;
                    i32 ret = get_vertex(ptr, v);
                    ptr += ret + 1;
                } break;

                default: {
                    ptr++;
                }
            }
        }
    }

    Obj::Obj(string_view path) {
        string file_out = read_file_to_string(path);

        parse_obj(file_out,
                  vertices,
                  faces);
    }
}
