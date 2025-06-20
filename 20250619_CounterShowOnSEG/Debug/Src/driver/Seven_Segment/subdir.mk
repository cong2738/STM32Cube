################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/Seven_Segment/Seven_Segment.c 

OBJS += \
./Src/driver/Seven_Segment/Seven_Segment.o 

C_DEPS += \
./Src/driver/Seven_Segment/Seven_Segment.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/Seven_Segment/%.o Src/driver/Seven_Segment/%.su Src/driver/Seven_Segment/%.cyclo: ../Src/driver/Seven_Segment/%.c Src/driver/Seven_Segment/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/button" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/GPIO" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/LedBar" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/Seven_Segment" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/driver/SystemClock" -I"C:/harman/STM32Cube/20250619_CounterShowOnSEG/Src/AP" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-Seven_Segment

clean-Src-2f-driver-2f-Seven_Segment:
	-$(RM) ./Src/driver/Seven_Segment/Seven_Segment.cyclo ./Src/driver/Seven_Segment/Seven_Segment.d ./Src/driver/Seven_Segment/Seven_Segment.o ./Src/driver/Seven_Segment/Seven_Segment.su

.PHONY: clean-Src-2f-driver-2f-Seven_Segment

