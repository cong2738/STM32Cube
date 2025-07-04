/*
 * ap_main.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef AP_AP_MAIN_H_
#define AP_AP_MAIN_H_

#include "stm32f4xx_hal.h"
#include "LedBar.h"
#include "Button.h"
#include "FND.h"
#include "tim.h"
#include "TimeWatch.h"
#include "StopWatch.h"

int ap_main();
void ap_init();
void TIM2_IRQHandler(void);
void Clock();
void Stopwatch();

#endif /* AP_AP_MAIN_H_ */
