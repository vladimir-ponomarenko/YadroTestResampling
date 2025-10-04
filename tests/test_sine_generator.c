#include "dsp.h"
#include "tests.h"

char* test_sine_generator_at_zero(){
    int f = 50;
    int n = 0;

    double expected = sin(2 * PI * f * n * (1.0/100));
    double actual = dsp_sine_sample(f, 100, 0);
    ASSERT_DOUBLE_EQUALS(expected , actual);

    return NULL;
}

char* test_sine_generator_at_one(){
    int f = 50;
    int n = 1;

    double expected = sin(2 * PI * f * n * (1.0/100.0));
    double actual = dsp_sine_sample(f, 100, 1);
    ASSERT_DOUBLE_EQUALS(expected , actual);

    return NULL;
}

