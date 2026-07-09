#ifndef __STRING_HELP__ 
#define __STRING_HELP__ 

#include "./result.h"
#include "./type.h"

#include <string_view>
#include <string>

using namespace common::type;

using std::string_view;
using std::string;

namespace common {
    Ok<f32> to_f32(std::string_view s);
    void skip_line(string &input);
    string get_line(string &input);
    string_view get_word(string_view &input, c8 seperator);
    void skip_word(string_view &input, c8 seperator);
    void skip_line(string_view &input);
    string_view get_line(string_view &input);
}

#endif // __STRING_HELP__ 
