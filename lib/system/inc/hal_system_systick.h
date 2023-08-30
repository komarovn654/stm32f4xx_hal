#pragma once

#include "stdint.h"
#include "stdbool.h"
#include "stm32f407xx.h"

#define SYSTICK_CTRL_DEFAULT (0)
#define SYSTICK_LOAD_DEFAULT (0)

typedef enum systick_source {
    SYSTICK_SOURCE_UNKNOWN = 0,
    SYSTICK_SOURCE_AHB = 1,
    SYSTICK_SOURCE_AHB_DIV8 = 2,
} systick_source;

typedef struct systick {
    uint32_t reload_value;
    systick_source clk_src;
    bool interrupt;
} systick;

error_system systick_apply_settings(SysTick_Type* addr, systick* settings);
void systick_get_settings(SysTick_Type* addr, systick* settings);
void systick_start(SysTick_Type* addr);
void systick_stop(SysTick_Type* addr);
uint32_t systick_1ms_reloadvalue(uint32_t systick_frequncy);
