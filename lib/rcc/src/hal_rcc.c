#include "hal_pll.h"
#include "hal_rcc.h"
#include "gen_pll.h"
#include "hal_rcc_regs.h"

static void reset_clock(void) {
    crit_section_start();
    WAIT_FOR_NS(true, 10000);


    crit_section_end();
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
