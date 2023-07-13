CC= arm-none-eabi-gcc
MACHINE= cortex-m4
CFLAGS= -c -g -mthumb -mcpu=$(MACHINE) -std=gnu11 -O0
LDFLAGS= -nostdlib -T stm32f407_ls.ld -Wl,-Map=application.map
INC=

all: main.o startup.o application.elf 

main.o: main.c
	$(CC) $(CFLAGS) $(INC) $^ -o $@

startup.o: startup.c
	$(CC) $(CFLAGS) $(INC) $^ -o $@

application.elf: main.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@

application.map: application.elf

clean:
	rm *.o *.out *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg -c "program application.elf verify exit reset"
