# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local rules and targets

TGTS_$(d)	:= $(d)/chic.hex

TGT_BIN		:= $(TGT_BIN) $(TGTS_$(d))
CLEAN		:= $(CLEAN) $(TGTS_$(d)) $(TGTS_$(d):%.hex=%.elf)

$(TGTS_$(d)): $(TGTS_$(d):%.hex=%.elf) $(d)/dummytest.o 
			$(OBJCPY) -O ihex

$(TGTS_$(d):%.hex=%.elf):	CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT)
$(TGTS_$(d):%.hex=%.elf):	LL_TGT := lib/core/libcore.a
$(TGTS_$(d):%.hex=%.elf):	$(d)/chic.cpp lib/core/libcore.a
							$(COMPLINK)


$(d)/dummytest.o: $(d)/tests/dummytest.c
	gcc -o $@ $^ /usr/local/lib/libcheck.a
	$@ 
	

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

