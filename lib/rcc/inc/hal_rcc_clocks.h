#pragma once

#include "stdio.h"
#include "hal_rcc.h"

#define RCC_SYSTEM_CLOCK_MAX (180000000U)

typedef struct Clocks
{
    uint32_t system;
} Clocks;

error_rcc set_system_clock(uint32_t);
uint32_t get_system_clock(void);