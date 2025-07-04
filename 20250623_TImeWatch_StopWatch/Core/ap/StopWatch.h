/*
 * StopWatch.h
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */

#ifndef AP_STOPWATCH_H_
#define AP_STOPWATCH_H_

#include "FND.h"
#include "Button.h"
#include "ap_main.h"

extern Button_Handler_t hBtnMode;
extern Button_Handler_t hBtnRunStop;
extern Button_Handler_t hBtnClear;

void StopWatch_IncTimeCallBack();
void StopWatch_Excute();

#endif /* AP_STOPWATCH_H_ */
