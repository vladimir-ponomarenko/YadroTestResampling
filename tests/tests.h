#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <math.h>
#include <omp.h>


char* test_sine_generator_at_zero();
char* test_sine_generator_at_one();

char* test_interpolate_2x_return_arr();
char* test_interpolate_2x_zeros();
char* test_interpolate_2x_case_arr1();
char* test_interpolate_2x_case_arr2();

char* test_decimate_2x_return_arr();
char* test_decimate_2x_zeros_even();
char* test_decimate_2x_zeros_odd();

char* test_calculate_mse();
char* test_calculate_rmse();
char* test_calculate_max_error();

char* test_pipeline_sine_generation();
char* test_pipeline_decimation_interpolation();

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
            fprintf(stderr, "        Expected: %lf\n", (double)(expected)); \
            fprintf(stderr, "        Actual:   %lf\n", (double)(actual)); \
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
