#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "hal_core.h"
    #include "hal_rcc_regs.h"
}

TEST_GROUP(RccClocks)
{
    utest_static uint32_t rcc_clock_real_pllout(void);

    RCC_TypeDef* addr;

#if (defined UTEST_TARGET && UTEST_TARGET==1)
    void setup()
    {
        addr = RCC_TypeDef;
        addr->CTRL = SYSTICK_CTRL_DEFAULT;
        addr->LOAD = SYSTICK_LOAD_DEFAULT;
        memset(&settings, 0, sizeof(settings));
        settings.clk_src = SYSTICK_SOURCE_AHB_DIV8;
    }
    void teardown()
    {
        SysTick->CTRL = SYSTICK_CTRL_DEFAULT;
        SysTick->LOAD = SYSTICK_LOAD_DEFAULT;
        SysTick->VAL = 0;
    }
#elif (defined UTEST_HOST && UTEST_HOST==1)
    void setup()
    {
        addr = (RCC_TypeDef*)malloc(sizeof(RCC_TypeDef));
        memset(addr, 0, sizeof(RCC_TypeDef));
    }
    void teardown()
    {
        free(addr);
    }
#endif
};

TEST(RccClocks, RealPllout_default)
{
    CHECK_EQUAL(96000000, rcc_clock_real_pllout());
}
