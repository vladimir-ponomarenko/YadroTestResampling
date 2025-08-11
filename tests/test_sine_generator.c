#include "dsp.h"
#include "tests.h"

const char* test_sine_generator_at_zero(){
    int f = 50;
    int n = 0;

    double expected = sin(2 * PI * f * n * (1.0/SAMPLING_RATE_HZ));
    double actual = dsp_sine_sample(f, SAMPLING_RATE_HZ, 0);
    ASSERT_DOUBLE_EQUALS(expected , actual);

    return NULL;
}

const char* test_sine_generator_at_one(){
    int f = 50;
    int n = 1;

    double expected = sin(2 * PI * f * n * (1/SAMPLING_RATE_HZ));
    double actual = dsp_sine_sample(f, SAMPLING_RATE_HZ, 1);
    ASSERT_DOUBLE_EQUALS(expected , actual);

    return NULL;
}

