#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "hal_core.h"
    #include "hal_rcc_regs.h"
    #include "hal_rcc.h"
    #include "hal_rcc_clocks.h"
    #include "hal_rcc_gen.h"

    utest_static uint32_t rcc_clocks_real_sysclk(RCC_TypeDef* addr);
    utest_static uint32_t rcc_clocks_real_pllout(RCC_TypeDef* addr);
    utest_static uint32_t rcc_clocks_real_hclk(RCC_TypeDef* addr);
    utest_static uint32_t rcc_clocks_real_fclk(RCC_TypeDef* addr);
    utest_static uint32_t rcc_clocks_real_systick(RCC_TypeDef* addr);
}

TEST_GROUP(RccClocks)
{
    RCC_TypeDef* addr;
    clocks* clk;

#if (defined UTEST_TARGET && UTEST_TARGET==1)
    void setup()
    {
        addr = RCC;
        rcc_reset(addr);

        clk = rcc_clocks_get();
        rcc_clocks_set_default();        
    }
    void teardown()
    {
    }
#elif (defined UTEST_HOST && UTEST_HOST==1)
    void setup()
    {
        addr = (RCC_TypeDef*)malloc(sizeof(RCC_TypeDef));
        rcc_reset(addr);

        clk = rcc_clocks_get();
        rcc_clocks_set_default();
    }
    void teardown()
    {
        free(addr);
    }
#endif
};

TEST(RccClocks, SetDefault)
{
    CHECK_EQUAL(RCC_SYSCLK_DEFAULT, clk->sysclk);
    CHECK_EQUAL(RCC_HCLK_DEFAULT, clk->hclk);
    CHECK_EQUAL(RCC_FCLK_DEFAULT, clk->fclk);
}

TEST(RccClocks, RealPllout_Default)
{
    CHECK_EQUAL(RCC_PLLCLK_DEFAULT, rcc_clocks_real_pllout(addr));
}

TEST(RccClocks, RealPllout_Required)
{
    CLR_BIT(addr->PLLCFGR, (RCC_PLLCFGR_PLLSRC_MSK | RCC_PLLCFGR_PLLM_MSK | RCC_PLLCFGR_PLLN_MSK | 
        RCC_PLLCFGR_PLLP_MSK | RCC_PLLCFGR_PLLQ_MSK));
    SET_BIT(addr->PLLCFGR, PLL_DIV_FACTOR_M << RCC_PLLCFGR_PLLM_POS | PLL_DIV_FACTOR_N << RCC_PLLCFGR_PLLN_POS |
        PLL_DIV_FACTOR_P << RCC_PLLCFGR_PLLP_POS | PLL_DIV_FACTOR_Q << RCC_PLLCFGR_PLLQ_POS | PLL_SOURCE_HSE << RCC_PLLCFGR_PLLSRC_POS);

    CHECK_EQUAL(PLL_REQUIRED_FREQUENCY, rcc_clocks_real_pllout(addr));   
}

TEST(RccClocks, RealSysclk_HsiFrequency)
{
    CHECK_EQUAL(HSI_FREQUENCY, rcc_clocks_real_sysclk(addr));
}

TEST(RccClocks, RealSysclk_HseFrequency)
{
    CLR_BIT(addr->CFGR, RCC_CFGR_SWS_MSK);
    SET_BIT(addr->CFGR, RCC_SW_SRC_HSE << RCC_CFGR_SW_POS);

    CHECK_EQUAL(HSE_FREQUENCY, rcc_clocks_real_sysclk(addr));
}

TEST(RccClocks, RealSysclk_PllFrequency)
{
    CLR_BIT(addr->CFGR, RCC_CFGR_SWS_MSK);
    SET_BIT(addr->CFGR, RCC_SW_SRC_PLL << RCC_CFGR_SW_POS);

    CHECK_EQUAL(RCC_PLLCLK_DEFAULT, rcc_clocks_real_sysclk(addr));
}

TEST(RccClocks, RealHclk_Default)
{
    CHECK_EQUAL(RCC_HCLK_DEFAULT, rcc_clocks_real_hclk(addr));
}

TEST(RccClocks, RealHclk_Div4)
{
    CLR_BIT(addr->CFGR, RCC_CFGR_HPRE_MSK);
    SET_BIT(addr->CFGR, 0x09 << RCC_CFGR_HPRE_POS);

    CHECK_EQUAL(RCC_HCLK_DEFAULT / 4, rcc_clocks_real_hclk(addr));
}

TEST(RccClocks, RealFclk_Default)
{
    CHECK_EQUAL(RCC_FCLK_DEFAULT, rcc_clocks_real_fclk(addr));
}

TEST(RccClocks, RealFclk_Div16)
{
    CLR_BIT(addr->CFGR, RCC_CFGR_HPRE_MSK);
    SET_BIT(addr->CFGR, 0x0B << RCC_CFGR_HPRE_POS);

    CHECK_EQUAL(RCC_FCLK_DEFAULT / 16, rcc_clocks_real_fclk(addr));
}

TEST(RccClocks, UpdateClocks_Default)
{
    memset(clk, 0, sizeof(clocks));
    rcc_clocks_update(addr);

    CHECK_EQUAL(RCC_SYSCLK_DEFAULT, clk->sysclk);
    CHECK_EQUAL(RCC_HCLK_DEFAULT, clk->hclk);
    CHECK_EQUAL(RCC_FCLK_DEFAULT, clk->fclk);
}

TEST(RccClocks, UpdateClocks)
{
    CLR_BIT(addr->CFGR, RCC_CFGR_SWS_MSK);
    SET_BIT(addr->CFGR, RCC_SW_SRC_PLL << RCC_CFGR_SW_POS);

    CLR_BIT(addr->CFGR, RCC_CFGR_HPRE_MSK);
    SET_BIT(addr->CFGR, 0x0C << RCC_CFGR_HPRE_POS);
    WAIT_TICKS(false, 1000);

    rcc_clocks_update(addr);
    CHECK_EQUAL(RCC_PLLCLK_DEFAULT, clk->sysclk);
    CHECK_EQUAL(RCC_PLLCLK_DEFAULT / 64, clk->hclk);
    CHECK_EQUAL(RCC_PLLCLK_DEFAULT / 64, clk->fclk);
}