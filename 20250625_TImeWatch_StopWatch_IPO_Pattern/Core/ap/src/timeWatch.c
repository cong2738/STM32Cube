/*
 * timeWatch.c
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */

#include "timeWatch.h"


static Watch_t timeWatch = {TIME_WATCH, 12,0,0,0};

Watch_t get_timewatch(){
	return timeWatch;
}

void TimeWatch_IncTimeCallBack() //interrupt에 들어가는 함수(interrupt로 인하여 갑자기 실행됨?)
{
	if (timeWatch.msec < 1000 - 1) {
		timeWatch.msec++;
		return;
	} else {
		timeWatch.msec = 0;
	}
	if (timeWatch.sec < 60 - 1) {
		timeWatch.sec++;
		return;
	} else{
		timeWatch.sec = 0;
	}

	if (timeWatch.min < 60 - 1) {
		timeWatch.min++;
		return;
	}
	timeWatch.min = 0;

	if (timeWatch.hour < 24 - 1) {
		timeWatch.hour++;
		return;
	}
	timeWatch.hour = 0;
}
