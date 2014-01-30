# Standard things

sp						:= $(sp).x
dirstack_$(sp)		:= $(d)
d						:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/MPU6050.o 
TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d))

# Local rules

$(TGTS_$(d)):	CF_TGT := -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE) -I$(ARDUINO_DIR)hardware/tools/include -Ilib/i2cdev
$(TGTS_$(d)):	ARDUINO_VERSION := $(shell grep 'ARDUINO' ${ARDUINO_DIR}/revisions.txt | head -n 1 | awk '{print $$2}' | sed 's/\.//g')
$(TGTS_$(d)):	$(TGTS_$(d):.o=.cpp) lib/i2cdev/I2Cdev.o
	$(COMP) -D ARDUINO=$(ARDUINO_VERSION)
	
# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
