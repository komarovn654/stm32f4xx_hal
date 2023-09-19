#include "hal_core.h"
#include "hal_rcc.h"
#include "hal_rcc_regs.h"
    
void reset_rcc(RCC_TypeDef* addr)
{
    addr->CR = RCC_CR_DEFAULT;
    addr->PLLCFGR = RCC_PLLCFGR_DEFAULT;
    addr->CFGR = RCC_CFGR_DEFAULT;
    addr->CIR = RCC_CIR_DEFAULT;
    addr->AHB1RSTR = RCC_AHB1RSTR_DEFAULT;
    addr->AHB2RSTR = RCC_AHB2RSTR_DEFAULT;
    addr->AHB3RSTR = RCC_AHB3RSTR_DEFAULT;
    addr->APB1RSTR = RCC_APB1RSTR_DEFAULT;
    addr->APB2RSTR = RCC_APB2RSTR_DEFAULT;
    addr->AHB1ENR = RCC_AHB1ENR_DEFAULT;
    addr->AHB2ENR = RCC_AHB2ENR_DEFAULT;
    addr->AHB3ENR = RCC_AHB3ENR_DEFAULT;
    addr->APB1ENR = RCC_APB1ENR_DEFAULT;
    addr->APB2ENR = RCC_APB2ENR_DEFAULT;
    addr->AHB1LPENR = RCC_AHB1LPENR_DEFAULT;
    addr->AHB2LPENR = RCC_AHB2LPENR_DEFAULT;
    addr->AHB3LPENR = RCC_AHB3LPENR_DEFAULT;
    addr->APB1LPENR = RCC_APB1LPENR_DEFAULT;
    addr->APB2LPENR = RCC_APB2LPENR_DEFAULT;                                
    addr->BDCR = RCC_BDCR_DEFAULT;
    addr->SSCGR = RCC_SSCGR_DEFAULT;
    addr->PLLI2SCFGR = RCC_PLLI2SCFGR_DEFAULT;
    addr->PLLSAICFGR = RCC_PLLSAICFGR_DEFAULT;
    addr->DCKCFGR = RCC_DCKCFGR_DEFAULT;
}
