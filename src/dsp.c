#include <assert.h>
#include "dsp.h"

const double PI = 3.1415926535898;
const int SAMPLING_RATE_HZ = 100;
const double AMPLITUDE = 1;

double dsp_sine_sample(double freq, double fs, size_t n) {
    return AMPLITUDE * sin(2 * PI * freq * ((double)n / fs));
}

double* interpolate_2x(const double* input_arr, size_t input_size, size_t* new_size) {
    if (input_arr == NULL || input_size == 0) { return NULL; }
    *new_size = input_size * 2 - 1;
    if (*new_size == 0) { return NULL; }

    double *output_arr = (double *)malloc(*new_size * sizeof(double));
    if (output_arr == NULL) {
        *new_size = 0;
        return NULL;
    }

    if (input_size == 1) { 
        output_arr[0] = input_arr[0];
        return output_arr;
    }

    size_t j = 0;
    for (size_t i = 0; i < *new_size; ++i) {
        if (i % 2 == 0) {
            output_arr[i] = input_arr[j];
            j++;
        } else {
            output_arr[i] = (input_arr[j-1] + input_arr[j]) / 2.0;
        }   
    }
    
    return output_arr;
}