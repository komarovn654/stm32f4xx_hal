#include "stdint.h"
#include "stdbool.h"
#include "hal_errors.h"
#include "hal_system_mstick.h"

static ms_tick system_ms_tick;

uint32_t system_mstick_get(void)
{
    return system_ms_tick.value;
}

bool system_mstick_isrunning(void)
{
    return system_ms_tick.running;
}

void system_mstick_rst(void)
{
    system_ms_tick.running = false;
    system_ms_tick.value = 0;
}

void system_mstick_inc(void) 
{
    system_ms_tick.running = true;
    system_ms_tick.value++;
}

error system_mstick_delay(uint32_t delay)
{
    if (delay == 0) {
        return ERROR_NOERROR;
    }
    if (system_ms_tick.running == false) {
        return ERROR_SYSTEM_MSTICK_STOPPED;
    }

    uint32_t target = system_ms_tick.value + delay;
    while (target != system_ms_tick.value) {};
    return ERROR_NOERROR;
}

