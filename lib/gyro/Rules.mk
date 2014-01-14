# Standard things

sp					:= $(sp).x
dirstack_$(sp)	:= $(d)
d					:= $(dir)

# Local variables

OBJS_$(d)	:= $(d)/mpu6050.o 

CLEAN		:= $(CLEAN) $(OBJS_$(d))

# Local rules
#-I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
$(d)/mpu6050.o:	CF_TGT := -I$(d)/*.h -I$(d)I2Cdev/I2Cdev.h -I$(ARDUINO_VARIANT) -I$(ARDUINO_CORE)
$(d)/mpu6050.o:	$(d)/MPU6050.cpp $(d)/I2Cdev/I2Cdev.cpp	
				$(COMP)
	
# Standard things

-include	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
