/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "ap_main.h"

enum { START,
	WATCH,
	STOPWATCH_STOP,
	STOPWATCH_RUN,
	STOPWATCH_CLEAR
};

typedef struct {
	uint16_t msec;
	uint16_t sec;
	uint16_t min;
}clock_type;

typedef struct {
	uint16_t msec;
	uint16_t sec;
	uint16_t min;
}stopwatch_type;

button_handler_t hBtnA;
button_handler_t hBtnB;
button_handler_t hBtnC;

void TIM2_IRQHandler(void) // 인터럽트 함수 Startup가보면 인터럽트벡터등 이름이 명시되어 있음
{
	incTick();
	FND_DisplayData();
	TIM_ClearUIF(TIM2);
}

int ap_main()
{
	clock_type clock;
	stopwatch_type stopwatch;
	uint32_t ap_state = START;
	uint32_t SW_run = 0;
	uint32_t dp = 0;
	clock.msec = 0;
	clock.sec = 0;
	clock.min = 0;
	stopwatch.msec = 0;
	stopwatch.sec = 0;
	stopwatch.min = 0;
	uint32_t prevCNT_clock = 0;
	uint32_t prevCNT_SW = 0;

	while (1) {
		if(getTick() - prevCNT_clock >= 100) {
			prevCNT_clock = getTick();
			clock.msec++;

			if(clock.msec == 10){
				clock.msec = 0;
				clock.sec++;
			}
			if(clock.sec == 60){
				clock.sec = 0;
				clock.min++;
			}
			if(clock.min == 60){
				clock.min = 0;
			}
		}
		if(SW_run && getTick() - prevCNT_SW >= 100) {
			prevCNT_SW = getTick();
			stopwatch.msec ++;

			if(stopwatch.msec == 10){
				stopwatch.msec = 0;
				stopwatch.sec++;
			}
			if(stopwatch.sec == 60){
				stopwatch.sec = 0;
				stopwatch.min++;
			}
			if(stopwatch.min == 60){
				stopwatch.min = 0;
			}
		}
		dp = 0;

		switch (ap_state) {
		case START:
			ap_state = WATCH;
			break;
		case WATCH:
			if(clock.sec % 10 >= 5) dp ^= (1U<<2);
			FND_WtireData(clock.sec + clock.min*100, dp);
			if (Button_GetState(&hBtnA) == ACT_PUSHED) {
				ap_state = SW_run ? STOPWATCH_RUN : STOPWATCH_STOP;
			}
			break;
		case STOPWATCH_RUN:
			SW_run= 1;
			if(stopwatch.msec >= 5) dp ^= (1U<<1);
			if(stopwatch.sec % 10 >= 5) dp ^= (1U<<3);
			FND_WtireData(stopwatch.msec+stopwatch.sec*10+stopwatch.min*1000, dp);
			if (Button_GetState(&hBtnA) == ACT_PUSHED) {
				ap_state = WATCH;
			} else if (Button_GetState(&hBtnB) == ACT_PUSHED) {
				ap_state = STOPWATCH_STOP;
			}
			break;
		case STOPWATCH_STOP:
			SW_run = 0;
			prevCNT_SW = getTick();
			if(stopwatch.msec >= 5) dp ^= (1U<<1);
			if(stopwatch.sec % 10 >= 5) dp ^= (1U<<3);
			FND_WtireData(stopwatch.msec+stopwatch.sec*10+stopwatch.min*1000, dp);
			if (Button_GetState(&hBtnA) == ACT_PUSHED) {
				ap_state = WATCH;
			} else if (Button_GetState(&hBtnB) == ACT_PUSHED) {
				ap_state = STOPWATCH_RUN;
			} else if (Button_GetState(&hBtnC) == ACT_PUSHED) {
				ap_state = STOPWATCH_CLEAR;
			}
			break;
		case STOPWATCH_CLEAR:
			ap_state = STOPWATCH_STOP;
			stopwatch.msec = 0;
			stopwatch.sec = 0;
			stopwatch.min = 0;
			break;
		}

	}
	return 0;
}

void ap_init()
{
	SystemClock_init();
	LedBar_Init();
	Button_Init(&hBtnA, GPIOB, 5);
	Button_Init(&hBtnB, GPIOB, 3);
	Button_Init(&hBtnC, GPIOA, 10);
	FND_Init();

	//TIM2 EN, TIM2INTRF
	TIM_Init(TIM2, 16 - 1, 1000 - 1);
	TIM_CntStart(TIM2);
	TIM_UIEnable(TIM2);
	NVIC_EnableIRQ(TIM2_IRQn); // TIM2 interruft EN
}
