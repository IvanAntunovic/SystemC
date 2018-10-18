################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Process1.cpp \
../src/Process2.cpp \
../src/Process3.cpp \
../src/Testbench.cpp \
../src/main.cpp 

OBJS += \
./src/Process1.o \
./src/Process2.o \
./src/Process3.o \
./src/Testbench.o \
./src/main.o 

CPP_DEPS += \
./src/Process1.d \
./src/Process2.d \
./src/Process3.d \
./src/Testbench.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ivan/workspace/SystemC_Initialization_Phase/headers" -I/usr/local/systemc-2.3.1/include/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


