cmake_minimum_required(VERSION 3.27.1)

project(flash_lib)

set(PROJECT_LIB "flash")

set(COMMON_SOURCES 
    src/hal_flash.c
)

set(COMMON_INCLUDES
    inc 
    ../core
    ../../third_party/CMSIS_5/CMSIS/Core/Include
    ../../third_party/cpputest/include/CppUTest
    ../../third_party/cpputest/include/CppUTestExt
)

add_library(${PROJECT_LIB} STATIC ${COMMON_SOURCES} ${TARGET_SOURCES})
target_include_directories(${PROJECT_LIB} PRIVATE ${COMMON_INCLUDES})
# set_target_properties(${PROJECT_LIB} PROPERTIES LINK_FLAGS "--specs=nano.specs --specs=nosys.specs")
