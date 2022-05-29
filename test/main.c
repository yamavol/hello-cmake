#include "harness.h"
#include "hello.h"

static void test_harness(test_runner* runner)
{
    OK(runner, 0, "OK() checks if return code is 0");      
    
    INT_EQ(runner, 100, 50+50, "INT_EQ checks if two int is equal");
    FLT_EQ(runner, 0.9999f, 0.9998f, 0.001f, "FLT_EQ() checks if two float is equal");
    DBL_EQ(runner, 0.9999, 0.9998, 0.0001, "DBL_EQ() checks if two double is equal");
    STR_EQ(runner, "abc", "abc", "STR_EQ() checks if two string is equal");

    OK(runner, 0, "msg can contain arguments: %d %f %s", 123, 456.0f, "789");
}

static void test_unit_hello(test_runner* runner)
{
    OK(runner, print_message(), "print message");
}

int main()
{
    int result = 0;
    test_runner* runner = new_test_runner();

    test_harness(runner);
    test_unit_hello(runner);

    print_test_summary(runner);
    
    result = is_test_ok(runner) ? 0 : 1;
    free_test_runner(runner);
    
    return result;
}