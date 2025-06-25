################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../data_structure/circled_que/circled_que.c 

OBJS += \
./data_structure/circled_que/circled_que.o 

C_DEPS += \
./data_structure/circled_que/circled_que.d 


# Each subdirectory must supply rules for building sources it contributes
data_structure/circled_que/%.o data_structure/circled_que/%.su data_structure/circled_que/%.cyclo: ../data_structure/circled_que/%.c data_structure/circled_que/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/ap" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/driver/Button" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/driver/FND" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/driver/LedBar" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/ap/Inc" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/ap/src" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/data_structure/circled_que" -I"C:/harman/STM32Cube/20250625_TImeWatch_StopWatch_IPO_Pattern/Core/driver/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-data_structure-2f-circled_que

clean-data_structure-2f-circled_que:
	-$(RM) ./data_structure/circled_que/circled_que.cyclo ./data_structure/circled_que/circled_que.d ./data_structure/circled_que/circled_que.o ./data_structure/circled_que/circled_que.su

.PHONY: clean-data_structure-2f-circled_que

