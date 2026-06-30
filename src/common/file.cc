#include "./file.h"

#include <fstream>

using std::ifstream;
using std::ios;

namespace common {
    string skip_line(string &input) {
        size_t pos = input.find('\n');
        if (pos == string::npos) {
            input.clear();
            return "";
        }
        input = input.substr(pos + 1);
        return input;
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
}
