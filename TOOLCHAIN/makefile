cc = arm-none-eabi-gcc

cFLAGS = -c -mcpu=$(MACH) -std=gnu11 -mthumb  -Wall  -Wno-main

MACH = cortex-m3

LDFLAGS = -T STM32_F103C8T6_LS.ld -nostdlib -Wl,-Map=final.map

main.o : main.c
	$(cc) $(cFLAGS) $^ -o $@
	
RCC_program.o : RCC_program.c
	$(cc) $(cFLAGS) $^ -o $@
	
DIO_program.o : DIO_program.c
	$(cc) $(cFLAGS) $^ -o $@
	
SYSTICK_program.o : SYSTICK_program.c
	$(cc) $(cFLAGS) $^ -o $@

STM32_F103C8T6Startup.o : STM32_F103C8T6Startup.c 
	$(cc) $(cFLAGS) $^ -o $@

final.elf : main.o DIO_program.o STM32_F103C8T6Startup.o SYSTICK_program.o RCC_program.o 
	$(cc) $(LDFLAGS) $^ -o $@
	
all : main.o DIO_program.o STM32_F103C8T6Startup.o SYSTICK_program.o RCC_program.o final.elf
	
clean: 
	rm -rf *.o *.elf 

# Flash the program
load: final.elf
	openocd -f interface/stlink.cfg -f board/stm32f103c8_blue_pill.cfg \
	-c "transport select hla_swd" 