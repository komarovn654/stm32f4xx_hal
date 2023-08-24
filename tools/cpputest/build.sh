#! /bin/sh

cmake -S . -B out -DCMAKE_TOOLCHAIN_FILE:PATH="../../toolchain-arm-none-eabi.cmake"
cd out && make