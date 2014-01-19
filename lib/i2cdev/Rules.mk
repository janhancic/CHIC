# Standard things

sp					:= $(sp).x
dirstack_$(sp)		:= $(d)
d					:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/I2CDev.o

CLEAN		:= $(CLEAN) $(TGS_$(d))

# Local rules

$(TGTS_$(d)):	$(TGTS_$(d):.o=.cpp)
	echo "hello you fucking thing"	

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
