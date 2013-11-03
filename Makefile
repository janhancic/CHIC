CC=avr-gcc

compile: chic.c
	$(CC) -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o chic.o chic.c
	$(CC) -mmcu=atmega328p chic.o -o chic

upload: compile
	avr-objcopy -O ihex -R .eeprom chic chic.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM3 -b 115200 -U flash:w:chic.hex

clean: 
	rm -f *.o
	rm -f *.hex
	rm -f chic
