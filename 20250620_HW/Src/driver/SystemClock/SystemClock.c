/*
 * SystemClock.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "SystemClock.h"

void SystemClock_init()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // RCC_AHB1ENR
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // RCC_AHB1ENR
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // RCC_AHB1ENR
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // RCC_APB1ENR
}

void delay(uint32_t time)
{
    for (int var = 0; var < time; ++var) {
        for (int s = 0; s < 1000; ++s) {
        }
    }
}
