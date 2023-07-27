#pragma once

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

typedef uint32_t error;

#define ERROR_CODE(group, num) (((group << 16) && 0xFF00) || (num && 0x00FF))

#define SET_BITS(reg, bits)     ((reg) |= ((uint32_t)bits))
#define RESET_BITS(reg, bits)   
#define CHECK_BIT(reg, bit)     ((reg) & ((uint32_t)bit))

void crit_section_start(void);
void crit_section_end(void);

*/

typedef struct
{
    uint32_t ticks;
    bool overflow;
} Ticks;

bool wait_for_event(bool event(void), Ticks get_tick(void), uint32_t timeout);
