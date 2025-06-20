################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/TIM/TIM.c 

OBJS += \
./Src/driver/TIM/TIM.o 

C_DEPS += \
./Src/driver/TIM/TIM.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/TIM/%.o Src/driver/TIM/%.su Src/driver/TIM/%.cyclo: ../Src/driver/TIM/%.c Src/driver/TIM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250620_HW/Src/AP" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/button" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/FND" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/TICK" -I"C:/harman/STM32Cube/20250620_HW/Src/driver/TIM" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-TIM

clean-Src-2f-driver-2f-TIM:
	-$(RM) ./Src/driver/TIM/TIM.cyclo ./Src/driver/TIM/TIM.d ./Src/driver/TIM/TIM.o ./Src/driver/TIM/TIM.su

.PHONY: clean-Src-2f-driver-2f-TIM

