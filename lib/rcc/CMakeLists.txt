cmake_minimum_required(VERSION 3.27.1)

project(rcc_lib)

set(COMMON_SOURCES 
    src/hal_rcc.c
    src/hal_rcc_clocks.c
)
set(EXT_SOURCES ../core/startup.c)

if(CMAKE_MACHINE_TYPE STREQUAL Host)
    set(TARGET_SOURCES ${COMMON_SOURCES})
elseif(CMAKE_MACHINE_TYPE STREQUAL Target)
    set(TARGET_SOURCES ${COMMON_SOURCES} ${EXT_SOURCES})
else()
    set(TARGET_SOURCES ${COMMON_SOURCES})
endif()

set(COMMON_INCLUDES
    inc 
    ../core
    ../../third_party/CMSIS_5/CMSIS/Core/Include
)

add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDES})

if(BUILD_TESTING)
    add_subdirectory(utest)
endif()
