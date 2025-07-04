/*
 * FND.c
 *
 *  Created on: Jun 20, 2025
 *      Author: kccistc
 */

#include "FND.h"

// private
static int FND_Decode(int digitPos);
static void FND_DisOffAll();
static void FND_DisOff();
static void FND_DisOn(int pos);
static void FND_DisDigit(int data);

typedef struct {
    GPIO_TypeDef* GPIO;
    uint32_t pinNum;
} SEG_GPIO_Type;

SEG_GPIO_Type FND_cmm[4] = {
    { GPIOA, 12 },
    { GPIOC, 5 },
    { GPIOC, 6 },
    { GPIOC, 8 }
};

SEG_GPIO_Type FND_seg[8] = {
    { GPIOA, 11 }, // A
    { GPIOB, 12 }, // B
    { GPIOB, 2 }, // C
    { GPIOB, 1 }, // D
    { GPIOB, 15 }, // E
    { GPIOB, 14 }, // F
    { GPIOB, 13 }, // G
    { GPIOC, 4 } // DP
};

enum { DIGIT1,
    DIGIT10,
    DIGIT100,
    DIGIT1000 };

static uint16_t fndDisplayNum = 0; // fnd main data(max 9999)

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
    GPIO_WritePin(FND_cmm[pos].GPIO, FND_cmm[pos].pinNum, PIN_RESET);
}

void FND_DisOn(int pos)
{
    GPIO_WritePin(FND_cmm[pos].GPIO, FND_cmm[pos].pinNum, PIN_SET);
}

void FND_DisDigit(int digit)
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
            GPIO_WritePin(FND_seg[i].GPIO, FND_seg[i].pinNum, PIN_SET);
        else
            GPIO_WritePin(FND_seg[i].GPIO, FND_seg[i].pinNum, PIN_RESET);
    }
}

/////public/////
// initializing FND
void FND_Init()
{
    for (int i = 0; i < 4; ++i) {
        GPIO_Init(FND_cmm[i].GPIO, FND_cmm[i].pinNum, OUTPUT);
    }
    for (int i = 0; i < 8; ++i) {
        GPIO_Init(FND_seg[i].GPIO, FND_seg[i].pinNum, OUTPUT);
    }
}

// Write FndData
void FND_WtireData(uint32_t data)
{
    fndDisplayNum = data;
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
    FND_DisDigit(digitD);
    FND_DisOn(digitPos);
    digitPos = (digitPos + 1) % 4;
}
