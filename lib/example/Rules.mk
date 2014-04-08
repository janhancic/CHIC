# Standard things

ep						:= $(sp).x
dirstack_$(sp)		:= $(d)
d						:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/example.o
TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d))

# Local rules

$(TGTS_$(d)):	CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -I$(d)
$(TGTS_$(d)):	$(TGTS_$(d):.o=.cpp)
	$(COMP) -fno-exceptions

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
