### Board specific config
MCU		= atmega328p
CPU_SPEED	= 16000000UL

### Build flags for all targets 
CF_ALL		= -Wall -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os
LF_ALL		=
LL_ALL		=
AF_ALL		= rcs
UP_ALL		= -V -F -p m328p -c arduino -b 115200 -P$(ARDUINO_PORT)


### Build tools
CC		= avr-gcc
AR		= avr-ar
OC		= avr-objcopy
AVRDUDE		= avrdude
COMP		= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK		= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_LGT) $(LL_ALL)
COMPLINK	= $(CC) $(CF_ALL) $(CF_TGT) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
OBJCPY		= $(OC) $(OC_ALL) $(OC_TGT) $< $@
ARCH		= $(AR) $(AF_ALL) $@ $^
UPLOAD		= $(AVRDUDE) $(UP_ALL)

### global variables

ARDUINO_CORE	= $(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT	= $(ARDUINO_DIR)/hardware/arduino/variants/standard

ARDUINO_PORT	= /dev/ttyACM4
TGT_UP		= src/chic.hex

### Standard parts
include Rules.mk
