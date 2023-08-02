#include "hal_rcc.h"
#include "hal_rcc_clocks.h"

static Clocks clocks = {
    .system = 0,
};

error_rcc set_system_clock(uint32_t value)
{
    if (value > RCC_SYSTEM_CLOCK_MAX) {
        return ERROR_RCC_SYSCLK_ASSERT;
    }

    clocks.system = value;
    return ERROR_RCC_NOERROR;
}

uint32_t get_system_clock(void)
{
    return clocks.system;
}