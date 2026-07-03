#include "model.h"
#include "common/file.h"
#include "common/macro.h"

#include <string>
#include <string_view>
#include <print>

using std::vector;
using std::string;
using common::read_file_to_string;
using std::println;

namespace model {

// v -0.086914 0.777547 0.400041

    Obj::Obj(string_view path) {
        string file_out = read_file_to_string(path);
        string_view file_out_ptr = file_out;

        while (1) {
            if (file_out_ptr.size() == 0) {
                println("end of file");
                break;
            }

            if (common::get_word(file_out_ptr) == "v") {
                string_view line = common::get_line(file_out_ptr);
                println("{}", line);
                continue;
            }

            if (common::get_word(file_out_ptr) == "vn") {
                string_view line = common::get_line(file_out_ptr);
                println("{}", line);
                continue;
            }

            if (common::get_word(file_out_ptr) == "vt") {
                string_view line = common::get_line(file_out_ptr);
                println("{}", line);
                continue;
            }

            if (common::get_word(file_out_ptr) == "f") {
                string_view line = common::get_line(file_out_ptr);
                println("{}", line);
                continue;
            }

            common::skip_line(file_out_ptr);
        }
    }
}
