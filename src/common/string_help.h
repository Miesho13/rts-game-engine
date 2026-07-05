#ifndef __STRING_HELP__ 
#define __STRING_HELP__ 

#include "./result.h"

#include "./type.h"
using namespace common::type;

#include <string_view>


using std::string;
using std::string_view;
using common::Result;

namespace common {
    Ok<f32> to_f32(std::string_view s);

    string get_line(string &input);
    string_view get_line(string_view &input);
    void skip_line(string &input);
    void skip_line(string_view &input);
    string_view get_word(string_view &input, c8 seperator = ' ');
    void skip_word(string_view &input, c8 seperator = ' ');
}

#endif // __STRING_HELP__ 
