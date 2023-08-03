#pragma once

#include "stdint.h"
#include "stdbool.h"

/*
#define WAIT_FOR_MS(event, timeout) do { \
    struct Ticks start = GetMsTicks(); \
    struct Ticks elapsed = start; \
    struct Ticks target; \
    target.ticks = UINT32_MAX - start.ticks; \
    target.overflow = (target.ticks < timeout) ? true : false; \
    do { \
        elapsed = GetMsTicks(); \
    } while (!event || (elapsed.ticks != target.ticks && elapsed.overflow != target.overflow)); \
} while(0)

#define WAIT_FOR_NS(event, tacts) do { \
    uint32_t elapsed = 0; \
    do { \
        elapsed++; \
    } while (!event || (elapsed == tacts)); \
} while(0)
*/

void crit_section_start(void);
void crit_section_end(void);

void delay_ns(uint32_t delay);
bool wait_for_event_ns(bool event(void), uint32_t timeout);
