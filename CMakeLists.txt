cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(rtd-engine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# the good idea will be change this to some more platfomr
# independed cmake command
set(CMAKE_CXX_FLAGS "-O0 -Wall -Wextra -Wpedantic -g3")
set(CMAKE_C_FLAGS   "-O0 -Wall -Wextra -Wpedantic -g3")

include(cmake/options.cmake)
include(cmake/platform_options.cmake)

include_directories(src)
add_subdirectory(extra/raylib)
include_directories(extra/raylib/src)

add_subdirectory(src/game)
include_directories(src/game)

add_subdirectory(src/common)
include_directories(src/common)


set(GAME_NAME rts_game)
add_executable(${GAME_NAME}
    $<TARGET_OBJECTS:game_obj>
    $<TARGET_OBJECTS:common>
)

target_link_libraries(
    ${GAME_NAME} PUBLIC
    raylib
    m
)
