#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int save_signal_to_csv(const char* filename, const double* signal, size_t size, double sampling_rate);
int save_error_analysis_to_csv(const char* filename, const double* original, const double* processed, 
                               size_t size, double sampling_rate);

void free_signal(double* signal);

#ifdef __cplusplus
}
#endif

#endif // UTILS_H
