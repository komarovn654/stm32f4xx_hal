#pragma once

#include "stdint.h"
#include "stdbool.h"
#include "timers/hal_tim.h"

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

typedef uint32_t error;

#define ERROR_CODE(group, num) (((group << 16) && 0xFF00) || (num && 0x00FF))

void crit_section_start(void);
void crit_section_end(void);
