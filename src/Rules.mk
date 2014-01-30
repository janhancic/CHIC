# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local rules and targets

TGTS_$(d)	:= $(d)/chic.hex

TGT_BIN		:= $(TGT_BIN) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d)) $(TGTS_$(d):%.hex=%.elf)

$(TGTS_$(d)): $(TGTS_$(d):%.hex=%.elf) 
			$(OBJCPY) -O ihex

$(TGTS_$(d):%.hex=%.elf):	CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -Ilib/i2cdev -Ilib/gyro
$(TGTS_$(d):%.hex=%.elf):	LL_TGT := lib/core/libcore.a lib/gyro/MPU6050.o lib/i2cdev/I2Cdev.o
$(TGTS_$(d):%.hex=%.elf):	$(d)/chic.cpp $(LL_TGT)
							$(COMPLINK)


$(d)/dummytest.o: $(d)/tests/dummytest.c
	gcc -o $@ $^ /usr/local/lib/libcheck.a
	$@ 
	

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

