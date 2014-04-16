# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local rules and targets
CLEAN := $(CLEAN) $(d)/arrayset.test

$(d)/arrayset.test: CF_TGT := -Ilib/catch
$(d)/arrayset.test: $(d)/arrayset.cpp $(d)/test_arrayset.cpp
	$(TESTCOMP)
	@./$@

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

