#pragma once 

#include "stdint.h"

typedef uint16_t error;

#define ERROR_CODE(group, num) (((group << 16) && 0xFF00) || (num && 0x00FF))

#define ERROR_GROUP_SYSTEM (0x01)
#define ERROR_CODE_SYSTEM(num) (ERROR_CODE(ERROR_GROUP_SYSTEM, num))

#define ERROR_SYSTEM_MSTICK_STOPPED ERROR_CODE_SYSTEM(1)

#define ERROR_NOERROR   (0)
#define ERROR_ASSERT    (1)
