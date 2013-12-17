# Standard things

sp			:= $(sp).x
dirstack	:= $(d)
d			:= $(dir)

# Local variables

ARDUINO_CORE=$(ARDUINO_DIR)/hardware/arduino/cores/arduino
ARDUINO_VARIANT=$(ARDUINO_DIR)/hardware/arduino/variants/standard

OBJS_$(d)	:= $(d)/wiring.o $(d)/wiring_analog.o $(d)/wiring_digital.o \
				$(d)/wiring_pulse.o $(d)/wiring_shift.o $(d)/HardwareSerial.o $(d)/Print.o   \
				$(d)/Tone.o $(d)/WMath.o $(d)/WString.o $(d)/WInterrupts.o

CLEAN		:= $(CLEAN) $(OBJS_$(d)) 

# Local rules

TGTS_$(d)	:= $(d)/libcore.a
DEPS_$(d)	:= $(OBJS_$(d))
SRC_FROM	:= $(ARDUINO_CORE)

CF_TGT		:= -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)

TGT_LIB		:= $(TGT_BIN) $(DEPS_$(d))

CLEAN		:= $(CLEAN) $(TGTS_$(d)) $(DEPS_$(d)

$(OBJS_$(d)):	$(ARDUINO_CORE)/%.c
	$(COMP) -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)

#$(OBJS_$(d)):			$(ARDUINO_CORE)/%.cpp
#	$(COMP) -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)

#$(d)/$(BOARD)_core.a:	$(OBJS_$(d))
#	$(ARCH)
	
# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))