/*
 * Controller.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#include "Controller.h"

static watchModeState_t modeState = TIME_WATCH;
inputData_TypeDef controlData = {0};

void Controller_Excute()
{
	Controller_Mode();
}

void Controller_SetInputData(inputData_TypeDef inputData)
{
	if (inputData.id == controlId_MODE) {
		controlData.id = controlId_MODE;
		controlData.data = controlData_MODE_ACT;
	}
	else if (inputData.id == controlId_RUN_STOP) {
		controlData.id = controlId_RUN_STOP;
		controlData.data = controlData_STOPWATCH_ACT;
	}
	else if (inputData.id == controlId_RUN) {
		controlData.id = controlId_RUN;
		controlData.data = controlData_STOPWATCH_ACT;
	}
	else if (inputData.id == controlId_STOP) {
		controlData.id = controlId_STOP;
		controlData.data = controlData_STOPWATCH_ACT;
	}
	else if (inputData.id == controlId_BTN_CLEAR) {
		controlData.id = controlId_BTN_CLEAR;
		controlData.data = controlData_STOPWATCH_ACT;
	}
}

void Controller_Mode()
{
	switch (modeState) {
	case TIME_WATCH:
		if (controlData.id == controlId_MODE) {
			controlData.id = controlId_NO_CONTROL;
			modeState = STOP_WATCH;
		}
		TimeWatch_Excute();
		break;
	case STOP_WATCH:
		if (controlData.id == controlId_MODE) {
			controlData.id = controlId_NO_CONTROL;
			modeState = TIME_WATCH;
		} else if (controlData.id == controlId_MODE) {
			controlData.id = controlId_NO_CONTROL;
			modeState = STOP_WATCH;
		} else if (controlData.id == controlId_MODE) {
			controlData.id = controlId_NO_CONTROL;
			modeState = STOP_WATCH;
		}
		StopWatch_Excute();
		break;
	}
}
