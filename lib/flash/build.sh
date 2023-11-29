#! /bin/sh

ROOT_PATH="/Users/nikolajkomarov/stm32f4xx_hal"
BIN_NAME_LIB="libflash.a"

mkdir -p out out/build_lib out/bin

# cmake -S . -B out/build_lib -DCMAKE_TOOLCHAIN_FILE:PATH="../../toolchain-arm-none-eabi.cmake"
cmake -S . -B out/build_lib

cd $ROOT_PATH/lib/flash/out/build_lib && make && cp $BIN_NAME_LIB ../bin/$BIN_NAME_LIB
