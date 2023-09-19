#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "hal_core.h"
    #include "hal_rcc_regs.h"
    #include "hal_rcc.h"
}

TEST_GROUP(RccClocks)
{
    RCC_TypeDef* addr;

#if (defined UTEST_TARGET && UTEST_TARGET==1)
    void setup()
    {
        addr = RCC;
        reset_rcc(addr);
    }
    void teardown()
    {
    }
#elif (defined UTEST_HOST && UTEST_HOST==1)
    void setup()
    {
        addr = (RCC_TypeDef*)malloc(sizeof(RCC_TypeDef));
        reset_rcc(addr);
    }
    void teardown()
    {
        free(addr);
    }
#endif
};

TEST(RccClocks, ResetRcc)
{
    CHECK_EQUAL(addr->CR, RCC_CR_DEFAULT);
    CHECK_EQUAL(addr->PLLCFGR, RCC_PLLCFGR_DEFAULT);
    CHECK_EQUAL(addr->CFGR, RCC_CFGR_DEFAULT);
    CHECK_EQUAL(addr->CIR, RCC_CIR_DEFAULT);
    CHECK_EQUAL(addr->AHB1RSTR, RCC_AHB1RSTR_DEFAULT);
    CHECK_EQUAL(addr->AHB2RSTR, RCC_AHB2RSTR_DEFAULT);
    CHECK_EQUAL(addr->AHB3RSTR, RCC_AHB3RSTR_DEFAULT);
    CHECK_EQUAL(addr->APB1RSTR, RCC_APB1RSTR_DEFAULT);
    CHECK_EQUAL(addr->APB2RSTR, RCC_APB2RSTR_DEFAULT);
    CHECK_EQUAL(addr->AHB1ENR, RCC_AHB1ENR_DEFAULT);
    CHECK_EQUAL(addr->AHB2ENR, RCC_AHB2ENR_DEFAULT);
    CHECK_EQUAL(addr->AHB3ENR, RCC_AHB3ENR_DEFAULT);
    CHECK_EQUAL(addr->APB1ENR, RCC_APB1ENR_DEFAULT);
    CHECK_EQUAL(addr->APB2ENR, RCC_APB2ENR_DEFAULT);
    CHECK_EQUAL(addr->AHB1LPENR, RCC_AHB1LPENR_DEFAULT);
    CHECK_EQUAL(addr->AHB2LPENR, RCC_AHB2LPENR_DEFAULT);
    CHECK_EQUAL(addr->AHB3LPENR, RCC_AHB3LPENR_DEFAULT);
    CHECK_EQUAL(addr->APB1LPENR, RCC_APB1LPENR_DEFAULT);
    CHECK_EQUAL(addr->APB2LPENR, RCC_APB2LPENR_DEFAULT);
    CHECK_EQUAL(addr->BDCR, RCC_BDCR_DEFAULT);
    CHECK_EQUAL(addr->SSCGR, RCC_SSCGR_DEFAULT);
    CHECK_EQUAL(addr->PLLI2SCFGR, RCC_PLLI2SCFGR_DEFAULT);
    CHECK_EQUAL(addr->PLLSAICFGR, RCC_PLLSAICFGR_DEFAULT);    
    CHECK_EQUAL(addr->DCKCFGR, RCC_DCKCFGR_DEFAULT);
}
