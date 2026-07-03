#include "./file.h"
#include "./type.h"

#include <fstream>

using namespace common::type;

using std::ifstream;
using std::ios;
using std::string_view;

namespace common {
    void skip_line(string &input) {
        size_t pos = input.find('\n');
        if (pos == string::npos) {
            input.clear();
        }
        input = input.substr(pos + 1);
    }

    string get_line(string &input) {
        size_t pos = input.find('\n');

        if (pos == string::npos) {
            string result = input;
            input.clear();
            return result;
        }

        string result = input.substr(0, pos);
        input = input.substr(pos + 1);

        return result;
    }

    string read_file_to_string(string_view path) {
        ifstream file(path.data(), ios::ate | ios::binary);

        size_t size = file.tellg();
        file.seekg(0);
        string buffer(size, ' ');
        file.read(&buffer[0], size);
        file.close();

        return buffer;
    }

    string_view get_word(string_view &input, c8 seperator) {
        u32 len = input.size();

        for (u32 i = 0; i < len; i++) {
            if (input[i] == seperator) { 
                return input.substr(0, i);
            }
        }

        return input;
    }

    void skip_word(string_view &input, c8 seperator) {
        u32 len = input.size();

        for (u32 i = 0; i < len; i++) {
            if (input[i] == seperator) { 
                input = input.substr(i + 1);
                return;
            }
        }

        input = string_view();
    }

    void skip_line(string_view &input) {
        u32 len = input.size();

        for (u32 i = 0; i < len; ++i) {
            if (input[i] == '\n') {
                input = input.substr(i + 1);
                return;
            }
        }

        input = std::string_view();
    }

    string_view get_line(string_view &input) {
        u32 len = input.size();

        for (u32 i = 0; i < len; ++i) {
            if (input[i] == '\n') {
                string_view line = input.substr(0, i);
                input = input.substr(i + 1);
                return line;
            }
        }

        string_view line = input;
        input = string_view();

        return line;
    }
}
