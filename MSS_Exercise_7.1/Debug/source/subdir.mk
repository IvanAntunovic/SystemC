################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/dst.cpp \
../source/main.cpp \
../source/mem.cpp \
../source/src.cpp \
../source/trans.cpp 

OBJS += \
./source/dst.o \
./source/main.o \
./source/mem.o \
./source/src.o \
./source/trans.o 

CPP_DEPS += \
./source/dst.d \
./source/main.d \
./source/mem.d \
./source/src.d \
./source/trans.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.1/include/ -I"/home/ivan/workspace/MSS_Exercise_7.1/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


