#include "hal_core.h"
#include "hal_rcc.h"
#include "gen_pll.h"

static clocks rcc_clocks = {
    .sysclk = RCC_SYSCLK_DEFAULT,
    .hclk = RCC_HCLK_DEFAULT,
    .fclk = RCC_FCLK_DEFAULT,
    .systick = RCC_SYSTICK_DEFAULT,
};

void rcc_clocks_set_default(void)
{
    rcc_clocks.sysclk = RCC_SYSCLK_DEFAULT;
    rcc_clocks.hclk = RCC_HCLK_DEFAULT;
    rcc_clocks.fclk = RCC_FCLK_DEFAULT;
    rcc_clocks.systick = RCC_SYSTICK_DEFAULT;
}

clocks* rcc_clocks_get(void)
{
    return &rcc_clocks;
}

void rcc_clocks_update(void)
{
    switch (GET_BIT(RCC->PLLCFGR, RCC_CFGR_SW_MSK))
    {
    case 0:
        /* code */
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;                
    
    default:
        break;
    }
}
