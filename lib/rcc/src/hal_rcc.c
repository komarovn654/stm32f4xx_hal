#include "hal_core.h"
// #include "hal_flash.h" // flash_setup_required
#include "hal_rcc.h"
#include "hal_rcc_gen.h"
#include "hal_rcc_regs.h"
#include "hal_rcc_clocks.h"

#define RCC_WAIT_STATUS(REG, TIMEOUT)

error rcc_reset(RCC_TypeDef* addr)
{
    /* Turn on HSI */
    SET_BIT(addr->CR, RCC_CR_HSI_ON << RCC_CR_HSION_POS);
    WAIT_TICKS_RET_ERR(GET_BIT_VAL(addr->CR, RCC_CR_HSIRDY_MSK, RCC_CR_HSIRDY_POS), 
        1000, ERROR_RCC_HSIRDY);

    /* Switch SYSCLK to HSI */
    SET_BIT(addr->CFGR, RCC_SW_SRC_HSI << RCC_CFGR_SW_POS);
    WAIT_TICKS_RET_ERR(GET_BIT_VAL(addr->CFGR, RCC_CFGR_SWS_MSK, RCC_CFGR_SWS_POS) == RCC_SWS_ACT_HSI, 
        1000, ERROR_RCC_SWSRDY);

    /* Turn off PLL */
    CLR_BIT(addr->CR, RCC_CR_PLLON_MSK);
    WAIT_TICKS_RET_ERR(GET_BIT_VAL(addr->CR, RCC_CR_PLLRDY_MSK, RCC_CR_PLLRDY_POS) == 0, 
        1000, ERROR_RCC_PLLRDY);        

    /* Set default RCC regs */
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

    return ERROR_NOERROR;
}

uint32_t rcc_ahb_prescaler(RCC_TypeDef* addr)
{
    switch (GET_BIT_VAL(addr->CFGR, RCC_CFGR_HPRE_MSK, RCC_CFGR_HPRE_POS))
    {
    case 0x08:
        return 2;
    case 0x09:
        return 4;
    case 0x0A:
        return 8;
    case 0x0B:
        return 16;
    case 0x0C:
        return 64;
    case 0x0D:
        return 128;
    case 0x0E:
        return 256;
    case 0x0F:
        return 512;             
    default:
        return 1;
    }
}

utest_static error rcc_setup_required_pll(RCC_TypeDef* addr)
{   
    rcc_reset(addr);

    /* Enable PLL_SOURCE */
    if (PLL_SOURCE == PLL_SOURCE_HSE) { 
        SET_BIT(addr->CR, RCC_CR_HSE_ON << RCC_CR_HSEON_POS);
        WAIT_TICKS_RET_ERR(GET_BIT_VAL(addr->CR, RCC_CR_HSERDY_MSK, RCC_CR_HSERDY_POS) == RCC_CR_HSE_ON,
            1000, ERROR_RCC_HSERDY);
    }

    /* Setup PLL */
    uint32_t pllcfgr_val = (PLL_DIV_FACTOR_M << RCC_PLLCFGR_PLLM_POS) | (PLL_DIV_FACTOR_N << RCC_PLLCFGR_PLLN_POS) |
        (PLL_DIV_FACTOR_P << RCC_PLLCFGR_PLLP_POS) | (PLL_SOURCE << RCC_PLLCFGR_PLLSRC_POS) | (PLL_DIV_FACTOR_Q << RCC_PLLCFGR_PLLQ_POS);
    pllcfgr_val |= 0x20000000; // reserved value
    addr->PLLCFGR = pllcfgr_val;  

    /* Enable PLL */
    SET_BIT(addr->CR, RCC_CR_PLL_ON << RCC_CR_PLLON_POS);
    WAIT_TICKS_RET_ERR(GET_BIT_VAL(addr->CR, RCC_CR_PLLRDY_MSK, RCC_CR_PLLRDY_POS) == RCC_CR_PLL_ON,
        1000, ERROR_RCC_PLLRDY);

    /* Setup flash latency */
    // flash_setup_required();

    /* Select PLL as a system clock */
    SET_BIT(addr->CFGR, RCC_SW_SRC_PLL << RCC_CFGR_SW_POS);
    WAIT_TICKS_RET_ERR(GET_BIT_VAL(addr->CFGR, RCC_CFGR_SWS_MSK, RCC_CFGR_SWS_POS) == RCC_SW_SRC_PLL,
        1000, ERROR_RCC_SWSRDY);
    return ERROR_NOERROR;  
}

error rcc_setup_required_frequency(RCC_TypeDef* addr)
{
    /* Setup, Enable and Select PLL as a system clock */
    CERR(rcc_setup_required_pll(addr));
    return ERROR_NOERROR;
}