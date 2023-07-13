#pragma once

#include "stdint.h"
#include "stdbool.h"

struct Ticks {
    uint32_t ticks;
    bool overflow;
};

struct Ticks GetMsTicks(void);

void DelayNs(uint32_t delay);
void DelayUs(uint32_t delay);
void DelayMs(uint32_t delay);
void DelayS (uint32_t delay);
