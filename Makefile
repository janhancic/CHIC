### Board specific config
MCU			= atmega328p
CPU_SPEED	= 16000000UL

### Build flags for all targets 
CF_ALL		= -g -Os -Wall -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -DARDUINO=$(ARDUINO_VERSION)
LF_ALL		= -Os -mmcu=$(MCU)
LL_ALL		=
AF_ALL		= rcs
UP_ALL		= -V -F -D -p $(MCU) -c arduino -b 115200 -P$(ARDUINO_PORT)


### Build tools
CC		= $(ARDUINO_BIN_DIR)avr-g++
CXX	= g++
AR		= avr-ar
OC		= avr-objcopy
AVRDUDE		= avrdude
COMP			= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK			= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_LGT) $(LL_ALL)
COMPLINK		= $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
OBJCPY		= $(OC) $(OC_ALL) $(OC_TGT) $< $@
ARCH			= $(AR) $(AF_ALL) $@ $^
UPLOAD		= $(AVRDUDE) $(UP_ALL)
TESTCOMP		= $(CXX) -g -Os -Wall  $(CF_TGT) -o $@ $^

### global variables

ARDUINO_CORE		= $(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT	= $(ARDUINO_DIR)/hardware/arduino/variants/standard
#ARDUINO_BIN_DIR   = $(ARDUINO_DIR)/hardware/tools/avr/bin/
ARDUINO_LIB_DIR 	= $(ARDUINO_DIR)/libraries


ARDUINO_LIBS 		= Servo
ARDUINO_VERSION 	= 105

#ARDUINO_PORT	= /dev/tty.usbmodemfa141
ARDUINO_PORT	= /dev/ttyACM4
TGT_UP		= src/main.hex

### Standard parts
include Rules.mk
