/*
 * Presenter.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_H_
#define AP_PRESENTER_H_

#include "FND.h"
#include "Watch_Model.h"
#include "i2c.h"
#include "LCD.h"

void Presenter_OutData(Watch_t watchData);
void Presenter_Excute();
void Presenter_Init();

#endif /* AP_PRESENTER_H_ */
