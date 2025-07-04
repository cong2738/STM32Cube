/*
 * Seven_Segment.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */
#include "Seven_Segment.h"

//private
int Decode(int data, int cmm);
int SegDecode(int data, int cmm);
int bcd_slice(int data, int cmm);
int DataDecodeToSeg(int num);
int decode_CMM();

typedef struct {
	GPIO_TypeDef* GPIO;
	uint32_t pinNum;
}SEG_GPO;

SEG_GPO CMM[4] ={
		{GPIOC,8},
		{GPIOC,6},
		{GPIOC,5},
		{GPIOA,12}
};

SEG_GPO SEG[8] = {
		{GPIOA,11},
		{GPIOB,12},
		{GPIOB,2},
		{GPIOB,1},
		{GPIOB,15},
		{GPIOB,14},
		{GPIOB,13},
		{GPIOC,4}
};

int Decode(int data, int cmm){
	int d = bcd_slice(data, cmm);
	return DataDecodeToSeg(d);
}

int bcd_slice(int data, int cmm){
	switch (cmm) {
	case 0: return data / 1000 % 10;
	case 1: return data / 100 % 10;
	case 2: return data / 10 % 10;
	case 3: return data / 1 % 10;
	}
	return 0;
}

int DataDecodeToSeg(int num){
	switch (num) {
	case 0x0: return 0xc0;
	case 0x1: return 0xf9;
	case 0x2: return 0xa4;
	case 0x3: return 0xb0;
	case 0x4: return 0x99;
	case 0x5: return 0x92;
	case 0x6: return 0x82;
	case 0x7: return 0xf8;
	case 0x8: return 0x80;
	case 0x9: return 0x90;
	case 0xa: return 0x88;
	case 0xb: return 0x83;
	case 0xc: return 0xc6;
	case 0xd: return 0xa1;
	case 0xe: return 0x86;
	case 0xf: return 0x8e;
	}
	return 0xff;
}

int decode_CMM(){
	static int SEG_count = 0;
	int cmm = 0;
	if(SEG_count  < 40){
		cmm = 0;
	} else if(SEG_count  < 80){
		cmm = 1;
	} else if(SEG_count  < 120) {
		cmm = 2;
	} else if(SEG_count  < 160){
		cmm = 3;
	}
	if(++SEG_count  == 160) SEG_count = 0;
	return cmm;
}

// public
void SEG_Init(){
	for (int var = 0; var < 4; var++) {
		GPIO_Init(CMM[var].GPIO,CMM[var].pinNum, OUTPUT);
	}
	for (int var = 0; var < 8; var++) {
		GPIO_Init(SEG[var].GPIO,SEG[var].pinNum, OUTPUT);
	}
}

void SEG_SHOW(int data){
	int cmm = decode_CMM();
	int seg_data = Decode(data, cmm);
	for (int i = 0; i < 4; i++) { // DisEnable ALL 7-Segments
		GPIO_WritePin(CMM[i].GPIO, CMM[i].pinNum, PIN_RESET);
	}
	for (int i = 0; i < 8; i++) { // Turn ON LEDs
		int pin_data = (seg_data & (1U << i))?1:0;
		GPIO_WritePin(SEG[i].GPIO, SEG[i].pinNum, ((pin_data)?PIN_SET:PIN_RESET));
	}
	GPIO_WritePin(CMM[cmm].GPIO, CMM[cmm].pinNum, PIN_SET); // Enable one of 7-Segments
}

void SEG_Write(uint32_t data){
	for (int var = 0; var < 8; var++) {
		if ((data & (1<<var)) == 0) {
			GPIO_WritePin(SEG[var].GPIO, SEG[var].pinNum, PIN_RESET);
		} else {
			GPIO_WritePin(SEG[var].GPIO, SEG[var].pinNum, PIN_SET);
		}
	}
}
