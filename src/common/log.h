#ifndef __LOG__
#define __LOG__

#include "type.h"
#include <string>

using std::string_view;

namespace common {
    using printer_func = void (*)(string_view, ...);

    void set_printer(printer_func func);
    void log(string_view format, ...);
}

#define LOG_LEVEL (0)

#if LOG_LEVEL == 1
#   define LOG_INFO(format, ...)  (void) 
#   define LOG_DEBUG(format, ...) (void)
#   define LOG_TRACE(format, ...) (void)
#elif LOG_LEVEL == 2
#   define LOG_INFO(format, ...)  (void)
#   define LOG_DEBUG(format, ...) (void)
#   define LOG_TRACE(format, ...) (void)
#elif LOG_LEVEL == 3 
#   define LOG_INFO(format, ...)  (void)
#   define LOG_DEBUG(format, ...) (void)
#   define LOG_TRACE(format, ...) (void)
#else
#   define LOG_INFO(format, ...)  (void)
#   define LOG_DEBUG(format, ...) (void)
#   define LOG_TRACE(format, ...) (void)
#endif


#endif // __LOG__
