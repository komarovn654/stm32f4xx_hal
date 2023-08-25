#! /bin/sh

ROOT_PATH="/Users/nikolajkomarov/stm32f4xx_hal"
BIN_NAME="system_lib"
BIN_NAME_SH="system_lib_sh"

mkdir -p out out/build_utest_host out/build_utest_target out/bin

cmake -S . -B out/build_utest_host -DCMAKE_BUILD_TYPE=UTEST_HOST
cmake -S . -B out/build_utest_target -DCMAKE_BUILD_TYPE=UTEST_TARGET -DCMAKE_TOOLCHAIN_FILE:PATH="../../toolchain-arm-none-eabi.cmake"

cd $ROOT_PATH/lib/system/out/build_utest_host && make && cp $BIN_NAME ../bin/$BIN_NAME.a
cd $ROOT_PATH/lib/system/out/build_utest_target && make && cp $BIN_NAME ../bin/$BIN_NAME.elf && cp $BIN_NAME_SH ../bin/$BIN_NAME_SH.elf
