/*
 * FND.h
 *
 *  Created on: Jun 20, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_FND_FND_H_
#define DRIVER_FND_FND_H_

#include "stm32f4xx_hal.h"

void FND_WriteData(uint32_t data, uint32_t dotPosition);
uint16_t FND_ReadData();
void FND_DisplayData();

#endif /* DRIVER_FND_FND_H_ */
