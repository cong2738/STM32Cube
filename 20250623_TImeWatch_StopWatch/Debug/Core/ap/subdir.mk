################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/StopWatch.c \
../Core/ap/TimeWatch.c \
../Core/ap/ap_main.c 

OBJS += \
./Core/ap/StopWatch.o \
./Core/ap/TimeWatch.o \
./Core/ap/ap_main.o 

C_DEPS += \
./Core/ap/StopWatch.d \
./Core/ap/TimeWatch.d \
./Core/ap/ap_main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/%.o Core/ap/%.su Core/ap/%.cyclo: ../Core/ap/%.c Core/ap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/harman/STM32Cube/20250623_TImeWatch_StopWatch/Core/ap" -I"C:/harman/STM32Cube/20250623_TImeWatch_StopWatch/Core/driver/Button" -I"C:/harman/STM32Cube/20250623_TImeWatch_StopWatch/Core/driver/FND" -I"C:/harman/STM32Cube/20250623_TImeWatch_StopWatch/Core/driver/LedBar" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap

clean-Core-2f-ap:
	-$(RM) ./Core/ap/StopWatch.cyclo ./Core/ap/StopWatch.d ./Core/ap/StopWatch.o ./Core/ap/StopWatch.su ./Core/ap/TimeWatch.cyclo ./Core/ap/TimeWatch.d ./Core/ap/TimeWatch.o ./Core/ap/TimeWatch.su ./Core/ap/ap_main.cyclo ./Core/ap/ap_main.d ./Core/ap/ap_main.o ./Core/ap/ap_main.su

.PHONY: clean-Core-2f-ap

