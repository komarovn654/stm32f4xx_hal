CXX = arm-none-eabi-g++
CC= arm-none-eabi-gcc

ROOT_PATH = $(CURDIR)/../..
CMSIS_PATH = $(ROOT_PATH)/third_party/CMSIS_5
CPPUTEST_PATH = $(ROOT_PATH)/third_party/cpputest
CORE_PATH = $(ROOT_PATH)/lib/core

# utest sources
CPPUTEST_OBJS_PATH = $(ROOT_PATH)/tools/cpputest
UTEST_SRC = $(wildcard $(CPPUTEST_PATH)/src/CppUTest/*.cpp)
UTESTEXT_SRC = $(wildcard $(CPPUTEST_PATH)/src/CppUTestExt/*.cpp)
PLATFORM_SRC = $(wildcard $(CPPUTEST_PATH)/src/Platforms/armcc/*.cpp)

UTEST_OBJS_NAME = $(patsubst %.cpp, %.o, $(notdir $(UTEST_SRC) $(UTESTEXT_SRC) $(PLATFORM_SRC)))
UTEST_OBJS = $(addprefix $(CPPUTEST_OBJS_PATH)/obj/, $(UTEST_OBJS_NAME))

UTEST_HOST = $(wildcard $(CPPUTEST_PATH)/cpputest_build/src/CppUTest/*.o $(CPPUTEST_PATH)/cpputest_build/src/CppUTestExt/*.o $(CPPUTEST_PATH)/cpputest_build/src/Platforms/Gcc/*.o)

#Source	files
SRC_CPP = $(wildcard utest/*.cpp)
SRC_C = $(wildcard src/*.c)

#Object files
# OBJ = hal_system_tests.o hal_system_systick_test.o
OBJ_CPP = $(patsubst utest/%.cpp, %.o, $(SRC_CPP))
OBJ_C = $(patsubst src/%.c, %.o, $(SRC_C))

# compiler flags
MACHINE = -mthumb -mcpu=cortex-m4
CFLAGS = -c -g3 $(MACHINE) -O0
CXXFLAGS = -c -g3 $(MACHINE) -O0
# EXTRA_FLAGS = -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -Wconversion -Wpadded
# STACK_FLAGS = -fstack-usage -Wstack-usage=
LDFLAGS = -specs=nano.specs -specs=nosys.specs $(MACHINE) -T ../../stm32f407_ls.ld -Wl,-Map=application.map
LDFLAGS_SH = $(MACHINE) -specs=rdimon.specs -T ../../stm32f407_ls.ld

INC = -I$(CPPUTEST_PATH)/include/CppUTest \
	-I$(CPPUTEST_PATH)/cpputest/include/CppUTestExt \
	-I$(CPPUTEST_PATH)/cpputest/include/Platforms \
	-I$(CMSIS_PATH)/CMSIS/Core/Include \
	-I$(CORE_PATH) \
	-I$(CURDIR)/inc

$(UTEST_OBJS):
	cd $(ROOT_PATH)/tools/cpputest && make all

all: application.elf

compile: $(UTEST_OBJS) $(OBJ_C) $(OBJ_CPP) startup.o

$(OBJ_C): $(SRC_C)
	$(CC) $(CFLAGS) $(INC) $^

$(OBJ_CPP): $(SRC_CPP)
	$(CXX) $(CXXFLAGS) $(INC) $^	

startup.o: $(CORE_PATH)/startup.c
	$(CC) $(CFLAGS) $(INC) $^ -o $@

application.elf: compile
	$(CXX) $(LDFLAGS) $(UTEST_OBJS) $(OBJ_C) $(OBJ_CPP) startup.o -o $@

app.elf: compile
	$(CXX) $(LDFLAGS_SH) $(UTEST_OBJS) $(OBJ_C) $(OBJ_CPP) startup.o -o $@	

application:
	gcc -c $(SRC_C) $(INC)
	g++ -c $(SRC_CPP) $(INC)
	g++ -o app $(OBJ_CPP) $(OBJ_C) $(UTEST_HOST)

application.map: application.elf

clean:
	rm -rf *.o *.out *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg -c "program application.elf verify exit reset"