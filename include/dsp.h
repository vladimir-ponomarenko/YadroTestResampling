#ifndef DSP_H
#define DSP_H

#include <math.h>
#include <assert.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif

extern const double PI;
extern const int SAMPLING_RATE_HZ;
extern const double AMPLITUDE;

double dsp_sine_sample(double freq, double fs, size_t n);
double* interpolate_2x(const double* input_arr, size_t input_size, size_t* new_size);

#ifdef __cplusplus
}
#endif


#endif // DSP_H