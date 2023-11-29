#pragma once 

#include "stdint.h"

typedef uint16_t error;

#define ERROR_CODE(group, num) (((group << 16) & 0xFF00) | (num & 0x00FF))

#define ERROR_GROUP_RCC    (0x01)
#define ERROR_GROUP_SYSTEM (0x02)

#define ERROR_CODE_RCC(num)     (ERROR_CODE(ERROR_GROUP_RCC, num))
#define ERROR_CODE_SYSTEM(num)  (ERROR_CODE(ERROR_GROUP_SYSTEM, num))

#define ERROR_RCC_HSIRDY ERROR_CODE_RCC(0x01)
#define ERROR_RCC_HSERDY ERROR_CODE_RCC(0x02)
#define ERROR_RCC_SWSRDY ERROR_CODE_RCC(0x03)
#define ERROR_RCC_PLLRDY ERROR_CODE_RCC(0x04)

#define ERROR_SYSTEM_MSTICK_STOPPED ERROR_CODE_SYSTEM(0x01)

#define ERROR_NOERROR   (0x00)
#define ERROR_ASSERT    (0x01)

#define CERR(FUNC) do { \
    error err = FUNC; \
    if (err != ERROR_NOERROR) { \
        return err; \
    } \
} while(0)
