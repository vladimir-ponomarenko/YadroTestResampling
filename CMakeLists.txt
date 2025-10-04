cmake_minimum_required(VERSION 3.10)
project(YadroTestResempling C)

include_directories(include)

find_package(OpenMP REQUIRED)

# Unit-tests
add_executable(dsp_tests
    src/dsp.c
    src/utils.c
    tests/tests.c
    tests/test_sine_generator.c
    tests/test_interpolate_2x.c
    tests/test_decimate_2x.c
    tests/test_error_calculation.c
    tests/test_pipeline.c
)

target_include_directories(dsp_tests PRIVATE tests)
target_link_libraries(dsp_tests m)

add_executable(dsp_app
    src/main.c
    src/dsp.c
    src/pipeline.c
    src/utils.c
)

target_link_libraries(dsp_app m)

add_test(NAME dsp_unit_tests COMMAND dsp_tests)
