#ifndef DSP_H
#define DSP_H

#include <math.h>
#include <assert.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif

const double PI = 3.1415926535898;
const int SAMPLING_RATE_HZ = 100;
const double AMPLITUDE = 1;

double dsp_sine_sample(double freq, double fs, size_t n);

#ifdef __cplusplus
}
#endif


#endif // DSP_H