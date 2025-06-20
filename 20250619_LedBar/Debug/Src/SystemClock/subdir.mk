################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/SystemClock/SystemClock.c 

OBJS += \
./Src/SystemClock/SystemClock.o 

C_DEPS += \
./Src/SystemClock/SystemClock.d 


# Each subdirectory must supply rules for building sources it contributes
Src/SystemClock/%.o Src/SystemClock/%.su Src/SystemClock/%.cyclo: ../Src/SystemClock/%.c Src/SystemClock/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-SystemClock

clean-Src-2f-SystemClock:
	-$(RM) ./Src/SystemClock/SystemClock.cyclo ./Src/SystemClock/SystemClock.d ./Src/SystemClock/SystemClock.o ./Src/SystemClock/SystemClock.su

.PHONY: clean-Src-2f-SystemClock

