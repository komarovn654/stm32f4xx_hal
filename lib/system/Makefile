CXX = g++
CC = gcc

#Paths
CPPUTEST_PATH = $(CURDIR)/../../third_party/cpputest

#Include paths
INC = -I$(CPPUTEST_PATH)/include/CppUTest \
	-I$(CPPUTEST_PATH)/cpputest/include/CppUTestExt \
	-I$(CPPUTEST_PATH)/cpputest/include/Platforms \
	-I/Users/nikolajkomarov/stm32f4xx_hal/third_party/CMSIS_5/CMSIS/Core/Include \
	-I$(CURDIR)/../core/ \
	-I./inc

#Source	files
SRC_CPP = $(wildcard utest/*_test.cpp utest/*_utmain.cpp)
SRC_C = $(wildcard src/*.c)

#Object files
# OBJ = hal_system_tests.o hal_system_systick_test.o
OBJ_CPP = $(patsubst utest/%.cpp, %.o, $(SRC_CPP))
OBJ_C = $(patsubst src/%.c, %.o, $(SRC_C))

UTEST_OBJ = $(wildcard $(CPPUTEST_PATH)/cpputest_build/src/CppUTest/*.o)
UTEST_EXT_OBJ = $(wildcard $(CPPUTEST_PATH)/cpputest_build/src/CppUTestExt/*.o)
PLATFORM_OBJ = $(wildcard $(CPPUTEST_PATH)/cpputest_build/src/Platforms/Gcc/*.o)

.SILENT:run compile

run: compile
	./test.out
	rm *.o *.out

compile:
	$(CXX) -c $(INC) $(SRC_CPP)
	$(CC) -c $(INC) $(SRC_C)
	$(CXX) -o test.out $(OBJ_CPP) $(OBJ_C) $(UTEST_OBJ) $(UTEST_EXT_OBJ) $(PLATFORM_OBJ)

clean:
	rm *.o