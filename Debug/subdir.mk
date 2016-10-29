################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DLL.cpp \
../DNode.cpp \
../SLL.cpp \
../SNode.cpp \
../lab3main.cpp 

OBJS += \
./DLL.o \
./DNode.o \
./SLL.o \
./SNode.o \
./lab3main.o 

CPP_DEPS += \
./DLL.d \
./DNode.d \
./SLL.d \
./SNode.d \
./lab3main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


