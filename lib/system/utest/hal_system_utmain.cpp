#include "CommandLineTestRunner.h"

extern "C" {
    #include "stm32f407xx.h"
    #include "hal_system_systick.h"
}

int main(int ac, char** av)
{
    RUN_ALL_TESTS(ac, av);

    return 0;
}