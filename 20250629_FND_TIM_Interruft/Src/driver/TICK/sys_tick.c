/*
 * sys_tic.c
 *
 *  Created on: Jun 20, 2025
 *      Author: kccistc
 */

#include "sys_tick.h"

static uint32_t tick;

uint32_t getTick(){
	return tick;
}

void incTick(){
	tick++;
}
