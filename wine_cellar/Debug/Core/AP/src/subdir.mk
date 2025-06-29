################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/AP/src/Controller.c \
../Core/AP/src/Listener.c \
../Core/AP/src/Presenter.c \
../Core/AP/src/ap_main.c \
../Core/AP/src/queue.c \
../Core/AP/src/sound.c \
../Core/AP/src/stopWatch.c \
../Core/AP/src/timeWatch.c 

OBJS += \
./Core/AP/src/Controller.o \
./Core/AP/src/Listener.o \
./Core/AP/src/Presenter.o \
./Core/AP/src/ap_main.o \
./Core/AP/src/queue.o \
./Core/AP/src/sound.o \
./Core/AP/src/stopWatch.o \
./Core/AP/src/timeWatch.o 

C_DEPS += \
./Core/AP/src/Controller.d \
./Core/AP/src/Listener.d \
./Core/AP/src/Presenter.d \
./Core/AP/src/ap_main.d \
./Core/AP/src/queue.d \
./Core/AP/src/sound.d \
./Core/AP/src/stopWatch.d \
./Core/AP/src/timeWatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/AP/src/%.o Core/AP/src/%.su Core/AP/src/%.cyclo: ../Core/AP/src/%.c Core/AP/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/harman/STM32Cube/wine_cellar/Core/driver/Button" -I"C:/harman/STM32Cube/wine_cellar/Core/driver/buzzer" -I"C:/harman/STM32Cube/wine_cellar/Core/driver/FND" -I"C:/harman/STM32Cube/wine_cellar/Core/driver/LCD" -I"C:/harman/STM32Cube/wine_cellar/Core/driver/LedBar" -I"C:/harman/STM32Cube/wine_cellar/Core/AP/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-AP-2f-src

clean-Core-2f-AP-2f-src:
	-$(RM) ./Core/AP/src/Controller.cyclo ./Core/AP/src/Controller.d ./Core/AP/src/Controller.o ./Core/AP/src/Controller.su ./Core/AP/src/Listener.cyclo ./Core/AP/src/Listener.d ./Core/AP/src/Listener.o ./Core/AP/src/Listener.su ./Core/AP/src/Presenter.cyclo ./Core/AP/src/Presenter.d ./Core/AP/src/Presenter.o ./Core/AP/src/Presenter.su ./Core/AP/src/ap_main.cyclo ./Core/AP/src/ap_main.d ./Core/AP/src/ap_main.o ./Core/AP/src/ap_main.su ./Core/AP/src/queue.cyclo ./Core/AP/src/queue.d ./Core/AP/src/queue.o ./Core/AP/src/queue.su ./Core/AP/src/sound.cyclo ./Core/AP/src/sound.d ./Core/AP/src/sound.o ./Core/AP/src/sound.su ./Core/AP/src/stopWatch.cyclo ./Core/AP/src/stopWatch.d ./Core/AP/src/stopWatch.o ./Core/AP/src/stopWatch.su ./Core/AP/src/timeWatch.cyclo ./Core/AP/src/timeWatch.d ./Core/AP/src/timeWatch.o ./Core/AP/src/timeWatch.su

.PHONY: clean-Core-2f-AP-2f-src

