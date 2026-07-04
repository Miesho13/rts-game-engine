#ifndef __COMMON_FILE__
#define __COMMON_FILE__

#include "./type.h"
#include "./result.h"

#include <string>
#include <string_view>

using namespace common::type;
using std::string;
using std::string_view;
using common::Result;

namespace common {
    Ok<string> read_file_to_string(string_view path);
    string get_line(string &input);
    string_view get_line(string_view &input);
    void skip_line(string &input);
    void skip_line(string_view &input);
    string_view get_word(string_view &input, c8 seperator = ' ');
    void skip_word(string_view &input, c8 seperator = ' ');
}


#endif // __COMMON_FILE__

