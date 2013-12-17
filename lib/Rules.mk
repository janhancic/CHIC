# Standard things

sp			:= $(sp).x
dirstack	:= $(d)
d			:= $(dir)

# Subdirectories, in random order

dir			:= $(d)/core
include		$(dir)/Rules.mk


# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))