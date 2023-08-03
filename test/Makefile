CXX= arm-none-eabi-g++
CC= arm-none-eabi-gcc

CPPUTEST_PATH = $(CURDIR)/../third_party/cpputest

MACHINE= cortex-m4
CFLAGS= -c -g -mthumb -mcpu=$(MACHINE) -O0
LDFLAGS= --specs=nano.sepcs -T stm32f407_ls.ld -Wl,-Map=application.map
INC= -I$(CPPUTEST_PATH)/include/CppUTest

UTEST_OBJ = -L/Users/nikolajkomarov/stm32f4xx_hal/third_party/cpputest/cpputest_build/lib -lCppUTest -lCppUTestExt

all: main.o startup.o application.elf 

main.o: main.cpp
	$(CXX) $(CFLAGS) $(INC) $^ -o $@

startup.o: startup.c
	$(CC) $(CFLAGS) $(INC) $^ -o $@

application.elf: main.o startup.o
	$(CXX) $(LDFLAGS) $^ $(UTEST_OBJ) -o $@

application.map: application.elf

clean:
	rm *.o *.out *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg -c "program application.elf verify exit reset"
