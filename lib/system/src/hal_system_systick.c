#include "stm32f407xx.h"
#include "hal_system.h"
#include "hal_system_systick.h"

static error_system assert_settings(systick* settings)
{
    if (!(settings->clk_src == SYSTICK_SOURCE_AHB_DIV8 || settings->clk_src == SYSTICK_SOURCE_AHB)) {
        return ERROR_ASSERT;
    }

    if (settings->reload_value > 0xFFFFFF) {
        return ERROR_ASSERT;
    }

    return ERROR_NOERROR;
}

error_system systick_apply_settings(SysTick_Type* addr, systick* settings)
{
    hal_assert(assert_settings, settings);

    addr->CTRL = SYSTICK_CTRL_DEFAULT;
    addr->LOAD = SYSTICK_LOAD_DEFAULT;

    uint8_t clk_source = (settings->clk_src == SYSTICK_SOURCE_AHB_DIV8) ? 1 : 0;
    SET_BIT(addr->CTRL, (clk_source << SysTick_CTRL_CLKSOURCE_Pos) | 
                        (settings->interrupt << SysTick_CTRL_TICKINT_Pos));
    SET_BIT(addr->LOAD, settings->reload_value << SysTick_LOAD_RELOAD_Pos);
    return ERROR_NOERROR;
}

void systick_get_settings(SysTick_Type* addr, systick* settings)
{
    settings->clk_src = GET_BIT(addr->CTRL, SysTick_CTRL_CLKSOURCE_Msk) >> SysTick_CTRL_CLKSOURCE_Pos;
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
}