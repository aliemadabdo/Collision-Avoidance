################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/RTOS/RTOS.c \
../LIB/RTOS/TIM2.c 

OBJS += \
./LIB/RTOS/RTOS.o \
./LIB/RTOS/TIM2.o 

C_DEPS += \
./LIB/RTOS/RTOS.d \
./LIB/RTOS/TIM2.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/RTOS/%.o: ../LIB/RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


