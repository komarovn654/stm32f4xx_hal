#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "stm32f407xx.h"
    #include "hal_system_systick.h"
}

TEST_GROUP(SystemTick)
{
    SysTick_Type* addr;
    systick settings;

#if (defined UTEST_TARGET && UTEST_TARGET==1)
    void setup()
    {
        addr = SysTick;
        addr->CTRL = SYSTICK_CTRL_DEFAULT;
        addr->LOAD = SYSTICK_LOAD_DEFAULT;
        memset(&settings, 0, sizeof(settings));
        settings.clk_src = SYSTICK_SOURCE_AHB_DIV8;
    }
    void teardown()
    {
    }
#elif (defined UTEST_HOST && UTEST_HOST==1)
    void setup()
    {
        addr = (SysTick_Type*)malloc(sizeof(SysTick_Type));
        memset(addr, 0, sizeof(SysTick_Type));
        memset(&settings, 0, sizeof(settings));
        settings.clk_src = SYSTICK_SOURCE_AHB_DIV8;
    }
    void teardown()
    {
        free(addr);
    }
#endif
};

TEST(SystemTick, ApplySettings_DisableSysTick)
{
    SET_BIT(addr->CTRL, 1 & SysTick_CTRL_ENABLE_Msk);
    systick_apply_settings(addr, &settings);
    BITS_EQUAL(0, addr->CTRL, SysTick_CTRL_ENABLE_Msk);
}

TEST(SystemTick, ApplySettings_AssertError)
{
    settings.reload_value = 0xFFFFFFFF;
    CHECK_EQUAL(ERROR_ASSERT, systick_apply_settings(addr, &settings));

    settings.reload_value = 0;
    settings.clk_src = SYSTICK_SOURCE_UNKNOWN;
    CHECK_EQUAL(ERROR_ASSERT, systick_apply_settings(addr, &settings));
}

TEST(SystemTick, ApplySettings_ResetFields)
{
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_CLKSOURCE_Pos);
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_TICKINT_Pos);
    SET_BIT(addr->LOAD, 0xFFFFFF << SysTick_LOAD_RELOAD_Pos);
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_ENABLE_Pos);

    systick_apply_settings(addr, &settings);
    BITS_EQUAL(0, addr->CTRL, SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
    BITS_EQUAL(0, addr->LOAD, SysTick_LOAD_RELOAD_Msk);
}

TEST(SystemTick, ApplySettings_SetFields)
{
    settings.clk_src = SYSTICK_SOURCE_AHB;
    settings.interrupt = true;
    settings.reload_value = 0xFFFFFF;
    systick_apply_settings(addr, &settings);

    BITS_EQUAL(1 << SysTick_CTRL_CLKSOURCE_Pos | 1 << SysTick_CTRL_TICKINT_Pos, addr->CTRL, 
            SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
    BITS_EQUAL(0xFFFFFF, addr->LOAD, SysTick_LOAD_RELOAD_Msk);
}

TEST(SystemTick, GetSettings_EmptyFields)
{
    settings.clk_src = SYSTICK_SOURCE_AHB;
    settings.interrupt = true;
    settings.reload_value = 0xFFFFFF;
    
    systick_get_settings(addr, &settings);

    CHECK_EQUAL(false, settings.interrupt);
    CHECK_EQUAL(0, settings.reload_value);
    CHECK_EQUAL(SYSTICK_SOURCE_AHB_DIV8, settings.clk_src);  
}

TEST(SystemTick, GetSettings_SetFields)
{
    settings.clk_src = SYSTICK_SOURCE_AHB;
    settings.interrupt = true;
    settings.reload_value = 0xFFFFFF;
    systick_apply_settings(addr, &settings);
    memset(&settings, 0, sizeof(settings));

    systick_get_settings(addr, &settings);

    CHECK_EQUAL(true, settings.interrupt);
    CHECK_EQUAL(0xFFFFFF, settings.reload_value);
    CHECK_EQUAL(SYSTICK_SOURCE_AHB, settings.clk_src);  
}

TEST(SystemTick, Start)
{
    systick_start(addr);

    BITS_EQUAL(1, addr->CTRL, SysTick_CTRL_ENABLE_Msk);
}

TEST(SystemTick, Stop)
{
    systick_stop(addr);

    BITS_EQUAL(0, addr->CTRL, SysTick_CTRL_ENABLE_Msk);
}

TEST(SystemTick, Calculate1msReloadValue)
{
    CHECK_EQUAL(0, systick_1ms_reloadvalue(0));
    CHECK_EQUAL(180000, systick_1ms_reloadvalue(180000000));
}
