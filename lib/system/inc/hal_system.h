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

#define hal_assert(func, ...) do { \
        if (ERROR_ASSERT == func(__VA_ARGS__)) return ERROR_ASSERT; \
    } while(0)

typedef uint32_t error;

#define ERROR_NOERROR   (0)
#define ERROR_ASSERT    (1)
#define ERROR_CODE(group, num) (((group << 16) && 0xFF00) || (num && 0x00FF))

#define ERROR_GROUP_SYSTEM 0x01
#define ERROR_CODE_SYSTEM(num) (ERROR_CODE(ERROR_CODE_SYSTEM, num))

typedef enum error_system {
    asd,
} error_system;

#define SET_BIT(reg, bit)   (reg |= (uint32_t)bit)
#define CLR_BIT(reg, bit)   (reg &= ~(uint32_t)bit)
#define GET_BIT(reg, bit)   (reg & (uint32_t)bit)

void crit_section_start(void);
void crit_section_end(void);

void delay_ns(uint32_t delay);
bool wait_for_event_ns(bool event(void), uint32_t timeout);
