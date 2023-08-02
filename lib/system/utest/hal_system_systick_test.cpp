#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "hal_system.h"
    #include "hal_system_systick.h"
}

TEST_GROUP(SystemTick)
{
    SysTick_Type* addr;
    systick settings;

    void setup()
    {
        addr = (SysTick_Type*)malloc(sizeof(SysTick_Type));
        memset(addr, 0, sizeof(SysTick_Type));
        memset(&settings, 0, sizeof(settings));
        settings.clk_src = SYSTICK_SOURCE_AHB;
    }
    void teardown()
    {
        free(addr);
    }
};

TEST(SystemTick, ApplySettings_DisableSysTick)
{
    SET_BIT(addr->CTRL, 1 & SysTick_CTRL_ENABLE_Msk);
    systick_aplly_settings(addr, &settings);
    BITS_EQUAL(0, addr->CTRL, SysTick_CTRL_ENABLE_Msk);
}

TEST(SystemTick, ApplySettings_AssertError)
{
    settings.reload_value = 0xFFFFFFFF;
    CHECK_EQUAL(ERROR_ASSERT, systick_aplly_settings(addr, &settings));

    settings.reload_value = 0;
    settings.clk_src = SYSTICK_SOURCE_UNKNOWN;
    CHECK_EQUAL(ERROR_ASSERT, systick_aplly_settings(addr, &settings));
}

TEST(SystemTick, ApplySettings_ClearFields)
{
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_CLKSOURCE_Pos);
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_TICKINT_Pos);
    SET_BIT(addr->LOAD, 0xFFFFFF << SysTick_LOAD_RELOAD_Pos);
    SET_BIT(addr->CTRL, 1 << SysTick_CTRL_ENABLE_Pos);

    systick_aplly_settings(addr, &settings);
    BITS_EQUAL(0, addr->CTRL, SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
    BITS_EQUAL(0, addr->LOAD, SysTick_LOAD_RELOAD_Msk);
}

TEST(SystemTick, ApplySettings_SetFields)
{
    settings.clk_src = SYSTICK_SOURCE_AHB_DIV8;
    settings.interrupt = true;
    settings.reload_value = 0xFFFFFF;
    systick_aplly_settings(addr, &settings);

    BITS_EQUAL(1 << SysTick_CTRL_CLKSOURCE_Pos | 1 << SysTick_CTRL_TICKINT_Pos, addr->CTRL, 
            SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
    BITS_EQUAL(0xFFFFFF, addr->LOAD, SysTick_LOAD_RELOAD_Msk);
}