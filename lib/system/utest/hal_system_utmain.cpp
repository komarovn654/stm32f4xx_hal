#include "CommandLineTestRunner.h"

int main(int ac, char** av)
{
    // printf("%u %s\n", ac, av);
    // return CommandLineTestRunner::RunAllTests(ac, av);
    RUN_ALL_TESTS(ac, av);
}