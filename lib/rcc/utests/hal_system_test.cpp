// #include "TestHarness.h"
// #include "CommandLineTestRunner.h"

// extern "C" {
//     #include "hal_system.h"
// }

// TEST_GROUP(WaitForNs)
// {
//     void setup()
//     {
//     }
//     void teardown()
//     {
//     }

//     static bool true_event(void) {
//         return true;
//     }

//     static bool false_event(void) {
//         return false;
//     }

//     static Ticks get_tick(void) {
//         static Ticks t = {0};
//         t.ticks++;
//         return t;
//     }
// };

// TEST(WaitForNs, TrueEvent)
// {
//     CHECK_FALSE(wait_for_event(true_event, get_tick, 0));
// }

// TEST(WaitForNs, Timeout)
// {
//     CHECK_TRUE(wait_for_event(false_event, get_tick, 100));
// }

// TEST_GROUP(TimerNs)
// {
//     void setup()
//     {
//     }
//     void teardown()
//     {
//     }
// };

// int main(int ac, char** av)
// {
//     return CommandLineTestRunner::RunAllTests(ac, av);
// }