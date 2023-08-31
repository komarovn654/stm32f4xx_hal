#pragma once

#include "stdint.h"
#include "stdbool.h"
#include "hal_errors.h"

typedef struct ms_tick
{
    volatile uint32_t value;
    volatile bool running;
} ms_tick;

uint32_t system_mstick_get(void);
bool system_mstick_isrunning(void);
void system_mstick_rst(void);
void system_mstick_inc(void);
error system_mstick_delay(uint32_t delay);

#define system_mstick_wait_for(event, timeout) do { \
    uint32_t target = system_mstick_get() + timeout; \
    while (!(event) && (target != system_mstick_get())){} \
} while(0)
