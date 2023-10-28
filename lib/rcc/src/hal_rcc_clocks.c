#include "hal_core.h"
#include "hal_rcc.h"
#include "hal_rcc_regs.h"
#include "hal_rcc_gen.h"
#include "hal_rcc_clocks.h"

static clocks rcc_clocks = {
    .sysclk = RCC_SYSCLK_DEFAULT,
    .hclk = RCC_HCLK_DEFAULT,
    .fclk = RCC_FCLK_DEFAULT,
};

void rcc_clocks_set_default(void)
{
    rcc_clocks.sysclk = RCC_SYSCLK_DEFAULT;
    rcc_clocks.hclk = RCC_HCLK_DEFAULT;
    rcc_clocks.fclk = RCC_FCLK_DEFAULT;
}

clocks* rcc_clocks_get(void)
{
    return &rcc_clocks;
}

utest_static uint32_t rcc_clocks_real_pllout(RCC_TypeDef* addr)
{
    uint32_t pll_in = ((GET_BIT(addr->PLLCFGR, RCC_PLLCFGR_PLLSRC_MSK) >> RCC_PLLCFGR_PLLSRC_POS) == PLL_SOURCE_HSE) ? HSE_FREQUENCY : HSI_FREQUENCY;
    uint32_t p_num = GET_BIT(addr->PLLCFGR, RCC_PLLCFGR_PLLP_MSK) >> RCC_PLLCFGR_PLLP_POS;
    uint32_t p = PLL_PLLCFGR_P(p_num); // expand to PLL_PLLCFGR_P0 or PLL_PLLCFGR_P1 etc
    uint32_t m = GET_BIT(addr->PLLCFGR, RCC_PLLCFGR_PLLM_MSK) >> RCC_PLLCFGR_PLLM_POS;
    uint32_t n = GET_BIT(addr->PLLCFGR, RCC_PLLCFGR_PLLN_MSK) >> RCC_PLLCFGR_PLLN_POS;
    uint32_t pll_out = ((pll_in * (n / m)) / p);

    return pll_out;
}

utest_static uint32_t rcc_clocks_real_sysclk(RCC_TypeDef* addr)
{
    switch (GET_BIT(addr->CFGR, RCC_CFGR_SW_MSK))
    {
    case RCC_SW_SRC_HSI:
        return HSI_FREQUENCY;
    case RCC_SW_SRC_HSE:
        return HSE_FREQUENCY;
    case RCC_SW_SRC_PLL:
        return rcc_clocks_real_pllout(addr);
    default:
        return 0;
    }
}

utest_static uint32_t rcc_clocks_real_hclk(RCC_TypeDef* addr)
{
    return rcc_clocks_real_sysclk(addr) / rcc_ahb_prescaler(addr);
}

utest_static uint32_t rcc_clocks_real_fclk(RCC_TypeDef* addr)
{
    return rcc_clocks_real_sysclk(addr) / rcc_ahb_prescaler(addr);
}

void rcc_clocks_update(RCC_TypeDef* addr)
{
    rcc_clocks.sysclk = rcc_clocks_real_sysclk(addr);
    rcc_clocks.fclk = rcc_clocks_real_fclk(addr);
    rcc_clocks.hclk = rcc_clocks_real_hclk(addr);
}
