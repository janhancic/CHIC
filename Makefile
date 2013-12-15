ARDUINO_CORE=$(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT=$(ARDUINO_DIR)/hardware/arduino/variants/standard

CC=avr-gcc
CXX=avr-g++
MCU=-mmcu=atmega328p
CPU_SPEED=-DF_CPU=16000000UL
CFLAGS=$(MCU) $(CPU_SPEED) -Os -w
BOARD=arduino
LIBNAME=lib$(BOARD).a

OBJECTS=wiring.o wiring_analog.o wiring_digital.o \
                   wiring_pulse.o wiring_shift.o HardwareSerial.o Print.o   \
                   Tone.o WMath.o WString.o WInterrupts.o

default: $(OBJECTS)
	avr-ar rcs $(LIBNAME) $^
	rm *.o

%.o : $(ARDUINO_CORE)/%.c
	$(CC) $< $(CFLAGS) -c -o $@ -I$(ARDUINO_VARIANT)

%.o : $(ARDUINO_CORE)/%.cpp
	$(CXX) $< $(CFLAGS) -c -o $@ -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
	
	
clean:
	rm -f *.o