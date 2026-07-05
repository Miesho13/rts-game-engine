#include "./string_help.h"
#include "result.h"

#include <charconv>
#include <string>
#include <string_view>

using std::string;
using std::string_view;

namespace common {
    Ok<f32> to_f32(std::string_view s) {
        f32 out = 0.f; 
        auto [ptr, ec] = std::from_chars(s.begin(), s.end(), out);

        if (ec == std::errc()) {
            return {out, false};
        }

        return {out, true};
    }

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
                return input.substr(0, i);
            }
        }

        return input;
    }
}
