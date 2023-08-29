#include "CommandLineTestRunner.h"

extern "C" {
    #include "stm32f407xx.h"
    #include "hal_system_systick.h"
}

void SysTickHandler(void)
{
    while(1);
}

int main(int ac, char** av)
{
    // printf("%u %s\n", ac, av);
    // return CommandLineTestRunner::RunAllTests(ac, av);
    // RUN_ALL_TESTS(ac, av);
    // __enable_irq();
    systick settings = {
        .reload_value = 10,
        .clk_src = SYSTICK_SOURCE_AHB_DIV8,
        .interrupt = true
    };
    systick_apply_settings(SysTick, &settings);
    systick_start(SysTick);
    while (1) {
        systick_start(SysTick);
    }
}