#! /bin/sh

ROOT_PATH="/Users/nikolajkomarov/stm32f4xx_hal"
BIN_NAME_HOST="rcc_ut_host"
BIN_NAME_TARGET="rcc_ut_target"
BIN_NAME_TARGET_SH="rcc_ut_target_sh"

mkdir -p out out/build_utest_host out/build_utest_target out/bin

cmake -S . -B out/build_utest_host -DCMAKE_BUILD_TYPE=UTEST_HOST
cmake -S . -B out/build_utest_target -DCMAKE_BUILD_TYPE=UTEST_TARGET -DCMAKE_TOOLCHAIN_FILE:PATH="../../toolchain-arm-none-eabi.cmake"

cd $ROOT_PATH/lib/rcc/out/build_utest_host && make && cp $BIN_NAME_HOST ../bin/$BIN_NAME_HOST.a
cd $ROOT_PATH/lib/rcc/out/build_utest_target && make && cp $BIN_NAME_TARGET ../bin/$BIN_NAME_TARGET.elf && cp $BIN_NAME_TARGET_SH ../bin/$BIN_NAME_TARGET_SH.elf
