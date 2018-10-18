################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bus.cpp \
../src/bus_ca.cpp \
../src/bus_cx.cpp \
../src/main.cpp \
../src/master.cpp \
../src/new_master.cpp \
../src/ram.cpp 

OBJS += \
./src/bus.o \
./src/bus_ca.o \
./src/bus_cx.o \
./src/main.o \
./src/master.o \
./src/new_master.o \
./src/ram.o 

CPP_DEPS += \
./src/bus.d \
./src/bus_ca.d \
./src/bus_cx.d \
./src/main.d \
./src/master.d \
./src/new_master.d \
./src/ram.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.1/include/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


