#pragma once 

#include "stdint.h"

typedef uint32_t error;

#define ERROR_CODE(group, num) (((group << 16) && 0xFF00) || (num && 0x00FF))

#define ERROR_GROUP_SYSTEM 0x01
#define ERROR_CODE_SYSTEM(num) (ERROR_CODE(ERROR_CODE_SYSTEM, num))

#define ERROR_NOERROR   (0)
#define ERROR_ASSERT    (1)

typedef enum error_system {
    asd = 2,
} error_system;