#include "TestHarness.h"
#include "CommandLineTestRunner.h"

extern "C" {
    #include "stm32f407xx.h"
    #include "hal_system.h"
}

TEST_GROUP(Core)
{
    void setup()
    {
    }
    void teardown()
    {
    }
};

TEST(Core, SetBit)
{
    uint32_t bit = 1;
    for (uint32_t i = 0; i < 32; i++, bit = bit << 1) {
        uint32_t reg = 0;
        SET_BIT(reg, bit);
        CHECK_EQUAL(bit & 0xFFFFFFFF, reg);
    }
}

TEST(Core, ClrBit)
{
    uint32_t bit = 1;
    for (uint32_t i = 0; i < 32; i++, bit = bit << 1) {
        uint32_t reg = 0xFFFFFFFF;
        CLR_BIT(reg, bit);
        CHECK_EQUAL(~(bit & 0xFFFFFFFF), reg);
    }
}

TEST(Core, GetBit)
{
    uint32_t bit = 1;
    uint32_t reg = 0xAAAAAAAA;
    for (uint32_t i = 0; i < 32; i++, bit = bit << 1) {
        CHECK_EQUAL(reg & bit, GET_BIT(reg, bit));
    }
}

TEST(Core, WaitTicks_Event) {
    WAIT_TICKS(true, 500);
    CHECK_TRUE(true);
}

TEST(Core, WaitTicks_Timeout) {
    uint32_t timeout = 500;
    WAIT_TICKS(false, timeout);
    CHECK_TRUE(true);
}
