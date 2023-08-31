#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "stm32f407xx.h"
    #include "hal_system_mstick.h"
}

TEST_GROUP(SystemMsTick)
{
    void setup()
    {
        system_mstick_rst();
    }
    void teardown()
    {
    }
};

TEST(SystemMsTick, MsTickInc)
{
    system_mstick_inc();
    CHECK_EQUAL(1, system_mstick_get());
}

TEST(SystemMsTick, MsTickIsRunning)
{
    system_mstick_inc();
    CHECK_TRUE(system_mstick_isrunning());
}

TEST(SystemMsTick, MsTickDelay_stopped)
{
    CHECK_EQUAL(ERROR_SYSTEM_MSTICK_STOPPED, system_mstick_delay(100));
}

TEST(SystemMsTick, MsTickDelay_nodelay)
{
    CHECK_EQUAL(ERROR_NOERROR, system_mstick_delay(0));
}

#if (defined UTEST_TARGET && UTEST_TARGET==1)
extern "C" {
    #include "hal_system_systick.h"
}

TEST(SystemMsTick, MsTickWaitFor)
{
    systick settings = {
        .reload_value = SYSTICK_1MS_RELOADVALUE(16000000),
        .clk_src = SYSTICK_SOURCE_AHB,
        .interrupt = true,
    };
    __enable_irq();
    systick_apply_settings(SysTick, &settings);
    systick_start(SysTick);

    while(!system_mstick_isrunning());

    CHECK_EQUAL(ERROR_NOERROR, system_mstick_delay(500));
    CHECK_TRUE(system_mstick_get() >= 500);
    
    systick_stop(SysTick);
}

TEST(SystemMsTick, MsTickDelay_running)
{
    systick settings = {
        .reload_value = SYSTICK_1MS_RELOADVALUE(16000000),
        .clk_src = SYSTICK_SOURCE_AHB,
        .interrupt = true,
    };
    __enable_irq();
    systick_apply_settings(SysTick, &settings);
    systick_start(SysTick);

    while(!system_mstick_isrunning());

    system_mstick_wait_for(false, 500);
    CHECK_TRUE(system_mstick_get() >= 500);
    
    systick_stop(SysTick);
}
#endif