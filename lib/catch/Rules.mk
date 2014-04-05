# Standard things

ep						:= $(sp).x
dirstack_$(sp)		:= $(d)
d						:= $(dir)

# Local variables

TGTS_$(d)	:= 
TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d))

# Local rules


# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
