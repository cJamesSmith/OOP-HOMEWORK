################################################################################
# MAKEFILE OF HW5
# gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.11)
################################################################################

RM := rm -rf

# All of the sources participating in the build are defined here
# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./Fraction.cpp \
./main.cpp 

OBJS += \
./Fraction.o \
./main.o 

CPP_DEPS += \
./Fraction.d \
./main.d 

# Each subdirectory must supply rules for building sources it contributes
%.o: ./%.cpp
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: HW5

# Tool invocations
HW5: $(OBJS) $(USER_OBJS)
	g++  -o "HW5" $(OBJS) $(USER_OBJS) $(LIBS)

# Other Targets
clean:
	$(RM) $(CC_DEPS)$(C++_DEPS)$(CUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) HW5
	-@echo ' '

.PHONY: all clean dependents

