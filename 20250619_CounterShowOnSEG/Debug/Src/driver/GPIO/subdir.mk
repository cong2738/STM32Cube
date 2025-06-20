################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/GPIO/GPIO.c 

OBJS += \
./Src/driver/GPIO/GPIO.o 

C_DEPS += \
./Src/driver/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/GPIO/%.o Src/driver/GPIO/%.su Src/driver/GPIO/%.cyclo: ../Src/driver/GPIO/%.c Src/driver/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/button" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/Seven_Segment" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/AP" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-GPIO

clean-Src-2f-driver-2f-GPIO:
	-$(RM) ./Src/driver/GPIO/GPIO.cyclo ./Src/driver/GPIO/GPIO.d ./Src/driver/GPIO/GPIO.o ./Src/driver/GPIO/GPIO.su

.PHONY: clean-Src-2f-driver-2f-GPIO

