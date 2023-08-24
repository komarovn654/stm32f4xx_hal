#! /bin/sh

cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE:PATH="../../toolchain-arm-none-eabi.cmake"
cd build && make