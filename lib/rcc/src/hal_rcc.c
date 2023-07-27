#include "hal_pll.h"
#include "hal_rcc.h"
#include "gen_pll.h"
#include "hal_rcc_regs.h"
#include "hal_system.h"

static error_rcc reset_clock(void) {
    crit_section_start();
    SET_BITS(RCC->CR, RCC_CR_HSI_ON << RCC_CR_HSION_POS);
    WAIT_FOR_NS(CHECK_BIT(RCC->CR, RCC_CR_HSIRDY_MSK), HSIRDY_TIMEOUT_NS);
    if (CHECK_BIT(RCC->CR, RCC_CR_HSIRDY_MSK) == false) {
        return ERROR_RCC_HSIRDY;
    }

    
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
