#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <math.h>
#include <omp.h>


const char* test_sine_generator_at_zero();
const char* test_sine_generator_at_one();
const char* test_interpolate_2x_return_arr();
const char* test_interpolate_2x_zeros();
const char* test_interpolate_2x_case_arr1();
const char* test_interpolate_2x_case_arr2();

#define ASSERT_TRUE(condition) \ 
    do { \
    if (!(condition)) { \
        fprintf(stderr, "   [FAIL] %s, %d Assertion failed: %s\n", __FILE__, __LINE__ , #condition); \ 
        return "Test failed"; \
        } \
    } while(0) \

#define ASSERT_INT_EQUALS(expected, actual) \
    do { \
        if ((actual) != (expected)) { \
            fprintf(stderr, "      [FAIL] %s, %d Assertion failed:\n", __FILE__, __LINE__ ); \
            fprintf(stderr, "        Expected: %lld\n", (long long)(expected)); \
            fprintf(stderr, "        Actual:   %lld\n", (long long)(actual)); \
            return "Values are not equal"; \
        } \
    } while (0)

#define ASSERT_DOUBLE_EQUALS(expected, actual) \
    do { \
        double epsilon = 1e-9; \
        if (fabs((actual) - (expected)) > epsilon) { \
            fprintf(stderr, "      [FAIL] %s, %d Assertion failed:\n", __FILE__, __LINE__ ); \
            fprintf(stderr, "        Expected: %lf\n", (expected)); \
            fprintf(stderr, "        Actual:   %lf\n", (actual)); \
            return "Values are not equal"; \
        } \
    } while (0)

#define RUN_TEST(test_function) \
    do { \
        fprintf(stdout, "Running test: %-35s", #test_function); \
        ++tests_run; \
        char *message = test_function(); \
        if (message) { \
            ++tests_failed; \
        } else { \
            fprintf(stdout, "    [OK]\n"); \
        } \ 
    } while (0)
    
#endif // TESTS_H
