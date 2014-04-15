# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local rules and targets

$(d)/arrayset.test: CF_TGT := -Ilib/catch
$(d)/arrayset.test: $(d)/arrayset.cpp $(d)/test_arrayset.cpp
	$(CXX) -g -O3 -Wall $(CF_TGT) -o $@ $^
	@./$@


$(foreach T,$(TESTS_$(d)),$(eval $(call test_target,$T)))

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

