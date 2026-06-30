cmake_minimum_required(VERSION 3.28)

add_library(
    game_obj OBJECT
    main.cc
    game.cc
    engine/render.cc
    scene/menu.cc
    model.cc
)
