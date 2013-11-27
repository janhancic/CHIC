CC=avr-gcc
CFLAGS=-Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
MCU=atmega168
F_CPU=16000000UL

OBJCOPY=avr-objcopy
BIN_FORMAT=ihex

PORT=/dev/cuaU0
BAUD=19200
PROTOCOL=stk500v1
PART=$(MCU)
AVRDUDE=avrdude -F -V

RM=rm -f

.PHONY: all
all: chic.hex

chic.hex: chic.elf

chic.elf: chic.s

chic.s: chic.c

.PHONY: clean
clean:
	$(RM) chic.elf chic.hex chic.s

.PHONY: upload
upload: chic.hex
	$(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) -b $(BAUD) -U flash:w:$<

%.elf: %.s ; $(CC) $(CFLAGS) -s -o $@ $<

%.s: %.c ; $(CC) $(CFLAGS) -S -o $@ $<

%.hex: %.elf ; $(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $< $@
