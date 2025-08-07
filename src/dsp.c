#include "dsp.h"

double dsp_sine_sample(double freq, double fs, size_t n) {
    return AMPLITUDE * sin(2 * PI * freq * ((double)n / fs));
}