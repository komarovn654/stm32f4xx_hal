cmake_minimum_required(VERSION 3.27.1)

project(stm32f4xx VERSION 0.1)

add_compile_options(
        -Werror -Wall -Wextra -Wshadow -Wundef -fno-common -fstack-usage -Wconversion -Os
)

include(ctest)
# message(BUILD_TESTING="${BUILD_TESTING}")

add_subdirectory(lib/system)
add_subdirectory(lib/rcc)
