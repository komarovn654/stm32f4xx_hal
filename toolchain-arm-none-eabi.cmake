set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN arm-none-eabi)
set(TOOLCHAIN_PREFIX "/Applications/ARM")

set(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_PREFIX}/bin)
set(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_PREFIX}/lib)

set(CMAKE_C_COMPILER ${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN}-gcc${TOOLCHAIN_EXT} CACHE INTERNAL "C Compiler")
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN}-g++${TOOLCHAIN_EXT} CACHE INTERNAL "C++ Compiler")

set(CMAKE_C_FLAGS "-g3 -mthumb -mcpu=cortex-m4 -O0" CACHE INTERNAL "C Compiler options")
set(CMAKE_CXX_FLAGS "-g3 -mthumb -mcpu=cortex-m4 -O0" CACHE INTERNAL "C++ Compiler options")
set(CMAKE_EXE_LINKER_FLAGS "--specs=nano.specs --specs=nosys.specs -mthumb -mcpu=cortex-m4 -T /Users/nikolajkomarov/stm32f4xx_hal/stm32f407_ls.ld -Wl,-Map=application.map" CACHE INTERNAL "Linker options")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
