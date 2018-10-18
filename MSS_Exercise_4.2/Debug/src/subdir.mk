################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/adder.cpp \
../src/bus_cx.cpp \
../src/bus_pv.cpp \
../src/master.cpp \
../src/ram.cpp \
../src/sc_main.cpp 

OBJS += \
./src/adder.o \
./src/bus_cx.o \
./src/bus_pv.o \
./src/master.o \
./src/ram.o \
./src/sc_main.o 

CPP_DEPS += \
./src/adder.d \
./src/bus_cx.d \
./src/bus_pv.d \
./src/master.d \
./src/ram.d \
./src/sc_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ivan/workspace/MSS_Exercise_4.2/headers" -I/usr/local/systemc-2.3.1/include/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


