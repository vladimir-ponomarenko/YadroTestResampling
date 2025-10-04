#include "dsp.h"
#include "tests.h"

char* test_decimate_2x_return_arr(){
    const double test_arr[] = {1.0, 1.0, 1.0};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = dsp_decimate_2x(test_arr, test_size, &res_size);

    ASSERT_DOUBLE_EQUALS(res_size, ((test_size + 1)/2));

    return NULL;
}

char* test_decimate_2x_zeros_even(){
    const double test_arr[] = {0.0, 0.0, 0.0, 0.0};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = dsp_decimate_2x(test_arr, test_size, &res_size);

    int flag = 1;
    
    for (size_t i = 1; i < res_size - 1; i++) {
        if (res_arr[i] != test_arr[i * 2]) {
            flag = 0;
            goto test_assert;
        }
        
    }
    
    test_assert:
    ASSERT_TRUE(flag == 1);
    ASSERT_DOUBLE_EQUALS(res_size, (test_size + 1) / 2);

    return NULL;
}

char* test_decimate_2x_zeros_odd(){
    const double test_arr[] = {0.0, 0.0, 0.0};
    const size_t test_size = sizeof(test_arr) / sizeof(test_arr[0]);

    size_t res_size = 0;
    double* res_arr = dsp_decimate_2x(test_arr, test_size, &res_size);

    int flag = 1;
    
    for (size_t i = 1; i < res_size - 1; i++) {
        if (res_arr[i] != test_arr[i * 2]) {
            flag = 0;
            goto test_assert;
        }
        
    }
    
    test_assert:
    ASSERT_TRUE(flag == 1);
    ASSERT_DOUBLE_EQUALS(res_size, (test_size + 1) / 2);

    return NULL;
}