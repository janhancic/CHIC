# Standard things

ep						:= $(sp).x
dirstack_$(sp)		:= $(d)
d						:= $(dir)

# Local variables

TGTS_$(d)	:= $(d)/gmock_main.a $(d)/gmock.a $(d)/*.o
TGT_LIB		:= $(TGT_LIB) $(TGTS_$(d))
CLEAN			:= $(CLEAN) $(TGTS_$(d))

GTEST_DIR 	:= $(d)/gmock/gtest
GMOCK_DIR 	:= $(d)/gmock
CPPFLAGS 	:= -isystem $(GTEST_DIR)/include -isystem $(GMOCK_DIR)/include
CXXFLAGS 	:= -g -Wall -Wextra -pthread

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GMOCK_HEADERS := $(GMOCK_DIR)/include/gmock/*.h \
                $(GMOCK_DIR)/include/gmock/internal/*.h \
                $(GTEST_HEADERS)

GTEST_SRCS_ := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
GMOCK_SRCS_ := $(GMOCK_DIR)/src/*.cc $(GMOCK_HEADERS)


# Local rules
$(d)/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) -I$(GMOCK_DIR) $(CXXFLAGS) \
            -o $@ -c $(GTEST_DIR)/src/gtest-all.cc

$(d)/gmock-all.o : $(GMOCK_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) -I$(GMOCK_DIR) $(CXXFLAGS) \
            -o $@ -c $(GMOCK_DIR)/src/gmock-all.cc

$(d)/gmock_main.o : $(GMOCK_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) -I$(GMOCK_DIR) $(CXXFLAGS) \
            -o $@ -c $(GMOCK_DIR)/src/gmock_main.cc

$(d)/gmock.a : lib/gmock/gmock-all.o lib/gmock/gtest-all.o
	ar $(ARFLAGS) $@ $^

$(d)/gmock_main.a : lib/gmock/gmock-all.o lib/gmock/gtest-all.o lib/gmock/gmock_main.o
	ar $(ARFLAGS) $@ $^

# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
