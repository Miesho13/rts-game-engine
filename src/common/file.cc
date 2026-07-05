#include "./file.h"
#include "./result.h"

#include <fstream>

#include "./type.h"
using namespace common::type;

using std::ifstream;
using std::ios;
using std::string_view;

namespace common {
    Ok<string> read_file_to_string(string_view path) {
        ifstream file(path.data(), ios::ate | ios::binary);

        if (file.is_open() == false) {
            return {"", false};
        }

        size_t size = file.tellg();
        file.seekg(0);
        string buffer(size, ' ');
        file.read(&buffer[0], size);
        file.close();

        return {buffer, true};
    }
}
