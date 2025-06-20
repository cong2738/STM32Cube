################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/TICK/sys_tick.c 

OBJS += \
./Src/driver/TICK/sys_tick.o 

C_DEPS += \
./Src/driver/TICK/sys_tick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/TICK/%.o Src/driver/TICK/%.su Src/driver/TICK/%.cyclo: ../Src/driver/TICK/%.c Src/driver/TICK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/FND" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/button" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/AP" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/TIM" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/TICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-TICK

clean-Src-2f-driver-2f-TICK:
	-$(RM) ./Src/driver/TICK/sys_tick.cyclo ./Src/driver/TICK/sys_tick.d ./Src/driver/TICK/sys_tick.o ./Src/driver/TICK/sys_tick.su

.PHONY: clean-Src-2f-driver-2f-TICK

