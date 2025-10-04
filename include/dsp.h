#ifndef DSP_H
#define DSP_H

#include <math.h>
#include <assert.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif

extern const double PI;
extern const double AMPLITUDE;

double dsp_sine_sample(double freq, double fs, size_t n);
double* dsp_interpolate_2x(const double* input_arr, size_t input_size, size_t* new_size);
double* dsp_decimate_2x(const double* input_arr, size_t input_size, size_t* new_size);

double calculate_mse(const double* original, const double* processed, size_t size);
double calculate_rmse(const double* original, const double* processed, size_t size);
double calculate_max_error(const double* original, const double* processed, size_t size);

#ifdef __cplusplus
}
#endif


#endif // DSP_H