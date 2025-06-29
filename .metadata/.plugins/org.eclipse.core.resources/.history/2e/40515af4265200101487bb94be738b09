/*
 * Controller.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_H_
#define AP_CONTROLLER_H_

#include "timeWatch.h"
#include "stopWatch.h"

enum{
	controlId_NO_CONTROL,
	controlId_MODE,
	controlId_RUN_STOP,
	controlId_STOP,
	controlId_RUN,
	controlId_BTN_CLEAR
};

enum{
	controlData_MODE_NO_ACT,
	controlData_MODE_ACT,
	controlData_STOPWATCH_NO_ACT,
	controlData_STOPWATCH_ACT
};

typedef struct{
	int id;
	int data;
}inputData_TypeDef;


void Controller_SetInputData(inputData_TypeDef inputData);
void Controller_Excute();
void Controller_Mode();

#endif /* AP_CONTROLLER_H_ */
