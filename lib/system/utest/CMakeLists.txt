cmake_minimum_required(VERSION 3.27.1)

project(system_lib_utest)

set(TEST_SOURCES
    hal_system_mstick_test.cpp
    hal_system_systick_test.cpp
    hal_system_test.cpp
    hal_system_utmain.cpp
)

set(TEST_INCLUDES
    ../inc 
    ../../core
    ../../../third_party/CMSIS_5/CMSIS/Core/Include
    ../../../third_party/cpputest/include/CppUTest
    ../../../third_party/cpputest/include/CppUTestExt
)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${TEST_INCLUDES})

if(CMAKE_MACHINE_TYPE STREQUAL Host)
    target_link_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/../
        ../../../third_party/cpputest/cpputest_build/lib
    )
elseif(CMAKE_MACHINE_TYPE STREQUAL Target)
    target_link_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/../
        ../../../tools/cpputest/out/CppUTest
    )
else()
endif()

target_link_libraries(${PROJECT_NAME} CppUTest system_lib)
    
add_test(NAME sys_unittest_host COMMAND ${PROJECT_NAME})
