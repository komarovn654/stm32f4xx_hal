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

TEST(Rcc, ResetRcc)
{
    CHECK_EQUAL(RCC_CR_DEFAULT, addr->CR & RCC_CR_DEFAULT_MSK);
    CHECK_EQUAL(RCC_PLLCFGR_DEFAULT, addr->PLLCFGR);
    CHECK_EQUAL(RCC_CFGR_DEFAULT, addr->CFGR);
    CHECK_EQUAL(RCC_CIR_DEFAULT, addr->CIR);
    CHECK_EQUAL(RCC_AHB1RSTR_DEFAULT, addr->AHB1RSTR);
    CHECK_EQUAL(RCC_AHB2RSTR_DEFAULT, addr->AHB2RSTR);
    CHECK_EQUAL(RCC_AHB3RSTR_DEFAULT, addr->AHB3RSTR);
    CHECK_EQUAL(RCC_APB1RSTR_DEFAULT, addr->APB1RSTR);
    CHECK_EQUAL(RCC_APB2RSTR_DEFAULT, addr->APB2RSTR);
    CHECK_EQUAL(RCC_AHB1ENR_DEFAULT, addr->AHB1ENR);
    CHECK_EQUAL(RCC_AHB2ENR_DEFAULT, addr->AHB2ENR);
    CHECK_EQUAL(RCC_AHB3ENR_DEFAULT, addr->AHB3ENR);
    CHECK_EQUAL(RCC_APB1ENR_DEFAULT, addr->APB1ENR);
    CHECK_EQUAL(RCC_APB2ENR_DEFAULT, addr->APB2ENR);
    CHECK_EQUAL(RCC_AHB1LPENR_DEFAULT, addr->AHB1LPENR);
    CHECK_EQUAL(RCC_AHB2LPENR_DEFAULT, addr->AHB2LPENR);
    CHECK_EQUAL(RCC_AHB3LPENR_DEFAULT, addr->AHB3LPENR);
    CHECK_EQUAL(RCC_APB1LPENR_DEFAULT, addr->APB1LPENR);
    CHECK_EQUAL(RCC_APB2LPENR_DEFAULT, addr->APB2LPENR);
    CHECK_EQUAL(RCC_BDCR_DEFAULT, addr->BDCR);
    CHECK_EQUAL(RCC_SSCGR_DEFAULT, addr->SSCGR);
    CHECK_EQUAL(RCC_PLLI2SCFGR_DEFAULT, addr->PLLI2SCFGR);
    CHECK_EQUAL(RCC_PLLSAICFGR_DEFAULT, addr->PLLSAICFGR);    
    CHECK_EQUAL(RCC_DCKCFGR_DEFAULT, addr->DCKCFGR);
}

TEST(Rcc, PllCfgrP_Macros)
{
    CHECK_EQUAL(PLL_PLLCFGR_P0, PLL_PLLCFGR_P(0));
    CHECK_EQUAL(PLL_PLLCFGR_P1, PLL_PLLCFGR_P(1));
    CHECK_EQUAL(PLL_PLLCFGR_P2, PLL_PLLCFGR_P(2));
    CHECK_EQUAL(PLL_PLLCFGR_P3, PLL_PLLCFGR_P(3));
}

TEST(Rcc, AhbPrescaler)
{
    uint32_t reg_val[8] = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    uint32_t expected[8] = {2, 4, 8, 16, 64, 128, 256, 512};    
    CHECK_EQUAL(1, rcc_ahb_prescaler(addr));

    for (uint32_t i = 0; i < 8; i++) {
        CLR_BIT(addr->CFGR, RCC_CFGR_HPRE_MSK);
        SET_BIT(addr->CFGR, reg_val[i] << RCC_CFGR_HPRE_POS);

        CHECK_EQUAL(expected[i], rcc_ahb_prescaler(addr));
    }
}

TEST(Rcc, SetupRequiredPll)
{   
    CHECK_EQUAL(ERROR_NOERROR, rcc_setup_required_pll(addr));
    BITS_EQUAL((PLL_DIV_FACTOR_M << RCC_PLLCFGR_PLLM_POS) | (PLL_DIV_FACTOR_N << RCC_PLLCFGR_PLLN_POS) |(PLL_DIV_FACTOR_P << RCC_PLLCFGR_PLLP_POS) |
        (PLL_DIV_FACTOR_Q << RCC_PLLCFGR_PLLQ_POS) |(PLL_SOURCE << RCC_PLLCFGR_PLLSRC_POS),
        addr->PLLCFGR,
        GET_BIT(addr->PLLCFGR, (RCC_PLLCFGR_PLLM_MSK | RCC_PLLCFGR_PLLN_MSK | RCC_PLLCFGR_PLLP_MSK | RCC_PLLCFGR_PLLQ_MSK | RCC_PLLCFGR_PLLSRC_MSK))
    );

    BITS_EQUAL(RCC_CR_PLL_ON << RCC_CR_PLLON_POS, addr->CR, GET_BIT(addr->CR, RCC_CR_PLLON_MSK));
    BITS_EQUAL(RCC_SW_SRC_PLL << RCC_CFGR_SW_POS, addr->CFGR, GET_BIT(addr->CFGR, RCC_CFGR_SW_MSK));
}