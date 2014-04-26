# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/libcore.a
OBJS_$(d)	:= $(d)/CDC.o $(d)/HID.o $(d)/wiring.o $(d)/wiring_analog.o \
				$(d)/wiring_digital.o $(d)/IPAddress.o $(d)/new.o $(d)/Stream.o $(d)/USBCore.o \
				$(d)/wiring_pulse.o $(d)/wiring_shift.o $(d)/HardwareSerial.o $(d)/Print.o   \
				$(d)/Tone.o $(d)/WMath.o $(d)/WString.o $(d)/WInterrupts.o $(d)/twi.o
LIBS_$(d)	:= $(addprefix $(d)/, $(addsuffix .o, $(ARDUINO_LIBS)))

TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))

CLEAN		:= $(CLEAN) $(TGTS_$(d)) $(OBJS_$(d)) $(LIBS_$(d))

# Local rules

$(TGTS_$(d)):	$(OBJS_$(d)) $(LIBS_$(d))
		$(ARCH)

$(d)/%.o:	CF_TGT := -I$(ARDUINO_CORE)
$(d)/%.o:	$(ARDUINO_CORE)/%.c
				$(COMP)

$(d)/%.o:	CF_TGT := -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
$(d)/%.o:	$(ARDUINO_CORE)/%.cpp
				$(COMP)

define build_lib
$(d)/%.o:	$1/%.cpp
		$(CC) $$(CF_ALL) -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) $(addprefix -I$(ARDUINO_LIB_DIR)/, $(addsuffix /utility, $(ARDUINO_LIBS))) $(addprefix -I$(ARDUINO_LIB_DIR)/, $(ARDUINO_LIBS)) -o $$@ -c $$<
endef

$(foreach L,$(addprefix $(ARDUINO_LIB_DIR)/, $(ARDUINO_LIBS)), $(eval $(call build_lib, $L)))

define lib_utility
$(d)/%.o:	CF_TGT := -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
$(d)/%.o:	$1/utility/%.c
		$(CC) $$(CF_ALL) $$(CF_TGT) -o $$@ -c $$<
endef

$(foreach L,$(addprefix $(ARDUINO_LIB_DIR)/, $(ARDUINO_LIBS)),$(eval $(call lib_utility, $L)))

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
