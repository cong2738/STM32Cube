################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/TIC/sys_tic.c 

OBJS += \
./Src/driver/TIC/sys_tic.o 

C_DEPS += \
./Src/driver/TIC/sys_tic.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/TIC/%.o Src/driver/TIC/%.su Src/driver/TIC/%.cyclo: ../Src/driver/TIC/%.c Src/driver/TIC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/FND" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/button" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/AP" -I"C:/harman/STM32Cube/20250629_FND_TIM_Interruft/Src/driver/TIM" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-TIC

clean-Src-2f-driver-2f-TIC:
	-$(RM) ./Src/driver/TIC/sys_tic.cyclo ./Src/driver/TIC/sys_tic.d ./Src/driver/TIC/sys_tic.o ./Src/driver/TIC/sys_tic.su

.PHONY: clean-Src-2f-driver-2f-TIC

