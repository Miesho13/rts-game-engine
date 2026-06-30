#ifndef __COMMON_MACRO__
#define __COMMON_MACRO__

// Because C++ developers are scared of C-style casts for some reason,
// they need compiler checks to know what they're doing.
#define CAST(val, type) static_cast<type>(val)
// C-style cast but with long syntax.
#define CAST_PTR(val, type)  reinterprete_cast<type>(val)
//  
#define UNUSED(val) (void)val;

#endif // __CAST__
