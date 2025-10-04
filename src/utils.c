#include "utils.h"
#include <stdlib.h>
#include <string.h>

int save_signal_to_csv(const char* filename, const double* signal, size_t size, double sampling_rate) {
    if (filename == NULL || signal == NULL || size == 0) {
        return -1;
    }
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }
    
    // Write header
    fprintf(file, "time,signal\n");
    
    // Write data
    for (size_t i = 0; i < size; i++) {
        double time = (double)i / sampling_rate;
        fprintf(file, "%.6f,%.10f\n", time, signal[i]);
    }
    
    fclose(file);
    return 0;
}

int save_error_analysis_to_csv(const char* filename, const double* original, const double* processed, 
                               size_t size, double sampling_rate) {
    if (filename == NULL || original == NULL || processed == NULL || size == 0) {
        return -1;
    }
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }
    
    // Write header
    fprintf(file, "time,original,processed,error\n");
    
    // Write data
    for (size_t i = 0; i < size; i++) {
        double time = (double)i / sampling_rate;
        double error = original[i] - processed[i];
        fprintf(file, "%.6f,%.10f,%.10f,%.10f\n", time, original[i], processed[i], error);
    }
    
    fclose(file);
    return 0;
}

void free_signal(double* signal) {
    if (signal != NULL) {
        free(signal);
    }
}
