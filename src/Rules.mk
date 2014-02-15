# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local rules and targets

TGTS_$(d)	:= $(d)/chic.hex

TGT_BIN		:= $(TGT_BIN) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d)) $(TGTS_$(d):%.hex=%.elf) $(TGTS_$(d):%.hex=%.o)
SRCS			:= $(wildcard src/*.c)
LIBS_$(d)	:= lib/core/libcore.a lib/gyro/MPU6050.o lib/i2cdev/I2Cdev.o


$(TGTS_$(d):%.hex=%.o):	CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -Ilib/i2cdev -Ilib/gyro -I$(ARDUINO_DIR)/libraries/Wire
$(TGTS_$(d):%.hex=%.o):	$(d)/chic.cpp
	$(COMP) 

$(TGTS_$(d):%.hex=%.elf): LF_TGT := -Wl,--gc-sections
$(TGTS_$(d):%.hex=%.elf): LIBS := $(LIBS_$(d)) 
$(TGTS_$(d):%.hex=%.elf): $(TGTS_$(d):%.hex=%.o) $(LIBS_$(d))
	$(LINK) $(LIBS) -lm 

$(TGTS_$(d):%.hex=%.eep): OC_TGT := -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0
$(TGTS_$(d):%.hex=%.eep): $(TGTS_$(d))
	      $(OBJCPY)

$(TGTS_$(d)): OC_TGT := -O ihex -R .eeprom
$(TGTS_$(d)): $(TGTS_$(d):%.hex=%.elf)
			$(OBJCPY) 

$(d)/dummytest.o: $(d)/tests/dummytest.c
	gcc -o $@ $^ /usr/local/lib/libcheck.a
	$@ 
	

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

