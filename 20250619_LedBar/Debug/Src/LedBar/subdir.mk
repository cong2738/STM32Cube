################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LedBar/LedBar.c 

OBJS += \
./Src/LedBar/LedBar.o 

C_DEPS += \
./Src/LedBar/LedBar.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LedBar/%.o Src/LedBar/%.su Src/LedBar/%.cyclo: ../Src/LedBar/%.c Src/LedBar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-LedBar

clean-Src-2f-LedBar:
	-$(RM) ./Src/LedBar/LedBar.cyclo ./Src/LedBar/LedBar.d ./Src/LedBar/LedBar.o ./Src/LedBar/LedBar.su

.PHONY: clean-Src-2f-LedBar

