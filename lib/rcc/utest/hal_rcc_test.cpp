#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "hal_core.h"
    #include "hal_rcc.h"
    #include "hal_rcc_regs.h"
    #include "hal_rcc_gen.h"

    utest_static error rcc_setup_required_pll(RCC_TypeDef* addr);
}

TEST_GROUP(Rcc)
{
    RCC_TypeDef* addr;

#if (defined UTEST_TARGET && UTEST_TARGET==1)
    void setup()
    {
        addr = RCC;
        rcc_reset(addr);
    }
    void teardown()
    {
    }
#elif (defined UTEST_HOST && UTEST_HOST==1)
    void setup()
    {
        addr = (RCC_TypeDef*)malloc(sizeof(RCC_TypeDef));
        rcc_reset(addr);
    }
    void teardown()
    {
        free(addr);
    }
#endif
};

// TEST(Rcc, ResetRcc)
// {
//     CHECK_EQUAL(addr->CR, RCC_CR_DEFAULT);
//     CHECK_EQUAL(addr->PLLCFGR, RCC_PLLCFGR_DEFAULT);
//     CHECK_EQUAL(addr->CFGR, RCC_CFGR_DEFAULT);
//     CHECK_EQUAL(addr->CIR, RCC_CIR_DEFAULT);
//     CHECK_EQUAL(addr->AHB1RSTR, RCC_AHB1RSTR_DEFAULT);
//     CHECK_EQUAL(addr->AHB2RSTR, RCC_AHB2RSTR_DEFAULT);
//     CHECK_EQUAL(addr->AHB3RSTR, RCC_AHB3RSTR_DEFAULT);
//     CHECK_EQUAL(addr->APB1RSTR, RCC_APB1RSTR_DEFAULT);
//     CHECK_EQUAL(addr->APB2RSTR, RCC_APB2RSTR_DEFAULT);
//     CHECK_EQUAL(addr->AHB1ENR, RCC_AHB1ENR_DEFAULT);
//     CHECK_EQUAL(addr->AHB2ENR, RCC_AHB2ENR_DEFAULT);
//     CHECK_EQUAL(addr->AHB3ENR, RCC_AHB3ENR_DEFAULT);
//     CHECK_EQUAL(addr->APB1ENR, RCC_APB1ENR_DEFAULT);
//     CHECK_EQUAL(addr->APB2ENR, RCC_APB2ENR_DEFAULT);
//     CHECK_EQUAL(addr->AHB1LPENR, RCC_AHB1LPENR_DEFAULT);
//     CHECK_EQUAL(addr->AHB2LPENR, RCC_AHB2LPENR_DEFAULT);
//     CHECK_EQUAL(addr->AHB3LPENR, RCC_AHB3LPENR_DEFAULT);
//     CHECK_EQUAL(addr->APB1LPENR, RCC_APB1LPENR_DEFAULT);
//     CHECK_EQUAL(addr->APB2LPENR, RCC_APB2LPENR_DEFAULT);
//     CHECK_EQUAL(addr->BDCR, RCC_BDCR_DEFAULT);
//     CHECK_EQUAL(addr->SSCGR, RCC_SSCGR_DEFAULT);
//     CHECK_EQUAL(addr->PLLI2SCFGR, RCC_PLLI2SCFGR_DEFAULT);
//     CHECK_EQUAL(addr->PLLSAICFGR, RCC_PLLSAICFGR_DEFAULT);    
//     CHECK_EQUAL(addr->DCKCFGR, RCC_DCKCFGR_DEFAULT);
// }

// TEST(Rcc, PllCfgrP_Macros)
// {
//     CHECK_EQUAL(PLL_PLLCFGR_P0, PLL_PLLCFGR_P(0));
//     CHECK_EQUAL(PLL_PLLCFGR_P1, PLL_PLLCFGR_P(1));
//     CHECK_EQUAL(PLL_PLLCFGR_P2, PLL_PLLCFGR_P(2));
//     CHECK_EQUAL(PLL_PLLCFGR_P3, PLL_PLLCFGR_P(3));
// }

// TEST(Rcc, AhbPrescaler)
// {
//     uint32_t reg_val[8] = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
//     uint32_t expected[8] = {2, 4, 8, 16, 64, 128, 256, 512};    
//     CHECK_EQUAL(1, rcc_ahb_prescaler(addr));

//     for (uint32_t i = 0; i < 8; i++) {
//         CLR_BIT(addr->CFGR, RCC_CFGR_HPRE_MSK);
//         SET_BIT(addr->CFGR, reg_val[i] << RCC_CFGR_HPRE_POS);

//         CHECK_EQUAL(expected[i], rcc_ahb_prescaler(addr));
//     }
// }

// TEST(Rcc, SetupRequiredPll)
// {   
//     CHECK_EQUAL(ERROR_NOERROR, rcc_setup_required_pll(addr));

//     BITS_EQUAL((PLL_DIV_FACTOR_M << RCC_PLLCFGR_PLLM_POS) | (PLL_DIV_FACTOR_N << RCC_PLLCFGR_PLLN_POS) |(PLL_DIV_FACTOR_P << RCC_PLLCFGR_PLLP_POS) |
//         (PLL_DIV_FACTOR_Q << RCC_PLLCFGR_PLLQ_POS) |(PLL_SOURCE << RCC_PLLCFGR_PLLSRC_POS),
//         addr->PLLCFGR,
//         GET_BIT(addr->PLLCFGR, RCC_PLLCFGR_PLLM_MSK | RCC_PLLCFGR_PLLN_MSK | RCC_PLLCFGR_PLLP_MSK | RCC_PLLCFGR_PLLQ_MSK | RCC_PLLCFGR_PLLSRC_MSK)
//     );

//     BITS_EQUAL(RCC_CR_PLL_ON << RCC_CR_PLLON_POS, addr->CR, GET_BIT(addr->CR, RCC_CR_PLLON_MSK));
//     BITS_EQUAL(RCC_SW_SRC_PLL << RCC_CFGR_SW_POS, addr->CFGR, GET_BIT(addr->CFGR, RCC_CFGR_SW_MSK));
// }