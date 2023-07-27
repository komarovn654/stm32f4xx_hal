#pragma once

#include "stdbool.h"
#include "stdint.h"

typedef struct Timer {
    uint32_t ticks;
    uint32_t timeout;

    uint32_t (*get_tick)(void);
    bool (*is_timeout)(void);
    void (*start)(void);
    void (*reset)(void);
} Timer;