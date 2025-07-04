/*
 * Presenter.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#include "Presenter.h"
#include <string.h>
#include <stdio.h>
#include "usart.h"

static void Presenter_DispTimeWatch(Watch_t watchData);
static void Presenter_DispStopWatch(Watch_t watchData);
static void Presenter_DisTimeWatchFnd(Watch_t watchData);
static void Presenter_DisStopWatchFnd(Watch_t watchData);
static void Presenter_DisMonitorTimeWatch(Watch_t watchData);
static void Presenter_DisMonitorStopWatch(Watch_t watchData);

static Watch_t dispData = {TIME_WATCH, 12, 0, 0, 0};

void Presenter_OutData(Watch_t watchData)
{
	//dispData.id = watchData.id;
	memcpy(&dispData, &watchData, sizeof(Watch_t));
}
void Presenter_Excute()
{
	if (dispData.id == TIME_WATCH) {
		Presenter_DispTimeWatch(dispData);
	} else { // STOP_WATCH
		Presenter_DispStopWatch(dispData);
	}
}

void Presenter_DispTimeWatch(Watch_t watchData)
{
	Presenter_DisTimeWatchFnd(watchData);
	Presenter_DisMonitorTimeWatch(watchData);
}
void Presenter_DispStopWatch(Watch_t watchData)
{
	Presenter_DisStopWatchFnd(watchData);
	Presenter_DisMonitorStopWatch(watchData);
}

void Presenter_DisTimeWatchFnd(Watch_t watchData){
	FND_WriteData(watchData.hour*100 + watchData.min);
	FND_WriteDp(FND_DP_1000|FND_DP_10, FND_DP_OFF);
	if (watchData.msec < 500) {
		FND_WriteDp(FND_DP_100, FND_DP_ON);
	} else{
		FND_WriteDp(FND_DP_100, FND_DP_OFF);
	}
}

void Presenter_DisStopWatchFnd(Watch_t watchData){
	FND_WriteData(((watchData.min % 10)*1000) + (watchData.sec*10) + (watchData.msec/100));
	FND_WriteDp(FND_DP_100|FND_DP_1, FND_DP_OFF);

	if (watchData.msec%100 < 50) {
		FND_WriteDp(FND_DP_10, FND_DP_ON);
	}else{
		FND_WriteDp(FND_DP_10, FND_DP_OFF);
	}
	if (watchData.msec < 500) {
		FND_WriteDp(FND_DP_1000, FND_DP_ON);
	}else{
		FND_WriteDp(FND_DP_1000, FND_DP_OFF);
	}
}

void Presenter_DisMonitorTimeWatch(Watch_t watchData) {
	char str[50];
	sprintf(str, "Time Watch : %02d:%02d:%02d.%03d\n",watchData.hour, watchData.min, watchData.sec, watchData.msec);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, strlen(str), 1000);
}
void Presenter_DisMonitorStopWatch(Watch_t watchData) {
	char str[50];
	sprintf(str, "Stop Watch : %02d:%02d:%02d.%03d\n",watchData.hour, watchData.min, watchData.sec, watchData.msec);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, strlen(str), 1000);
}
