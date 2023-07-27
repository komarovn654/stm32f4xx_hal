#include "stdint.h"
#include "stdbool.h"
#include "hal_system.h"

bool wait_for_event(bool event(void), Ticks get_tick(void), uint32_t timeout)
{
    return false;
}