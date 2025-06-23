################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/SysTick/SysTick.c 

OBJS += \
./Src/driver/SysTick/SysTick.o 

C_DEPS += \
./Src/driver/SysTick/SysTick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/SysTick/%.o Src/driver/SysTick/%.su Src/driver/SysTick/%.cyclo: ../Src/driver/SysTick/%.c Src/driver/SysTick/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/FND" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/Button" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/ap" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/TIM" -I"C:/harman/STM32Cube/20250620_FND_TIM_Interrupt/Src/driver/SysTick" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-SysTick

clean-Src-2f-driver-2f-SysTick:
	-$(RM) ./Src/driver/SysTick/SysTick.cyclo ./Src/driver/SysTick/SysTick.d ./Src/driver/SysTick/SysTick.o ./Src/driver/SysTick/SysTick.su

.PHONY: clean-Src-2f-driver-2f-SysTick

