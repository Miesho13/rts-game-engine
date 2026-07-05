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
}


#endif // __COMMON_FILE__

