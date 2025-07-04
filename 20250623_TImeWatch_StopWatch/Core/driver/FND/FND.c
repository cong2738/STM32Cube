/*
 * FND.c
 *
 *  Created on: Jun 20, 2025
 *      Author: kccistc
 */

/////include/////
#include "FND.h"

/////private/////
static int FND_Decode(int digitPos);
static void FND_DisOffAll();
static void FND_DisOff();
static void FND_DisOn(int pos);
static void FND_printDot(uint32_t digitPos);
static void FND_PrintDigit(int data);

typedef struct {
    GPIO_TypeDef* GPIO;
    uint32_t pinNum;
} SEG_GPIO_Type;

SEG_GPIO_Type FND_cmm[4] = {
    { GPIOA, GPIO_PIN_12 },
    { GPIOC, GPIO_PIN_5 },
    { GPIOC, GPIO_PIN_6 },
    { GPIOC, GPIO_PIN_8 }
};

SEG_GPIO_Type FND_seg[8] = {
    { GPIOA, GPIO_PIN_11 }, // A
    { GPIOB, GPIO_PIN_12 }, // B
    { GPIOB, GPIO_PIN_2 }, // C
    { GPIOB, GPIO_PIN_1 }, // D
    { GPIOB, GPIO_PIN_15 }, // E
    { GPIOB, GPIO_PIN_14 }, // F
    { GPIOB, GPIO_PIN_13 }, // G
    { GPIOC, GPIO_PIN_4 } // DP
};

enum { DIGIT1,
    DIGIT10,
    DIGIT100,
    DIGIT1000 };

static uint16_t fndDisplayNum = 0; // fnd main data(max 9999)
static uint16_t dotPos = 0b0000;

int FND_Decode(int digitPos)
{
    switch (digitPos) {
    case DIGIT1:
        return fndDisplayNum % 10;
    case DIGIT10:
        return fndDisplayNum / 10 % 10;
    case DIGIT100:
        return fndDisplayNum / 100 % 10;
    case DIGIT1000:
        return fndDisplayNum / 1000 % 10;
    default:
    }
    return 0;
}

void FND_DisOffAll()
{
    for (int i = 0; i < 4; ++i) {
        FND_DisOff(i);
    }
}

void FND_DisOff(int pos)
{
    HAL_GPIO_WritePin(FND_cmm[pos].GPIO, FND_cmm[pos].pinNum, RESET);
}

void FND_DisOn(int pos)
{
    HAL_GPIO_WritePin(FND_cmm[pos].GPIO, FND_cmm[pos].pinNum, SET);
}

void FND_printDot(uint32_t digitPos){
	if(dotPos & (1U << digitPos)) HAL_GPIO_WritePin(FND_seg[7].GPIO, FND_seg[7].pinNum, RESET);
}

void FND_PrintDigit(int digit)
{
    const uint8_t segFont[10] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F // 9
    };
    for (int i = 0; i < 8; ++i) {
        if (!(segFont[digit] & (1 << i)))
            HAL_GPIO_WritePin(FND_seg[i].GPIO, FND_seg[i].pinNum, SET);
        else
            HAL_GPIO_WritePin(FND_seg[i].GPIO, FND_seg[i].pinNum, RESET);
    }
}

/////public/////
// Write FndData
void FND_WriteData(uint32_t data, uint32_t dotPosition)
{
    fndDisplayNum = data;
    dotPos = dotPosition;
}

// Read FndData
uint16_t FND_ReadData()
{
    return fndDisplayNum;
}

// Display FndData
void FND_DisplayData()
{
    static int digitPos = DIGIT1;
    uint8_t digitD = FND_Decode(digitPos);
    // 인터럽트 발생시 한 자리씩 출력
    FND_DisOffAll();
    FND_PrintDigit(digitD);
    FND_printDot(digitPos);
    FND_DisOn(digitPos);
    digitPos = (digitPos + 1) % 4;
}
