#include "TestHarness.h"

extern "C" {
    #include "hal_system_nstimer.h"
}

TEST_GROUP(TimerNs)
{
    Timer* timer;

    void setup()
    {
        timer = init_ns_timer();
    }

    void teardown()
    {
    }
};

TEST(TimerNs, TrueEvent)
{
    timer->reset();
}

