### Board specific config
MCU			= atmega328p
CPU_SPEED	= 16000000UL

### Build flags for all targets 
CF_ALL		= -w -MMD -c -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -DARDUINO=$(ARDUINO_VERSION) -ffunction-sections -fdata-sections -fno-exceptions -Os
LF_ALL		= -mmcu=$(MCU) 
LL_ALL		= -lc -lm
AF_ALL		= rcs
UP_ALL		= -V -D -p atmega328p -C $(ARDUINO_DIR)/hardware/tools/avr/etc/avrdude.conf -c arduino -b 115200 -P $(ARDUINO_PORT)


### Build tools
CC		= $(ARDUINO_BIN_DIR)/avr-gcc
AR		= $(ARDUINO_BIN_DIR)/avr-ar
OC		= $(ARDUINO_BIN_DIR)/avr-objcopy
AVRDUDE		= $(ARDUINO_BIN_DIR)/avrdude 
COMP			= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK			= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_LGT) $(LL_ALL)
COMPLINK		= $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
OBJCPY		= $(OC) $(OC_ALL) $(OC_TGT) $< $@
ARCH			= $(AR) $(AF_ALL) $@ $^
UPLOAD		= $(AVRDUDE) $(UP_ALL)

### global variables

ARDUINO_CORE		= $(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT	= $(ARDUINO_DIR)/hardware/arduino/variants/standard
ARDUINO_BIN_DIR   = $(ARDUINO_DIR)/hardware/tools/avr/bin
ARDUINO_VERSION   = $(shell grep 'ARDUINO' ${ARDUINO_DIR}/revisions.txt | head -n 1 | awk '{print $$2}' | sed 's/\.//g')

#ARDUINO_PORT	= /dev/ttyACM4
ARDUINO_PORT	= /dev/tty.usbmodemfd131
TGT_UP			= src/chic.hex

### Standard parts
include Rules.mk
