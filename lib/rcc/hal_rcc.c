#include "hal_rcc.h"
#include "hal_rcc_regs.h"

#define N_MAX 0
// 180MHz
ErrorRCC CalculateAndSetupPll(PllSource src, uint32_t pllfreq)
{
#pragma message "Assert params"
    // disable pll
    for (uint8_t i = 0; i < N_MAX; i++) {
        
    }
    // enable pll
    // wait 
}

ErrorRCC SetupPll(PllSource src, uint8_t m, uint8_t n, uint8_t p, uint8_t q, uint8_t r)
{
    // disable pll
    RCC->PLLCFGR |= (src << RCC_PLLCFGR_PLLSRC_POS) | (q << RCC_PLLCFGR_PLLQ_POS) | (p<< RCC_PLLCFGR_PLLP_POS)
                    | (n << RCC_PLLCFGR_PLLN_POS) | (m << RCC_PLLCFGR_PLLM_POS);
    // enable pll
    // wait 
}

ErrorRCC SetSystemClock(SystemClockSource src, uint32_t freq)
{
#pragma message "Assert params"
    if (src == SCS_HSI && freq != HSI_FREQUENCY) {
        return 1;
    }
    if (src == SCS_HSE && freq != HSE_FREQUENCY) {
        return 1;
    }

    if (src == SCS_PLLCLK) {
        SetupPll(0, 0, 0, 0, 0, 0);
    }


    return 0;
}
