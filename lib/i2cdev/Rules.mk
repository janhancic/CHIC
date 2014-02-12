# Standard things

ep					:= $(sp).x
dirstack_$(sp)		:= $(d)
d					:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/I2Cdev.o
TGT_LIB	:= $(TGT_LIB) $(TGTS_$(d))
CLEAN		:= $(CLEAN) $(TGTS_$(d))

# Local rules

$(TGTS_$(d)):	CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -I$(d) -I$(ARDUINO_DIR)/libraries/Wire
$(TGTS_$(d)):	$(TGTS_$(d):.o=.cpp)
	$(COMPP)

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
