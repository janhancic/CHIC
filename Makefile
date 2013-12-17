### Board specific config
MCU			=atmega328p
CPU_SPEED	=16000000UL

### Build flags for all targets 
CF_ALL		= -Wall -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os
LF_ALL		=
LL_ALL		=
UP_ALL		= -V -F -p m328p -c arduino -b 115200 -P$(PORT)


### Build tools
CC			= avr-gcc
AR			= avr-ar
AVRDUDE		= avrdude
COMP		= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK		= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_LGT) $(LL_ALL)
COMPLINK	= $(CC) $(CF_ALL) $(CF_TGT) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
UPLOAD		= $(AVRDUDE) $(UP_ALL)


TGT_UP = chic.hex	
### Standard parts
include Rules.mk

ARDUINO_CORE=$(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT=$(ARDUINO_DIR)/hardware/arduino/variants/standard



BOARD=arduino
LIBNAME=lib$(BOARD).a

PORT=/dev/cu.usbmodemfd131

OBJECTS=wiring.o wiring_analog.o wiring_digital.o \
                   wiring_pulse.o wiring_shift.o HardwareSerial.o Print.o   \
                   Tone.o WMath.o WString.o WInterrupts.o

$(TGT_UP) : chic.elf
	avr-objcopy -O ihex $< $@
	
chic.elf : src/chic.cpp $(LIBNAME)
#	$(CC) $(CF_ALL) $^ -o $@ -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -Wall
	$(COMPLINK) -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) $(LIBNAME)

$(LIBNAME): $(OBJECTS)
	avr-ar rcs $(LIBNAME) $^
	rm *.o

%.o : $(ARDUINO_CORE)/%.c
	$(COMP) -I$(ARDUINO_VARIANT)

%.o : $(ARDUINO_CORE)/%.cpp
	$(COMP) -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
	


#.PHONY : upload
#upload: chic.hex
#	avrdude -V -F -p m328p -c arduino -b 115200 -P$(PORT) -Uflash:w:chic.hex
#	$(UPLOAD) -Uflash:w:chic.hex 

clean:
	rm -f *.o *.elf *.a *.hex