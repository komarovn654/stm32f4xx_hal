cmake_minimum_required(VERSION 3.27.1)

project(system_lib)

set(PROJECT_HOST_UTEST      "sl_ut_host")
set(PROJECT_TARGET_UTEST    "sl_ut_target")
set(PROJECT_TARGET_SH_UTEST "sl_ut_target_sh")

set(COMMON_SOURCES 
    src/hal_system.c
    src/hal_system_systick.c
    utest/hal_system_systick_test.cpp
    utest/hal_system_test.cpp
    utest/hal_system_utmain.cpp
)
set(TARGET_SOURCES ../core/interrupts.c ../core/startup.c)

set(COMMON_INCLUDES
    inc 
    ../core
    ../../third_party/CMSIS_5/CMSIS/Core/Include
    ../../third_party/cpputest/include/CppUTest
    ../../third_party/cpputest/include/CppUTestExt
)

# Utest host executable
if (CMAKE_BUILD_TYPE STREQUAL UTEST_HOST)
    add_executable(${PROJECT_HOST_UTEST} ${COMMON_SOURCES})
    target_include_directories(${PROJECT_HOST_UTEST} PRIVATE ${COMMON_INCLUDES})
    target_link_directories(${PROJECT_HOST_UTEST} PRIVATE ../../third_party/cpputest/cpputest_build/lib)
    target_link_libraries(${PROJECT_HOST_UTEST} CppUTest)
    set_target_properties(${PROJECT_HOST_UTEST} PROPERTIES COMPILE_FLAGS "-D UTEST_HOST=1")
endif()

# Utest target executable
if (CMAKE_BUILD_TYPE STREQUAL UTEST_TARGET)
    add_executable(${PROJECT_TARGET_UTEST} ${COMMON_SOURCES} ${TARGET_SOURCES})
    target_include_directories(${PROJECT_TARGET_UTEST} PRIVATE ${COMMON_INCLUDES})
    target_link_directories(${PROJECT_TARGET_UTEST} PRIVATE ../../tools/cpputest/out/CppUTest)
    target_link_libraries(${PROJECT_TARGET_UTEST} CppUTest)
    set_target_properties(${PROJECT_TARGET_UTEST} PROPERTIES 
    LINK_FLAGS "--specs=nano.specs --specs=nosys.specs"
    COMPILE_FLAGS "-D UTEST_TARGET=1"
    )

    # Utest target with semihosting executable
    add_executable(${PROJECT_TARGET_SH_UTEST} ${COMMON_SOURCES} ${TARGET_SOURCES})
    target_include_directories(${PROJECT_TARGET_SH_UTEST} PRIVATE ${COMMON_INCLUDES})
    target_link_directories(${PROJECT_TARGET_SH_UTEST} PRIVATE ../../tools/cpputest/out/CppUTest)
    target_link_libraries(${PROJECT_TARGET_SH_UTEST} CppUTest)
    set_target_properties(${PROJECT_TARGET_SH_UTEST} PROPERTIES 
    LINK_FLAGS "--specs=rdimon.specs"
    COMPILE_FLAGS "-D UTEST_TARGET=1"
    )
endif()
