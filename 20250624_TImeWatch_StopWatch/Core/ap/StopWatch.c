#include "stopWatch.h"

typedef enum {STOP, RUN, CLEAR} stopwatch_state_t;

typedef struct{
	uint16_t msec;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
}stopWatch_t;

stopWatch_t stopWatch = {0};
uint32_t stopWatchDotData = 0b0000;

stopwatch_state_t stopWatchState = STOP;

void StopWatch_IncTime();
void StopWatch_Stop();
void StopWatch_Run();
void StopWatch_Clear();
void StopWatchDotBlink();

void StopWatch_IncTime()
{
	if(stopWatch.msec < 1000 - 1){
		stopWatch.msec++;
		return;
	}
	stopWatch.msec = 0;

	if(stopWatch.sec < 60 - 1){
		stopWatch.sec++;
		return;
	}
	stopWatch.sec = 0;

	if(stopWatch.min < 60 - 1){
		stopWatch.min++;
		return;
	}
	stopWatch.min = 0;

	if(stopWatch.hour < 24 - 1){
		stopWatch.hour++;
		return;
	}
	stopWatch.hour = 0;
}


void StopWatch_Stop()
{
	if(Button_GetState(&hBtnRunStop) == ACT_PUSHED ){
		stopWatchState = RUN;
	}
	else if (Button_GetState(&hBtnClear) == ACT_PUSHED ){
		stopWatchState = CLEAR;
	}
}

void StopWatch_Run()
{
	if (Button_GetState(&hBtnRunStop) == ACT_PUSHED ){
		stopWatchState = STOP;
	}
}

void StopWatch_Clear()
{
	stopWatchState = STOP;
	stopWatch.msec = 0;
	stopWatch.sec = 0;
	stopWatch.min = 0;
	stopWatch.hour = 0;
}

void StopWatchDotBlink(){
	stopWatchDotData = 0b0000;
	if((stopWatch.msec%100) > 50) stopWatchDotData |= (1U << 1);
	if((stopWatch.msec%1000) > 500) stopWatchDotData |= (1U << 3);
}

///// public /////
void StopWatch_Execute()
{
	switch(stopWatchState) {
	case  STOP :
		StopWatch_Stop();
		break;
	case  RUN :
		StopWatch_Run();
		break;
	case CLEAR :
		StopWatch_Clear();
		break;
	}
	StopWatchDotBlink();
	FND_WriteData(((stopWatch.min % 10)* 1000) + (stopWatch.sec*10) + (stopWatch.msec/100), stopWatchDotData);
}

void StopWatch_IncTimeCallBack()
{
	if(stopWatchState == RUN){ //RU
		StopWatch_IncTime();
	}
}
