cmake_minimum_required(VERSION 3.27.1)

project(system_lib)
set(PROJECT_SOURCES 
    src/hal_system.c
    src/hal_system_systick.c
    utest/hal_system_systick_test.cpp
    utest/hal_system_test.cpp
    utest/hal_system_utmain.cpp
)

set(PROJECT_INCLUDES
        inc 
        ../core
        ../../third_party/CMSIS_5/CMSIS/Core/Include
        ../../third_party/cpputest/include/CppUTest
        ../../third_party/cpputest/include/CppUTestExt
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDES})

if (CMAKE_BUILD_TYPE STREQUAL UTEST_TARGET)
    # string(APPEND PROJECT_SOURCES " ../core/startup.c")
    # string(APPEND PROJECT_INCLUDES " ../../tools/cpputest/out/CppUTest")

    target_sources(${PROJECT_NAME} PRIVATE ../core/startup.c)
    target_link_directories(${PROJECT_NAME} PRIVATE ../../tools/cpputest/out/CppUTest)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "--specs=nano.specs --specs=nosys.specs")

    add_executable(${PROJECT_NAME}_sh ${PROJECT_SOURCES} ../core/startup.c)
    target_include_directories(${PROJECT_NAME}_sh PRIVATE ${PROJECT_INCLUDES})
    target_link_directories(${PROJECT_NAME}_sh PRIVATE ../../tools/cpputest/out/CppUTest)
    target_link_libraries(${PROJECT_NAME}_sh CppUTest)
    set_target_properties(${PROJECT_NAME}_sh PROPERTIES LINK_FLAGS "--specs=rdimon.specs")
elseif (CMAKE_BUILD_TYPE STREQUAL UTEST_HOST)
    target_link_directories(${PROJECT_NAME} PRIVATE ../../third_party/cpputest/cpputest_build/lib)
endif()

target_link_libraries(${PROJECT_NAME} CppUTest)
