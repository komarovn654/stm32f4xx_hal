CXX = g++
CC = gcc
INC = -I/Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/include/CppUTest \
	-I/Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/include/CppUTestExt \
	-I/Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/include/Platforms \
	-I./inc
SRCCPP = $(wildcard utests/*_test.cpp utests/*_tests.cpp)
SRCC = $(wildcard src/*.c)
OBJ = hal_system_nstimer_test.o hal_system_nstimer.o hal_system_test.o hal_system_tests.o hal_system.o

libs = $(wildcard /Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/cpputest_build/src/CppUTest/*.o)
libsExt = $(wildcard /Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/cpputest_build/src/CppUTestExt/*.o)
platform = $(wildcard /Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/cpputest_build/src/Platforms/Gcc/*.o)

.SILENT:run compile link

all: run

run: link
	./test.out
	rm *.o *.out

compile:
	$(CXX) -c $(INC) $(SRCCPP)
	$(CC) -c $(INC) $(SRCC)

link: compile
	$(CXX) -o test.out $(OBJ) $(libs) $(libsExt) $(platform)

run_main: compile_main
	./a.out

compile_main:
	$(CC) main.c src/hal_system_nstimer.c $(INC)

clean:
	rm *.o