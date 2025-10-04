#include "dsp.h"
#include "tests.h"

char* test_calculate_mse() {
    const double original[] = {1.0, 2.0, 3.0, 4.0};
    const double processed[] = {1.1, 1.9, 3.1, 3.9};
    const size_t size = 4;
    
    double expected_mse = 0.0;
    for (size_t i = 0; i < size; i++) {
        double error = original[i] - processed[i];
        expected_mse += error * error;
    }
    expected_mse /= size;
    
    double actual_mse = calculate_mse(original, processed, size);
    ASSERT_DOUBLE_EQUALS(expected_mse, actual_mse);
    
    
    ASSERT_DOUBLE_EQUALS(0.0, calculate_mse(NULL, processed, size));
    ASSERT_DOUBLE_EQUALS(0.0, calculate_mse(original, NULL, size));
    ASSERT_DOUBLE_EQUALS(0.0, calculate_mse(original, processed, 0));
    
    return NULL;
}

char* test_calculate_rmse() {
    const double original[] = {1.0, 4.0, 9.0, 16.0};
    const double processed[] = {1.0, 4.0, 9.0, 16.0};
    const size_t size = 4;
    
    
    double actual_rmse = calculate_rmse(original, processed, size);
    ASSERT_DOUBLE_EQUALS(0.0, actual_rmse);
    
    
    const double processed2[] = {2.0, 5.0, 10.0, 17.0};
    double expected_mse = 1.0; 
    double expected_rmse = sqrt(expected_mse);
    double actual_rmse2 = calculate_rmse(original, processed2, size);
    ASSERT_DOUBLE_EQUALS(expected_rmse, actual_rmse2);
    
    return NULL;
}

char* test_calculate_max_error() {
    const double original[] = {1.0, 5.0, 3.0, 8.0};
    const double processed[] = {1.5, 4.0, 3.5, 7.0};
    const size_t size = 4;
    
    
    double expected_max = 0.0;
    for (size_t i = 0; i < size; i++) {
        double error = fabs(original[i] - processed[i]);
        if (error > expected_max) {
            expected_max = error;
        }
    }
    
    double actual_max = calculate_max_error(original, processed, size);
    ASSERT_DOUBLE_EQUALS(expected_max, actual_max);
    
    
    ASSERT_DOUBLE_EQUALS(0.0, calculate_max_error(NULL, processed, size));
    ASSERT_DOUBLE_EQUALS(0.0, calculate_max_error(original, NULL, size));
    ASSERT_DOUBLE_EQUALS(0.0, calculate_max_error(original, processed, 0));
    
    return NULL;
}
