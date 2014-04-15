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
AR		= $(ARDUINO_BIN_DIR)avr-ar
OC		= $(ARDUINO_BIN_DIR)avr-objcopy
AVRDUDE		= $(ARDUINO_BIN_DIR)avrdude
COMP			= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK			= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_LGT) $(LL_ALL)
COMPLINK		= $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
OBJCPY		= $(OC) $(OC_ALL) $(OC_TGT) $< $@
ARCH			= $(AR) $(AF_ALL) $@ $^
UPLOAD		= $(AVRDUDE) $(UP_ALL)

### global variables

ifndef ARDUINO_CORE
ARDUINO_CORE		= $(ARDUINO_DIR)/hardware/arduino/cores/arduino
endif
ifndef ARDUINO_VARIANT
ARDUINO_VARIANT	= $(ARDUINO_DIR)/hardware/arduino/variants/standard
endif
ifndef ARDUINO_LIB_DIR
ARDUINO_LIB_DIR 	= $(ARDUINO_DIR)/libraries
endif

#ARDUINO_BIN_DIR   = $(ARDUINO_DIR)/hardware/tools/avr/bin/


ARDUINO_LIBS 		= Servo Wire
ARDUINO_VERSION 	= 105

#ARDUINO_PORT	= /dev/tty.usbmodemfa141
ARDUINO_PORT	= /dev/ttyACM4
TGT_UP		= src/chic.hex

### Standard parts
include Rules.mk
