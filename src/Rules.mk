# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local rules and targets

TGTS_$(d)	:= $(d)/chic.hex

LIBS_$(d)	:= lib/core/libcore.a lib/gyro/MPU6050.o lib/i2cdev/I2Cdev.o lib/arrayset/arrayset.o
TESTSRC_$(d):= $(wildcard $(d)/test_*.cpp)
OBJS_$(d)	:= $(patsubst %.cpp,%.o,$(filter-out $(TESTSRC_$(d)), $(wildcard $(d)/*.cpp)))
TESTS_$(d)	:= $(patsubst $(d)/test_%.cpp,%.test,$(TESTSRC_$(d)))

TGT_BIN		:= $(TGT_BIN) $(TGTS_$(d))
TESTS			:= $(TESTS) $(patsubst %, $(d)/%,$(TESTS_$(d)))
CLEAN			:= $(CLEAN) $(TGTS_$(d)) $(TGTS_$(d):%.hex=%.elf) $(OBJS_$(d)) $(patsubst %, $(d)/%,$(TESTS_$(d))) $(d)/*.dSYM

GMOCK_INCLUES := -Ilib/gmock/gmock/include -Ilib/gmock/gmock/gtest/include -Ilib/gmock/gmock/gtest/include/gtest/internal

$(OBJS_$(d)): CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -I$(d) -I$(d)/wrapper -Ilib/i2cdev -Ilib/gyro -Ilib/arrayset
$(OBJS_$(d)): CF_TGT += $(addprefix -I$(ARDUINO_LIB_DIR)/, $(ARDUINO_LIBS))
$(OBJS_$(d)): %.o : %.cpp
	$(COMP)

$(TGTS_$(d):%.hex=%.elf): LF_TGT := -Wl,--gc-sections
$(TGTS_$(d):%.hex=%.elf): $(OBJS_$(d)) $(LIBS_$(d))
	$(LINK) -lm

$(TGTS_$(d):%.hex=%.eep): OC_TGT := -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0
$(TGTS_$(d):%.hex=%.eep): $(TGTS_$(d))
	$(OBJCPY)

$(TGTS_$(d)): OC_TGT := -O ihex -R .eeprom
$(TGTS_$(d)): $(TGTS_$(d):%.hex=%.elf)
	$(OBJCPY)

define test_target
$(d)/$1: CF_TGT := -I$(ARDUINO_CORE) -I$(ARDUINO_VARIANT) -I$(d)/wrapper -Ilib/catch -Ilib/arrayset $(GMOCK_INCLUES) -Ilib/gyro -Ilib/i2cdev -D_TESTING
$(d)/$1: $(d)/test_$(1:%.test=%.cpp) $(d)/$(1:%.test=%.cpp) lib/arrayset/arrayset.cpp src/eventdispatcher.cpp lib/gmock/gmock_main.a
	$(CXX) -g -O3 -std=c++11 -Wall $$(CF_TGT) -o $$@ $$^ 
	@./$$@
endef

$(foreach T,$(TESTS_$(d)),$(eval $(call test_target,$T)))

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

