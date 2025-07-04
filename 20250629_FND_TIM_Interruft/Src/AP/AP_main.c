/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "ap_main.h"

enum { OFF,
    LEFT,
    RIGHT };

button_handler_t hBtnLeft;
button_handler_t hBtnRight;
button_handler_t hBtnOnOff;

void TIM2_IRQHandler(void) // 인터럽트 함수 Startup가보면 인터럽트벡터등 이름이 명시되어 있음
{
	incTick();
    FND_DisplayData();
    TIM_ClearUIF(TIM2);
}

int ap_main()
{

    uint16_t counter = 0;
    uint32_t prevCounterTime = 0;
    while (1) {
    	if(getTick() - prevCounterTime >= 1000) {
    		prevCounterTime = getTick();
    		FND_WtireData(counter++);
    	}
//        switch (led_state) {
//        case OFF:
//            if (Button_GetState(&hBtnLeft) == ACT_PUSHED) {
//                led_state = LEFT;
//            } else if (Button_GetState(&hBtnRight) == ACT_PUSHED) {
//                led_state = RIGHT;
//            }
//            LedBar_Write(0);
//            break;
//        case LEFT:
//            data = (data << 1) | (data >> 7);
//            if (Button_GetState(&hBtnOnOff) == ACT_PUSHED) {
//                led_state = OFF;
//            } else if (Button_GetState(&hBtnRight) == ACT_PUSHED) {
//                led_state = RIGHT;
//            }
//            LedBar_Write(data);
//            break;
//        case RIGHT:
//            data = (data >> 1) | (data << 7);
//            if (Button_GetState(&hBtnOnOff) == ACT_PUSHED) {
//                led_state = OFF;
//            } else if (Button_GetState(&hBtnLeft) == ACT_PUSHED) {
//                data = 1;
//                led_state = LEFT;
//            }
//            LedBar_Write(data);
//            break;
//        }
    }

    return 0;
}

void ap_init()
{
    SystemClock_init();
    LedBar_Init();
    Button_Init(&hBtnLeft, GPIOB, 5);
    Button_Init(&hBtnRight, GPIOB, 3);
    Button_Init(&hBtnOnOff, GPIOA, 10);
    FND_Init();

    //TIM2 EN, TIM2INTRF
    TIM_Init(TIM2, 16 - 1, 1000 - 1);
    TIM_CntStart(TIM2);
    TIM_UIEnable(TIM2);
    NVIC_EnableIRQ(TIM2_IRQn); // TIM2 interruft EN
}
