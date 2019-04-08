#.o files
SRC  = project_main.o state_machine.o timer.o switches.o buzzer.o led.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS = ../demos/lib/libTimer.a -L/opt/ti/msp430_gcc/include

# Switch the compiler 
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: arch1_project2.elf 

# Additional rules for files
arch1_project2.elf: ${SRC} ../demos/lib/libTimer.a
	${CC} $(CFLAGS) $(LDFLAGS) -o $@ $^

load: arch1_project2.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf
