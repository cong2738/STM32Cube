################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AP/AP_main.c 

OBJS += \
./Src/AP/AP_main.o 

C_DEPS += \
./Src/AP/AP_main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/AP/%.o Src/AP/%.su Src/AP/%.cyclo: ../Src/AP/%.c Src/AP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250619_LedBar/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250619_LedBar/Src/driver" -I"C:/harman/STM32Cube/20250619_LedBar/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250619_LedBar/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250619_LedBar/Src/AP" -I"C:/harman/STM32Cube/20250619_LedBar/Src/driver/button" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-AP

clean-Src-2f-AP:
	-$(RM) ./Src/AP/AP_main.cyclo ./Src/AP/AP_main.d ./Src/AP/AP_main.o ./Src/AP/AP_main.su

.PHONY: clean-Src-2f-AP

