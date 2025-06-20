################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/FND/FND.c 

OBJS += \
./Src/driver/FND/FND.o 

C_DEPS += \
./Src/driver/FND/FND.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/FND/%.o Src/driver/FND/%.su Src/driver/FND/%.cyclo: ../Src/driver/FND/%.c Src/driver/FND/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/FND" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/button" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/AP" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/TIM" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/TICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-FND

clean-Src-2f-driver-2f-FND:
	-$(RM) ./Src/driver/FND/FND.cyclo ./Src/driver/FND/FND.d ./Src/driver/FND/FND.o ./Src/driver/FND/FND.su

.PHONY: clean-Src-2f-driver-2f-FND

