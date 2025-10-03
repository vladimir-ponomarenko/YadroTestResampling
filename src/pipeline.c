#include "pipeline.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void run_dsp_pipeline() {
    // Fixed parameters as per requirements
    const double sampling_freq = 100.0;  // 100 Hz
    const double sine_freq = 0.5;        // 0.5 Hz
    const size_t num_samples = 1000;     // 10 seconds at 100 Hz
    
    printf("DSP Pipeline: Processing 0.5 Hz sine wave...\n");
    
    // Generate original sine wave
    double *sine_generated = (double *)malloc(num_samples * sizeof(double));
    if (sine_generated == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }
    
    for (size_t i = 0; i < num_samples; i++) {
        sine_generated[i] = dsp_sine_sample(sine_freq, sampling_freq, i);
    }
    
    // Save original signal
    save_signal_to_csv("original_signal.csv", sine_generated, num_samples, sampling_freq);

    // Apply decimation (2x downsampling)
    size_t sine_decimated_2x_size = 0;
    double* sine_decimated_2x = dsp_decimate_2x(sine_generated, num_samples, &sine_decimated_2x_size);
    
    if (sine_decimated_2x == NULL) {
        fprintf(stderr, "Error: Decimation failed\n");
        free(sine_generated);
        return;
    }
    
    // Save decimated signal
    save_signal_to_csv("decimated_signal.csv", sine_decimated_2x, sine_decimated_2x_size, sampling_freq / 2.0);

    // Apply interpolation (2x upsampling)
    size_t sine_interpolated_2x_size = 0;
    double* sine_interpolated_2x = dsp_interpolate_2x(sine_decimated_2x, sine_decimated_2x_size, &sine_interpolated_2x_size);
    
    if (sine_interpolated_2x == NULL) {
        fprintf(stderr, "Error: Interpolation failed\n");
        free(sine_generated);
        free(sine_decimated_2x);
        return;
    }
    
    // Save interpolated signal
    save_signal_to_csv("interpolated_signal.csv", sine_interpolated_2x, sine_interpolated_2x_size, sampling_freq);

    // Calculate errors
    size_t compare_size = (num_samples < sine_interpolated_2x_size) ? num_samples : sine_interpolated_2x_size;
    
    double mse = calculate_mse(sine_generated, sine_interpolated_2x, compare_size);
    double rmse = calculate_rmse(sine_generated, sine_interpolated_2x, compare_size);
    double max_error = calculate_max_error(sine_generated, sine_interpolated_2x, compare_size);
    
    // Save error analysis
    save_error_analysis_to_csv("error_analysis.csv", sine_generated, sine_interpolated_2x, compare_size, sampling_freq);

    // Print results
    printf("Results: MSE=%.2e, RMSE=%.2e, MaxError=%.2e\n", mse, rmse, max_error);
    printf("Data saved to CSV files.\n");

    // Cleanup
    free(sine_generated);
    free(sine_decimated_2x);
    free(sine_interpolated_2x);
}