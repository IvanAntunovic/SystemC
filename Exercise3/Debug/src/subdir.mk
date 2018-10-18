################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/adder.cpp \
../src/main.cpp \
../src/testbench.cpp 

OBJS += \
./src/adder.o \
./src/main.o \
./src/testbench.o 

CPP_DEPS += \
./src/adder.d \
./src/main.d \
./src/testbench.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ivan/workspace/Exercise3/headers" -I/usr/local/systemc-2.3.1/include/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


