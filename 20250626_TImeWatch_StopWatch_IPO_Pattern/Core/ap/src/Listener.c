/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#include "Listener.h"
#include <string.h>
#include "Button.h"
#include "usart.h"

static void Listener_CheckButton();
static void Listener_CheckUART();

static uint8_t rxData = 0;
static CircleQue_tpye uartRxQue = {0};

void Listener_Init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
	HAL_UART_Receive_IT(&huart2, &rxData, 1); // uart recv interrupt enable(UART IT initializing)
	queInit(&uartRxQue);
}

void Listener_Excute()
{
	Listener_CheckButton();
	Listener_CheckUART();
}

void Listener_CheckButton() { // check button state
	static uint32_t chkBtnTime = 0;
	uint32_t curTick = HAL_GetTick();

	if(curTick - chkBtnTime < 10) return;
	chkBtnTime = curTick;

	inputData_TypeDef inputData;

	if (Button_GetState(&hBtnMode)== ACT_RELEASED) {
		inputData.id = controlId_MODE;
		inputData.data = controlData_MODE_ACT;
		Controller_SetInputData(inputData);
		return;
	}
	if (Button_GetState(&hBtnRunStop)== ACT_PUSHED) {
		inputData.id = controlId_RUN_STOP;
		inputData.data = controlData_STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		return;
	}
	if (Button_GetState(&hBtnClear)== ACT_PUSHED) {
		inputData.id = controlId_BTN_CLEAR;
		inputData.data = controlData_STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		return;
	}
}

void Listener_CheckUART() { // check UART rxData
	if(isQueEmpty(&uartRxQue)) return; // check UART rxFlag
	int uartRxData = (int) deQue(&uartRxQue);

	inputData_TypeDef inputData;

	if (uartRxData == 'm') {
		inputData.id = controlId_MODE;
		inputData.data = controlData_MODE_ACT;
		Controller_SetInputData(inputData);
		return;
	}
	if (uartRxData== 'r') {
		inputData.id = controlId_RUN_STOP;
		inputData.data = controlData_STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		return;
	}
	if (uartRxData == 's') {
		inputData.id = controlId_RUN_STOP;
		inputData.data = controlData_STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		return;
	}
	if (uartRxData == 'c') {
		inputData.id = controlId_BTN_CLEAR;
		inputData.data = controlData_STOPWATCH_ACT;
		Controller_SetInputData(inputData);
		return;
	}
}

void Listener_UartCallBack() {
	HAL_UART_Receive_IT(&huart2, &rxData, 1);  //interrupt en
	enQue(&uartRxQue, (void*) rxData);
}
