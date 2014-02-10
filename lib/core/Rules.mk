# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/libcore.a
OBJS_$(d)	:= $(d)/CDC.o $(d)/HID.o $(d)/wiring.o $(d)/wiring_analog.o \
				$(d)/wiring_digital.o $(d)/IPAddress.o $(d)/new.o $(d)/Stream.o $(d)/USBCore.o \
				$(d)/wiring_pulse.o $(d)/wiring_shift.o $(d)/HardwareSerial.o $(d)/Print.o   \
				$(d)/Tone.o $(d)/WMath.o $(d)/WInterrupts.o $(d)/HID.o $(d)/Tone.o

TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))

CLEAN			:= $(CLEAN) $(TGTS_$(d)) $(OBJS_$(d))

# Local rules

$(TGTS_$(d)):	$(OBJS_$(d))
		$(ARCH)

$(d)/%.o:	CF_TGT := -I$(ARDUINO_CORE)
$(d)/%.o:	$(ARDUINO_CORE)/%.c
				$(COMP)

$(d)/%.o:	CF_TGT := -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
$(d)/%.o:	$(ARDUINO_CORE)/%.cpp
				$(COMP)

	
# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
