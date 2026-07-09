#ifndef __LOG__
#define __LOG__

#include "type.h"
#include <string>
#include <mutex>
#include <string>
#include <string_view>
#include <format>

using std::string_view;

namespace common {
    using printer_func = void (*)(std::string_view);

    inline void default_print(std::string_view text) {
        std::fwrite(text.data(), 1, text.size(), stdout);
        std::fputc('\n', stdout);
    }

    // Globalny stan backendu + mutex dla bezpieczeństwa wątkowego.
    inline printer_func g_printer = default_print;
    inline std::mutex g_printer_mutex;

    inline void set_printer(printer_func func) {
        std::scoped_lock lock(g_printer_mutex);
        g_printer = (func ? func : default_print);
    }

    inline printer_func get_printer() {
        std::scoped_lock lock(g_printer_mutex);
        return g_printer;
    }

    template <typename... Args>
    void log(std::format_string<Args...> fmt, Args&&... args) {
        std::string msg = std::format(fmt, std::forward<Args>(args)...);

        printer_func out;
        {
            std::scoped_lock lock(g_printer_mutex);
            out = g_printer;
        }

        out(msg);
    }
}

#define log_err(fmt, ...) ::common::log("[err] " fmt, ##__VA_ARGS__)
#define log_war(fmt, ...) ::common::log("[war] " fmt, ##__VA_ARGS__)
#define log_inf(fmt, ...) ::common::log("[inf] " fmt, ##__VA_ARGS__)

#endif // __LOG__
