################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Decimator.cpp \
../src/Multiplier.cpp \
../src/adder.cpp \
../src/main.cpp \
../src/testbench.cpp 

OBJS += \
./src/Decimator.o \
./src/Multiplier.o \
./src/adder.o \
./src/main.o \
./src/testbench.o 

CPP_DEPS += \
./src/Decimator.d \
./src/Multiplier.d \
./src/adder.d \
./src/main.d \
./src/testbench.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.1/include/ -I"/home/ivan/workspace/MSS_Exercise_3.1/headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


