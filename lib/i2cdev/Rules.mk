# Standard things

ep					:= $(sp).x
dirstack_$(sp)		:= $(d)
d					:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/I2Cdev.o
TGT_LIB	:= $(TGT_LIB) $(TGTS_$(d))
CLEAN		:= $(CLEAN) $(TGTS_$(d))

# Local rules

$(TGTS_$(d)):	CF_TGT := -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE) -I$(ARDUINO_DIR)/hardware/tools/include -I$(ARDUINO_DIR)/libraries/Wire
$(TGTS_$(d)):	$(TGTS_$(d):.o=.cpp)
	$(COMP) -DARDUINO=$(ARDUINO_VERSION)

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
