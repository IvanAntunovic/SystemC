################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/adapter.cpp \
../source/adder.cpp \
../source/bus_ca.cpp \
../source/bus_cx.cpp \
../source/bus_pv.cpp \
../source/master.cpp \
../source/new_master.cpp \
../source/ram.cpp \
../source/sc_main.cpp 

OBJS += \
./source/adapter.o \
./source/adder.o \
./source/bus_ca.o \
./source/bus_cx.o \
./source/bus_pv.o \
./source/master.o \
./source/new_master.o \
./source/ram.o \
./source/sc_main.o 

CPP_DEPS += \
./source/adapter.d \
./source/adder.d \
./source/bus_ca.d \
./source/bus_cx.d \
./source/bus_pv.d \
./source/master.d \
./source/new_master.d \
./source/ram.d \
./source/sc_main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.1/include/ -I"/home/ivan/workspace/MSS_Exercise_4.3/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


