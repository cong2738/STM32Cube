#include "AP_main.h"

typedef enum {
	STOP,
	RUN,
	CLEAR
}led_state_e;

button_handler_t hBtnRUN;
button_handler_t hBtnCLEAR;
button_handler_t hBtOnSTOP;

int ap_run(){
	uint32_t data = 0;
	uint32_t UD = 0;
	uint32_t sys_count = 0;
	led_state_e led_state = STOP;
	while(1){
		int Btn1_state = Button_GetState(&hBtnRUN);
		int Btn2_state = Button_GetState(&hBtOnSTOP);
		int Btn3_state = Button_GetState(&hBtnCLEAR);
		switch (led_state) {
		case STOP:
			UD = 0;
			if(Btn1_state == ACT_PUSHED) led_state = RUN;
			else if (Btn3_state == ACT_PUSHED) led_state = CLEAR;
			break;
		case RUN:
			UD = 1;
			if(Btn2_state == ACT_PUSHED) led_state = STOP;
			break;
		case CLEAR:
			UD = 0;
			data = 0;
			led_state = STOP;
			break;
		}
		SEG_SHOW(data);
		sys_count++;
		if(sys_count == 1000) {
			sys_count = 0;
			data += UD;
			if(data == 10000) data = 0;
		}
	}
	return 0 ;
}

void ap_init(){
	SystemClock_init();
	Button_Init(&hBtnRUN, GPIOB, 5);
	Button_Init(&hBtnCLEAR, GPIOB, 3);
	Button_Init(&hBtOnSTOP, GPIOA, 10);
	SEG_Init();
}
