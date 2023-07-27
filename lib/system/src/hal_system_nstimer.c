#include "stdio.h"
#include "hal_system_nstimer.h"

static Timer ns_timer;

static uint32_t ns_get_tick(void)
{
    printf("%s\n", __func__);
    return 0;
}

static bool ns_is_timeout(void)
{
    printf("%s\n", __func__);
    return false;
}

static void ns_start(void)
{
    printf("%s\n", __func__);
    return;
}

static void ns_reset(void)
{
    printf("%s\n", __func__);
    return;
}

Timer* init_ns_timer(void)
{
    ns_timer.reset = ns_reset;
    ns_timer.start = ns_start;
    ns_timer.is_timeout = ns_is_timeout;
    ns_timer.get_tick = ns_get_tick;
    return &ns_timer;
}
