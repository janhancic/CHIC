# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/libcore.a
OBJS_$(d)	:= $(d)/CDC.o $(d)/HID.o $(d)/wiring.o $(d)/wiring_analog.o \
				$(d)/wiring_digital.o $(d)/IPAddress.o $(d)/new.o $(d)/Stream.o $(d)/USBCore.o \
				$(d)/wiring_pulse.o $(d)/wiring_shift.o $(d)/HardwareSerial.o $(d)/Print.o   \
				$(d)/Tone.o $(d)/WMath.o $(d)/WInterrupts.o $(d)/HID.o $(d)/Tone.o \
				$(d)/malloc.o $(d)/realloc.o $(d)/WString.o

LIBS_$(d)   := $(d)/Wire.o $(d)/twi.o $(d)/Servo.o

TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d)) $(OBJS_$(d))

vpath % $(ARDUINO_CORE):$(ARDUINO_CORE)/avr-libc
vpath % $(ARDUINO_DIR)/libraries/Wire:$(ARDUINO_DIR)/libraries/Wire/utility
vpath % $(ARDUINO_DIR)/libraries/Servo
# Local rules

$(TGTS_$(d)):	$(OBJS_$(d)) $(LIBS_$(d)) 
		$(ARCH)

$(d)/%.o:	CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_DIR)/libraries -I$(ARDUINO_DIR)/libraries/Wire/utility -I$(ARDUINO_CORE)/avr-libc
$(d)/%.o:	%.c
	$(COMP)

$(d)/%.o:	CF_TGT := -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE) -I$(ARDUINO_DIR)/libraries -I$(ARDUINO_DIR)/libraries/Wire/utility -I$(ARDUINO_CORE)/avr-libc
$(d)/%.o:	%.cpp
	$(COMP) -fno-exceptions

	
# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
