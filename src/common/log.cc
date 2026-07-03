#include "log.h"
#include "macro.h"
#include <cstdarg> 

namespace common {
    void _deafult_print(string_view format, ...) {
        va_list args;
        va_start(args, format);

        std::vfprintf(stdout, format.data(), args);

        va_end(args);
    }

    static printer_func _print = _deafult_print;

    void set_printer(printer_func func) {
        _print = func;
    }

    printer_func get_printer() {
        return _print; 
    }

    void log(string_view format, ...) {
        va_list args;
        va_start(args, format);

        _print(format, args);

        va_end(args);
    }
}
