#include "harness.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

test_runner* new_test_runner(void)
{
    return (test_runner*)calloc(1, sizeof(test_runner));
}

void free_test_runner(test_runner* runner)
{
    free(runner);
}

static void handle_test_result(test_runner* runner, int cond, const char* msg, va_list args)
{
    runner->test_num++;
    if (cond) {
        runner->pass_count++;
    }
    else {
        runner->fail_count++;
        printf("FAILED test %d: ", runner->test_num);
        vprintf(msg, args);
        printf("\n");
    }
}

int is_test_ok(test_runner* runner)
{
    return runner->fail_count == 0;
}

void print_test_summary(test_runner* runner)
{
    printf("%d tests passed, %d failed, %d skipped\n",
        runner->pass_count,
        runner->fail_count,
        runner->skip_count);

    if (is_test_ok(runner)) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");  
    }
}

void SKIP(test_runner* runner, ...)
{
    runner->test_num++;
    runner->skip_count++;
}

void OK(test_runner* runner, int code, const char* msg, ...)
{
    int cond = code == 0;

    va_list args;
    va_start(args, msg);
    handle_test_result(runner, cond, msg, args);
    va_end(args);
}

void INT_EQ(test_runner* runner, int value, int expect,
    const char* msg, ...)
{
    int cond = value == expect;

    va_list args;
    va_start(args, msg);
    handle_test_result(runner, cond, msg, args);
    va_end(args);

    if (!cond) {
        printf("  Expected: %d\n", expect);
        printf("  Received: %d\n", value);
    }
}

void FLT_EQ(test_runner* runner, float value, float expect, float delta,
    const char* msg, ...)
{
    int cond = fabs(value - expect) < delta;

    va_list args;
    va_start(args, msg);
    handle_test_result(runner, cond, msg, args);
    va_end(args);

    if (!cond) {
        printf("  Expected: %f\n", expect);
        printf("  Received: %f\n", value);
    }
}

void DBL_EQ(test_runner* runner, double value, double expect, double delta,
    const char* msg, ...)
{
    int cond = fabs(value - expect) < delta;

    va_list args;
    va_start(args, msg);
    handle_test_result(runner, cond, msg, args);
    va_end(args);

    if (!cond) {
        printf("  Expected: %f\n", expect);
        printf("  Received: %f\n", value);
    }
}

void STR_EQ(test_runner* runner, const char* value, const char* expect,
    const char* msg, ...)
{
    int cond = strcmp(value, expect) == 0;

    va_list args;
    va_start(args, msg);
    handle_test_result(runner, cond, msg, args);
    va_end(args);

    if (!cond) {
        printf("  Expected: \"%s\"\n", expect);
        printf("  Received: \"%s\"\n", value);
    }
}

