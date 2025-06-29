################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/src/Controller.c \
../Core/ap/src/Listener.c \
../Core/ap/src/Presenter.c \
../Core/ap/src/ap_main.c \
../Core/ap/src/stopWatch.c \
../Core/ap/src/timeWatch.c 

OBJS += \
./Core/ap/src/Controller.o \
./Core/ap/src/Listener.o \
./Core/ap/src/Presenter.o \
./Core/ap/src/ap_main.o \
./Core/ap/src/stopWatch.o \
./Core/ap/src/timeWatch.o 

C_DEPS += \
./Core/ap/src/Controller.d \
./Core/ap/src/Listener.d \
./Core/ap/src/Presenter.d \
./Core/ap/src/ap_main.d \
./Core/ap/src/stopWatch.d \
./Core/ap/src/timeWatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/src/%.o Core/ap/src/%.su Core/ap/src/%.cyclo: ../Core/ap/src/%.c Core/ap/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/ap" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/driver/Button" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/driver/FND" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/driver/LedBar" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/ap/Inc" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/ap/src" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/data_structure/circled_que" -I"C:/harman/STM32Cube/20250626_TImeWatch_StopWatch_IPO_Pattern/Core/driver/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-src

clean-Core-2f-ap-2f-src:
	-$(RM) ./Core/ap/src/Controller.cyclo ./Core/ap/src/Controller.d ./Core/ap/src/Controller.o ./Core/ap/src/Controller.su ./Core/ap/src/Listener.cyclo ./Core/ap/src/Listener.d ./Core/ap/src/Listener.o ./Core/ap/src/Listener.su ./Core/ap/src/Presenter.cyclo ./Core/ap/src/Presenter.d ./Core/ap/src/Presenter.o ./Core/ap/src/Presenter.su ./Core/ap/src/ap_main.cyclo ./Core/ap/src/ap_main.d ./Core/ap/src/ap_main.o ./Core/ap/src/ap_main.su ./Core/ap/src/stopWatch.cyclo ./Core/ap/src/stopWatch.d ./Core/ap/src/stopWatch.o ./Core/ap/src/stopWatch.su ./Core/ap/src/timeWatch.cyclo ./Core/ap/src/timeWatch.d ./Core/ap/src/timeWatch.o ./Core/ap/src/timeWatch.su

.PHONY: clean-Core-2f-ap-2f-src

