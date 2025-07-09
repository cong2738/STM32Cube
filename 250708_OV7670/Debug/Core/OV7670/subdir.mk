################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/OV7670/OV7670.c 

OBJS += \
./Core/OV7670/OV7670.o 

C_DEPS += \
./Core/OV7670/OV7670.d 


# Each subdirectory must supply rules for building sources it contributes
Core/OV7670/%.o Core/OV7670/%.su Core/OV7670/%.cyclo: ../Core/OV7670/%.c Core/OV7670/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/harman/STM32Cube/250708_OV7670/Core/Lib/ili9341" -I"C:/harman/STM32Cube/250708_OV7670/Core/OV7670" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-OV7670

clean-Core-2f-OV7670:
	-$(RM) ./Core/OV7670/OV7670.cyclo ./Core/OV7670/OV7670.d ./Core/OV7670/OV7670.o ./Core/OV7670/OV7670.su

.PHONY: clean-Core-2f-OV7670

