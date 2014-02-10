### Board specific config
MCU			= atmega328p
CPU_SPEED	= 16000000UL

### Build flags for all targets 
CF_ALL		= -w -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os -fpic -fdata-sections -ffunction-sections -Wl,--gc-sections 
LF_ALL		= -Llib/core
LL_ALL		= -static 
AF_ALL		= rcs
UP_ALL		= -V -F -p m328p -c arduino -b 115200 -P$(ARDUINO_PORT)


### Build tools
CC		= avr-gcc
AR		= avr-ar
OC		= avr-objcopy
AVRDUDE		= avrdude
COMP			= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK			= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_LGT) $(LL_ALL)
COMPLINK		= $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
OBJCPY		= $(OC) $(OC_ALL) $(OC_TGT) $< $@
ARCH			= $(AR) $(AF_ALL) $@ $^
UPLOAD		= $(AVRDUDE) $(UP_ALL)

### global variables

ARDUINO_CORE		= $(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT	= $(ARDUINO_DIR)/hardware/arduino/variants/standard
ARDUINO_VERSION   = $(shell grep 'ARDUINO' ${ARDUINO_DIR}/revisions.txt | head -n 1 | awk '{print $$2}' | sed 's/\.//g')

#ARDUINO_PORT	= /dev/ttyACM4
ARDUINO_PORT	= /dev/tty.usbmodemfa141
TGT_UP			= src/chic.hex

### Standard parts
include Rules.mk
