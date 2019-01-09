################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/system_elements/AlfaPendular.cpp \
../src/system_elements/Engineer.cpp \
../src/system_elements/InterCidades.cpp \
../src/system_elements/Passenger.cpp \
../src/system_elements/PassengerCard.cpp \
../src/system_elements/Person.cpp \
../src/system_elements/Station.cpp \
../src/system_elements/SystemElement.cpp \
../src/system_elements/Train.cpp \
../src/system_elements/Trip.cpp 

OBJS += \
./src/system_elements/AlfaPendular.o \
./src/system_elements/Engineer.o \
./src/system_elements/InterCidades.o \
./src/system_elements/Passenger.o \
./src/system_elements/PassengerCard.o \
./src/system_elements/Person.o \
./src/system_elements/Station.o \
./src/system_elements/SystemElement.o \
./src/system_elements/Train.o \
./src/system_elements/Trip.o 

CPP_DEPS += \
./src/system_elements/AlfaPendular.d \
./src/system_elements/Engineer.d \
./src/system_elements/InterCidades.d \
./src/system_elements/Passenger.d \
./src/system_elements/PassengerCard.d \
./src/system_elements/Person.d \
./src/system_elements/Station.d \
./src/system_elements/SystemElement.d \
./src/system_elements/Train.d \
./src/system_elements/Trip.d 


# Each subdirectory must supply rules for building sources it contributes
src/system_elements/%.o: ../src/system_elements/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


