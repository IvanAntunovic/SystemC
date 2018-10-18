################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Adder.cpp \
../src/Decimator.cpp \
../src/Destination.cpp \
../src/Multiplier.cpp \
../src/Source.cpp \
../src/Testbench.cpp \
../src/main.cpp 

OBJS += \
./src/Adder.o \
./src/Decimator.o \
./src/Destination.o \
./src/Multiplier.o \
./src/Source.o \
./src/Testbench.o \
./src/main.o 

CPP_DEPS += \
./src/Adder.d \
./src/Decimator.d \
./src/Destination.d \
./src/Multiplier.d \
./src/Source.d \
./src/Testbench.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ivan/workspace/MSS_Exercise_3.2/headers" -I/usr/local/systemc-2.3.1/include/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


