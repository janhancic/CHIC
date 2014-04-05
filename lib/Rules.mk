# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Subdirectories, in random order

dir			:= $(d)/core
include		$(dir)/Rules.mk

dir			:= $(d)/catch
include		$(dir)/Rules.mk

dir			:= $(d)/example
include		$(dir)/Rules.mk

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
