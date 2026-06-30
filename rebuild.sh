#!/bin/sh

rm -rf build
cmake -S . -B build -DBUILD_SPEC_PLATFORM=RAYLIB_LINUX 
cd build
make -j15
