#include "CommandLineTestRunner.h"

extern "C" {
    #include "stm32f407xx.h"
}

int main(int ac, char** av)
{
    return RUN_ALL_TESTS(ac, av);
}