/* ap_main.c */

#include "ap_main.h"
#include <stdbool.h>



volatile uint8_t dotBlink = 0;
volatile uint16_t blinkTick = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		FND_DispDataCallBack();

		TimeWatch_IncTimeCallBack();
		StopWatch_IncstopCallBack();
	}
}

int ap_main()
{
	HAL_TIM_Base_Start_IT(&htim2);
	while (1) {
		Listener_Excute();
		Controller_Excute();
		Presenter_Excute();
	}
	return 0;
}
void ap_init(void)
{
	Listener_Init();
}
