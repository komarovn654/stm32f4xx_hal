#include "hal_core.h"
#include "hal_rcc.h"
#include "hal_rcc_regs.h"
#include "hal_rcc_gen.h"
#include "hal_rcc_clocks.h"

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

utest_static uint32_t rcc_clock_real_systick()
{
    switch (GET_BIT(RCC->PLLCFGR, RCC_CFGR_SW_MSK))
    {
    case SW_SRC_HSI:
        return HSI_FREQUENCY;
    case SW_SRC_HSE:
        return HSE_FREQUENCY;
    case SW_SRC_PLL:
        return PLL_REQUIRED_FREQUENCY;
    
    default:
        return 0;
    }
}

utest_static uint32_t rcc_clock_real_pllout()
{
    uint32_t pll_in = ((GET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_MSK) >> RCC_PLLCFGR_PLLSRC_POS) == PLL_SOURCE_HSE) ? HSE_FREQUENCY : HSI_FREQUENCY;
    uint32_t p = PLL_PLLCFGR_P(GET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLP_MSK) >> RCC_PLLCFGR_PLLP_POS); // expand to PLL_PLLCFGR_P0 or PLL_PLLCFGR_P1 etc
    uint32_t m = GET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLM_MSK) >> RCC_PLLCFGR_PLLM_POS;
    uint32_t n = GET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLN_MSK) >> RCC_PLLCFGR_PLLN_POS;
    uint32_t pll_out = ((pll_in * (n / m)) / p);

    return pll_out;
}

void rcc_clocks_update(void)
{

}
