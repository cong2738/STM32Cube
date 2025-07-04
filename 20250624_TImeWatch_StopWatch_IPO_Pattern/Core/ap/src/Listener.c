/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#include "Listener.h"
#include <string.h>

static void Listener_CheckButton();
static void Listener_GetRX();

void Listener_Init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
}

void Listener_Excute()
{
	Listener_CheckButton(); // Button이 단순히 눌렸는지만 판단하는 함수
	Listener_GetRX();
}

void Listener_CheckButton(){ // 그때 버튼이 입력됨에 따라 어떻게 동작하는 지 보여주는 함수
	inputData_TypeDef inputData;

	if (Button_GetState(&hBtnMode)== ACT_RELEASED) {
		inputData.id = controlId_MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnRunStop)== ACT_PUSHED) {
		inputData.id = controlId_RUN_STOP;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnClear)== ACT_PUSHED) {
		inputData.id = controlId_BTN_CLEAR;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
	}
}

void Listener_GetRX() {
	inputData_TypeDef inputData;
	char inputStr[1];
	HAL_UART_Receive(&huart2, (uint8_t*) inputStr, sizeof(inputStr), 10);
	switch (inputStr[0]) {
	case 'm':
		inputData.id = controlId_MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);
		break;
	case 'r':
		inputData.id = controlId_RUN;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		break;
	case 's':
		inputData.id = controlId_STOP;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		break;
	case 'c':
		inputData.id = controlId_BTN_CLEAR;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		break;
	}
}
