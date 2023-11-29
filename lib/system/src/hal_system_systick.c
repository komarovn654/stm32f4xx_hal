#include "stm32f407xx.h"
#include "hal_system.h"
#include "hal_system_systick.h"

static error assert_settings(systick* settings)
{
    if (!(settings->clk_src == SYSTICK_SOURCE_AHB_DIV8 || settings->clk_src == SYSTICK_SOURCE_AHB)) {
        return ERROR_ASSERT;
    }

    if (settings->reload_value > 0xFFFFFF) {
        return ERROR_ASSERT;
    }

    return ERROR_NOERROR;
}

error systick_apply_settings(SysTick_Type* addr, systick* settings)
{
    hal_assert(assert_settings, settings);

    addr->CTRL = SYSTICK_CTRL_DEFAULT;
    addr->LOAD = SYSTICK_LOAD_DEFAULT;

    uint8_t clk_source = (settings->clk_src == SYSTICK_SOURCE_AHB_DIV8) ? 0 : 1;
    SET_BIT(addr->CTRL, (clk_source << SysTick_CTRL_CLKSOURCE_Pos) | 
                        (uint8_t)(settings->interrupt << SysTick_CTRL_TICKINT_Pos));
    SET_BIT(addr->LOAD, settings->reload_value << SysTick_LOAD_RELOAD_Pos);
    return ERROR_NOERROR;
}

void systick_get_settings(SysTick_Type* addr, systick* settings)
{
    uint8_t clk_src = GET_BIT(addr->CTRL, SysTick_CTRL_CLKSOURCE_Msk) >> SysTick_CTRL_CLKSOURCE_Pos;
    settings->clk_src = (clk_src == 0) ? SYSTICK_SOURCE_AHB_DIV8 : SYSTICK_SOURCE_AHB;
    settings->interrupt =  GET_BIT(addr->CTRL, SysTick_CTRL_TICKINT_Msk) >> SysTick_CTRL_TICKINT_Pos;
    settings->reload_value = GET_BIT(addr->LOAD, SysTick_LOAD_RELOAD_Msk) >> SysTick_LOAD_RELOAD_Pos;   
}

void systick_start(SysTick_Type* addr)
{
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_ENABLE_Pos);
}

void systick_stop(SysTick_Type* addr)
{
    CLR_BIT(addr->CTRL, 1 << SysTick_CTRL_ENABLE_Pos);
    addr->VAL = 0;
}

uint32_t systick_1ms_reloadvalue(uint32_t systick_frequncy)
{
    return systick_frequncy / 1000;
}