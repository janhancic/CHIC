# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Subdirectories, in random order

dir 			:= $(d)/gmock
include 		$(dir)/Rules.mk

dir			:= $(d)/core
include		$(dir)/Rules.mk

dir			:= $(d)/gyro
include		$(dir)/Rules.mk

dir			:= $(d)/i2cdev
include		$(dir)/Rules.mk

dir 			:= $(d)/arrayset
include		$(dir)/Rules.mk

dir 			:= $(d)/catch
include 		$(dir)/Rules.mk

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
