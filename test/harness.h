#ifndef TEST_HARNESS_H
#define TEST_HARNESS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct test_runner {
    int test_num;
    int pass_count;
    int fail_count;
    int skip_count;
} test_runner;

test_runner* new_test_runner(void);

void free_test_runner(test_runner* runner);

int is_test_ok(test_runner* runner);

void print_test_summary(test_runner* runner);

void SKIP(test_runner* runner, ...);

void OK(test_runner* runner, int code, const char* msg, ...);

void INT_EQ(test_runner* runner, int value, int expect,
    const char* msg, ...);

void FLT_EQ(test_runner* runner, float value, float expect, float delta,
    const char* msg, ...);

void DBL_EQ(test_runner* runner, double value, double expect, double delta,
    const char* msg, ...);

void STR_EQ(test_runner* runner, const char* value, const char* expect,
    const char* msg, ...);





#ifdef __cplusplus
}
#endif


#endif // TEST_HARNESS_H