################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/DIO/subdir.mk
-include LIB/RTOS/subdir.mk
-include HAL/UltraSonic/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/DCMotor/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Collision_Avoidance.lss \

FLASH_IMAGE += \
Collision_Avoidance.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Collision_Avoidance.elf secondary-outputs

# Tool invocations
Collision_Avoidance.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Collision_Avoidance.map -mmcu=atmega32 -o "Collision_Avoidance.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Collision_Avoidance.lss: Collision_Avoidance.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Collision_Avoidance.elf  >"Collision_Avoidance.lss"
	@echo 'Finished building: $@'
	@echo ' '

Collision_Avoidance.hex: Collision_Avoidance.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Collision_Avoidance.elf  "Collision_Avoidance.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Collision_Avoidance.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Collision_Avoidance.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Collision_Avoidance.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
