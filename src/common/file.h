#ifndef __COMMON_FILE__
#define __COMMON_FILE__

#include <string>
#include <string_view>

using std::string;
using std::string_view;

namespace common {
    string read_file_to_string(string_view path);
    string skip_line(string &input);
    string get_line(string &input);
}


#endif // __COMMON_FILE__

