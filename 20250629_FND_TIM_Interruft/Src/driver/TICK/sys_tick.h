/*
 * sys_tic.h
 *
 *  Created on: Jun 20, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_TICK_SYS_TICK_H_
#define DRIVER_TICK_SYS_TICK_H_

#include  <stdint.h>
#include "stm32f411xe.h"

uint32_t getTick();
void incTick();

#endif /* DRIVER_TICK_SYS_TICK_H_ */
