cmake_minimum_required(VERSION 3.27.1)

project(arm-none-eabi_cpputest)

SET(PROJECT_SOURCE_DIR /Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest)
set(CPP_PLATFORM armcc)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/CppUTest CppUTest)
target_sources(CppUTest
	PRIVATE
		${PROJECT_SOURCE_DIR}/src/Platforms/armcc/UtestPlatform.cpp
)

