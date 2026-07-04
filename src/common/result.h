#ifndef __RESULT__
#define __RESULT__

namespace common {
    template<typename Ok, typename Err>
    struct Result {
        Ok ok;
        Err err;
        bool is_ok;
    };

    template<typename ok_type>
    struct Ok {
        ok_type ok;
        bool is_ok;
    };
}

#endif // __RESULT__

