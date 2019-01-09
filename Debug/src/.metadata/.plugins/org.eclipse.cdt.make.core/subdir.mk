################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp 

C_SRCS += \
../src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

OBJS += \
./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

CPP_DEPS += \
./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 

C_DEPS += \
./src/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
src/.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../src/.metadata/.plugins/org.eclipse.cdt.make.core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../src/.metadata/.plugins/org.eclipse.cdt.make.core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


