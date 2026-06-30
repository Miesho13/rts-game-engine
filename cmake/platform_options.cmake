include(cmake/custom_func.cmake)

set(BUILD_SPEC_PLATFORM "" CACHE STRING "Choose platform: RAYLIB_LINUX or SDL2_LINUX")

if(BUILD_SPEC_PLATFORM STREQUAL "RAYLIB_LINUX")
    push_group_def(RAYLIB_LINUX_PLATFORM "Raylib linux platform" ON
        __RAYLIB_LINUX_PLATFORM_IMP
    )
elseif(BUILD_SPEC_PLATFORM STREQUAL "SDL2_LINUX")
    push_group_def(SDL2_LINUX_PLATFORM "SDL2 linux platform" ON
        __SDL2_LINUX_PLATFORM_IMP
    )
else()
    message(FATAL_ERROR "\nSet your -DBUILD_SPEC_PLATFORM=...\nTo get more information see cmake/custom_func.cmake\n")
endif()
