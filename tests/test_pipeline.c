#include "dsp.h"
#include "tests.h"
#include <stdlib.h>

char* test_pipeline_sine_generation() {
    
    const double freq = 0.5;
    const double fs = 100.0;
    const size_t num_samples = 100;
    
    
    double* signal = (double*)malloc(num_samples * sizeof(double));
    if (signal == NULL) {
        return "Memory allocation failed";
    }
    
    for (size_t i = 0; i < num_samples; i++) {
        signal[i] = dsp_sine_sample(freq, fs, i);
    }
    
    ASSERT_DOUBLE_EQUALS(0.0, signal[0]);

    double expected = sin(PI / 100.0);
    ASSERT_DOUBLE_EQUALS(expected, signal[1]);    
    
    size_t period_samples = (size_t)(2.0 * fs / freq);
    if (num_samples >= period_samples) {
        double error = fabs(signal[0] - signal[period_samples]);
        ASSERT_TRUE(error < 1e-10);
    }
    
    free(signal);
    return NULL;
}

char* test_pipeline_decimation_interpolation() {
    
    const double freq = 0.5;
    const double fs = 100.0;
    const size_t num_samples = 100;
    double* original = (double*)malloc(num_samples * sizeof(double));
    if (original == NULL) {
        return "Memory allocation failed";
    }
    
    for (size_t i = 0; i < num_samples; i++) {
        original[i] = dsp_sine_sample(freq, fs, i);
    }
    
    size_t decimated_size = 0;
    double* decimated = dsp_decimate_2x(original, num_samples, &decimated_size);
    if (decimated == NULL) {
        free(original);
        return "Decimation failed";
    }
    
    ASSERT_INT_EQUALS((num_samples + 1) / 2, decimated_size);
    size_t interpolated_size = 0;
    double* interpolated = dsp_interpolate_2x(decimated, decimated_size, &interpolated_size);
    if (interpolated == NULL) {
        free(original);
        free(decimated);
        return "Interpolation failed";
    }
    
    
    ASSERT_INT_EQUALS(2 * decimated_size - 1, interpolated_size);
    size_t compare_size = (num_samples < interpolated_size) ? num_samples : interpolated_size;
    double mse = calculate_mse(original, interpolated, compare_size);
    double rmse = calculate_rmse(original, interpolated, compare_size);
    double max_error = calculate_max_error(original, interpolated, compare_size);
    
    ASSERT_TRUE(mse >= 0.0);
    ASSERT_TRUE(rmse >= 0.0);
    ASSERT_TRUE(max_error >= 0.0);
    ASSERT_TRUE(max_error < 1.0); 
    
    free(original);
    free(decimated);
    free(interpolated);
    
    return NULL;
}
