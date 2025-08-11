#include "dsp.h"
#include "tests.h"

const char* test_interpolate_2x_return_arr(){
    const double test_arr[] = {1.0, 1.0, 1.0};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = interpolate_2x(test_arr, test_size, &res_size);

    // printf("res_size = %d, test_size = %d", res_size, 2*test_size - 1);
    ASSERT_DOUBLE_EQUALS(res_size, 2*test_size - 1);

    return NULL;
}

const char* test_interpolate_2x_zeros(){
    const double test_arr[] = {0.0, 0.0, 0.0};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = interpolate_2x(test_arr, test_size, &res_size);

    int flag = 1;

    for (size_t i = 1; i < res_size - 2; i++) {
        if (i % 2 == 0) {continue;}
        double mean = (res_arr[i-1] + res_arr[i+1]) / 2;
        if (res_arr[i] != mean) {
            flag = 0;
            break;
        }
    }
    

    // printf("res_size = %d, test_size = %d", res_size, 2*test_size);
    ASSERT_TRUE(flag == 1);
    ASSERT_DOUBLE_EQUALS(res_size, 2*test_size - 1);

    return NULL;
}

const char* test_interpolate_2x_case_arr1(){
    const double test_arr[] = {1.9999, 2.7777, 4.44898};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = interpolate_2x(test_arr, test_size, &res_size);

    int flag = 1;

    for (size_t i = 1; i <= res_size - 2; i++) {
        if (i % 2 == 0) {continue;}
        double mean = (res_arr[i-1] + res_arr[i+1]) / 2;
        if (res_arr[i] != mean) {
            flag = 0;
            break;
        }
    }
    
    // printf("res_size = %d, test_size = %d", res_size, 2*test_size);
    ASSERT_TRUE(flag == 1);
    ASSERT_DOUBLE_EQUALS(res_size, 2*test_size - 1);

    return NULL;
}

const char* test_interpolate_2x_case_arr2(){
    const double test_arr[] = {44.0, 222.2222222, 0.0, 1000.0};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = interpolate_2x(test_arr, test_size, &res_size);

    int flag = 1;

    for (size_t i = 1; i <= res_size - 2; i++) {
        if (i % 2 == 0) {continue;}
        double mean = (res_arr[i-1] + res_arr[i+1]) / 2;
        if (res_arr[i] != mean) {
            flag = 0;
            break;
        }
    }
    
    // printf("res_size = %d, test_size = %d", res_size, 2*test_size);
    ASSERT_TRUE(flag == 1);
    ASSERT_DOUBLE_EQUALS(res_size, 2*test_size - 1);

    return NULL;
}