#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <math.h>


const char* test_sine_generator_at_zero();
const char* test_sine_generator_at_one();

#define ASSERT_TRUE(condition) \ 
    do { \
    if (!(condition)) { \
        fprintf(stderr, "   [FAIL] __FILE__ , __LINE__ Condition failed: %s\n", #condition); \ 
        return "Test failed"; \
        } \
    } while(0) \

#define ASSERT_INT_EQUALS(expected, actual) \
    do { \
        if ((actual) != (expected)) { \
            fprintf(stderr, "      [FAIL] __FILE__ , __LINE__ Assertion failed:\n"); \
            fprintf(stderr, "        Expected: %lld\n", (long long)(expected)); \
            fprintf(stderr, "        Actual:   %lld\n", (long long)(actual)); \
            return "Values are not equal"; \
        } \
    } while (0)

#define ASSERT_DOUBLE_EQUALS(expected, actual) \
    do { \
        double epsilon = 1e-2; \
        if (fabs(((actual) - (expected))) < epsilon) { \
            fprintf(stderr, "      [FAIL] __FILE__ , __LINE__ Assertion failed:\n"); \
            fprintf(stderr, "        Expected: %lf\n", (long long)(expected)); \
            fprintf(stderr, "        Actual:   %lf\n", (long long)(actual)); \
            return "Values are not equal"; \
        } \
    } while (0)

#define RUN_TEST(test_function) \
    do { \
        fprintf(stdout, "Running test: %s...\n", #test_function); \
        ++tests_run; \
        char *message = test_function(); \
        if (message) { \
            ++tests_failed; \
        } else { \
            fprintf(stdout, "[OK]"); \
        } \ 
    } while (0)
    
#endif // TESTS_H