#include "hal_pll.h"
#include "hal_rcc.h"
#include "gen_pll.h"
#include "hal_rcc_regs.h"
#include "hal_system.h"

static error_rcc reset_clock(void)
{

}

error_rcc setup_pll(void)
{
    // disable pll
    RCC->CR = RCC_CR_DEFAULT;
    
    RCC->PLLCFGR |= (PLL_SOURCE << RCC_PLLCFGR_PLLSRC_POS) | (PLL_DIV_FACTOR_Q << RCC_PLLCFGR_PLLQ_POS) | (PLL_DIV_FACTOR_P<< RCC_PLLCFGR_PLLP_POS)
                    | (PLL_DIV_FACTOR_N << RCC_PLLCFGR_PLLN_POS) | (PLL_DIV_FACTOR_M << RCC_PLLCFGR_PLLM_POS);
    // enable pll
    // wait 
}

error_rcc set_system_clock(void)
{
    return 0;
}
