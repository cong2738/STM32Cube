/*
 * stopWatch.h
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */

#ifndef AP_STOPWATCH_H_
#define AP_STOPWATCH_H_
#include "Watch_Model.h"
#include "stm32f4xx_hal.h"
#include "Controller.h"
#include "Presenter.h"

typedef enum{STOP, RUN, CLEAR}stopWatch_s;

Watch_t get_stopwatch();
stopWatch_s get_stopwatchState();
void StopWatch_IncstopCallBack();
void StopWatch_Incstop();
void StopWatch_Excute();
void StopWatch_Stop();
void StopWatch_Run();
void StopWatch_Clear();

#endif /* AP_STOPWATCH_H_ */
