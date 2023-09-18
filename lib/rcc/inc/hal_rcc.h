#pragma once

#include "hal_system.h"

#define HSIRDY_TIMEOUT_NS (500)

#define ERROR_GROUP_RCC 0x00

typedef enum error_rcc
{
    ERROR_RCC_UNKNOWN = -1,
    ERROR_RCC_NOERROR = 0,
    ERROR_RCC_HSIRDY,
    ERROR_RCC_SYSCLK_ASSERT,
} error_rcc;

#define ERROR_CODE_RCC(num) (ERROR_CODE(ERROR_CODE_RCC, num))

void reset_rcc(RCC_TypeDef* addr);