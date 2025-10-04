#include "tests.h"

int tests_run = 0;
int tests_failed = 0;

int main(int argc, char const *argv[])
{

    printf("Starting tests...\n\n");
    
    RUN_TEST(test_sine_generator_at_zero);
    RUN_TEST(test_sine_generator_at_one);
    RUN_TEST(test_interpolate_2x_return_arr);
    RUN_TEST(test_interpolate_2x_zeros);
    RUN_TEST(test_interpolate_2x_case_arr1);
    RUN_TEST(test_interpolate_2x_case_arr2);
    RUN_TEST(test_decimate_2x_return_arr);
    RUN_TEST(test_decimate_2x_zeros_even);
    RUN_TEST(test_decimate_2x_zeros_odd);
    
    // Error calculation tests
    RUN_TEST(test_calculate_mse);
    RUN_TEST(test_calculate_rmse);
    RUN_TEST(test_calculate_max_error);
    
    // Pipeline tests
    RUN_TEST(test_pipeline_sine_generation);
    RUN_TEST(test_pipeline_decimation_interpolation);

    printf("\n--- Test Summary ---\n");
    if (tests_failed == 0) {
        printf("All %d tests passed!\n", tests_run);
        return 0;
    } else {
        printf("%d out of %d tests failed.\n", tests_failed, tests_run);
        return 1;
    }

    return 0;
}
