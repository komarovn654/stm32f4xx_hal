#pragma once

#include "system/hal_system.h"

#define ERROR_GROUP_RCC 0x00

typedef enum ErrorRCC
{
    unknown = 0,
} ErrorRCC;

#define ERROR_CODE_RCC(num) (ERROR_CODE(ERROR_CODE_RCC, num))

typedef struct RccPLLCFGR
{
    volatile uint32_t reserved1 : 4;
    volatile uint32_t pllq      : 4;
    volatile uint32_t reserved2 : 1;
    volatile uint32_t pllsrc    : 1;
    volatile uint32_t reserved3 : 4;
    volatile uint32_t pllp      : 2; 
    volatile uint32_t reserved4 : 1;
    volatile uint32_t plln      : 9;
    volatile uint32_t pllm      : 6;
} RccPLLCFGR;

typedef enum SystemClockSource
{
    SCS_HSI = 0,
    SCS_HSE = 1,
    SCS_PLLCLK = 2,
} SystemClockSource;

typedef enum PllSource
{
    PS_HSI = 0,
    PS_HSE = 1,
} PllSource;

#define HSI_FREQUENCY 16000000UL
#ifndef HSE_FREQUENCY
#define HSE_FREQUENCY 0
#endif