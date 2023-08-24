cmake_minimum_required(VERSION 3.27.1)

project(system_lib)

add_executable(${PROJECT_NAME}
    src/hal_system.c
    src/hal_system_systick.c
    utest/hal_system_systick_test.cpp
    utest/hal_system_test.cpp
    utest/hal_system_utmain.cpp
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        inc 
        ../core
        ../../third_party/CMSIS_5/CMSIS/Core/Include
        ../../third_party/cpputest/include/CppUTest
        ../../third_party/cpputest/include/CppUTestExt
)

if (CMAKE_BUILD_TYPE STREQUAL UTEST_TARGET)
    target_sources(${PROJECT_NAME} PRIVATE ../core/startup.c)
    target_link_directories(${PROJECT_NAME} PRIVATE ../../tools/cpputest/out/CppUTest)
elseif (CMAKE_BUILD_TYPE STREQUAL UTEST_HOST)
    target_link_directories(${PROJECT_NAME} PRIVATE ../../third_party/cpputest/cpputest_build/lib)
endif()

target_link_libraries(${PROJECT_NAME} CppUTest)
