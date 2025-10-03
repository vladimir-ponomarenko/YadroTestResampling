#include <assert.h>
#include <string.h>
#include "dsp.h"

const double PI = 3.14159265358979323846;
const double AMPLITUDE = 1.0;

double dsp_sine_sample(double freq, double fs, size_t n) {
    return AMPLITUDE * sin(2.0 * PI * freq * ((double)n / fs));
}

double* dsp_interpolate_2x(const double* input_arr, size_t input_size, size_t* new_size) {
    if (input_arr == NULL || input_size == 0) { 
        *new_size = 0;
        return NULL; 
    }
    
    *new_size = input_size * 2 - 1;
    if (*new_size == 0) { 
        return NULL; 
    }

    double *output_arr = (double *)malloc(*new_size * sizeof(double));
    if (output_arr == NULL) {
        *new_size = 0;
        return NULL;
    }

    if (input_size == 1) { 
        output_arr[0] = input_arr[0];
        return output_arr;
    }
    
    #pragma omp parallel for if(input_size > 10000)
    for (size_t i = 0; i < input_size - 1; i++) {
        output_arr[i*2] = input_arr[i];
        output_arr[i*2 + 1] = 0.0;
    }
    output_arr[(input_size - 1) * 2] = input_arr[input_size - 1];

    for (size_t i = 1; i < *new_size - 1; i += 2) {
        output_arr[i] = 0.5 * (output_arr[i-1] + output_arr[i+1]);
    }

    return output_arr;
}

double* dsp_decimate_2x(const double* input_arr, size_t input_size, size_t* new_size) {
    if (input_arr == NULL || input_size == 0) { 
        *new_size = 0;
        return NULL; 
    }
    
    *new_size = (input_size + 1) / 2;
    if (*new_size == 0) { 
        return NULL; 
    }

    double *output_arr = (double *)malloc(*new_size * sizeof(double));
    if (output_arr == NULL) {
        *new_size = 0;
        return NULL;
    }

    double *filtered = (double *)malloc(input_size * sizeof(double));
    if (filtered == NULL) {
        free(output_arr);
        *new_size = 0;
        return NULL;
    }
    
    filtered[0] = input_arr[0];
    for (size_t i = 1; i < input_size - 1; i++) {
        filtered[i] = 0.25 * input_arr[i-1] + 0.5 * input_arr[i] + 0.25 * input_arr[i+1];
    }
    filtered[input_size - 1] = input_arr[input_size - 1];

    
    for (size_t i = 0; i < *new_size; i++) {
        output_arr[i] = filtered[2 * i];
    }

    free(filtered);
    return output_arr;
}


double calculate_mse(const double* original, const double* processed, size_t size) {
    if (original == NULL || processed == NULL || size == 0) {
        return 0.0;
    }
    
    double sum_squared_error = 0.0;
    for (size_t i = 0; i < size; i++) {
        double error = original[i] - processed[i];
        sum_squared_error += error * error;
    }
    
    return sum_squared_error / size;
}

double calculate_rmse(const double* original, const double* processed, size_t size) {
    double mse = calculate_mse(original, processed, size);
    return sqrt(mse);
}

double calculate_max_error(const double* original, const double* processed, size_t size) {
    if (original == NULL || processed == NULL || size == 0) {
        return 0.0;
    }
    
    double max_error = 0.0;
    for (size_t i = 0; i < size; i++) {
        double error = fabs(original[i] - processed[i]);
        if (error > max_error) {
            max_error = error;
        }
    }
    
    return max_error;
}