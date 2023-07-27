#include "third_party/cpputest/include/CppUTest/TestHarness.h"
#include "third_party/cpputest/include/CppUTest/CommandLineTestRunner.h"

extern "C"
{
#include "main.h"
#include <stdio.h>
#include <memory.h>
}

//START: testGroup
TEST_GROUP(sprintf)
{
    char output[100];
    const char * expected;
    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
    }
    void teardown()
    {
    }
    void expect(const char * s)
    {
        expected = s;
    }
    void given(int charsWritten)
    {
        LONGS_EQUAL(strlen(expected), charsWritten);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};
//END: testGroup

TEST(sprintf, NoFormatOperations)
{
    expect("hy");
    given(sprintf(output, "hey"));
}

TEST(sprintf, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}

#if 0 //START: NoFormatOperations1
TEST(sprintf, NoFormatOperations)
{
    char output[5];
    LONGS_EQUAL(3, sprintf(output, "hey"));
    STRCMP_EQUAL("hey", output);
}
//END: NoFormatOperations1
#endif

int main(int ac, char** av)
{
    return 1;
}