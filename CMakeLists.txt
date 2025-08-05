cmake_minimum_required(VERSION 3.10)
project(YadroTestResempling C)

include_directories(include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

# Unit-tests
add_executable(dsp_tests
    src/dsp.c
    tests/tests.c
    tests/test_sine_generator.c
    tests/test_interpolate_2x.c
)

target_include_directories(dsp_tests PRIVATE tests)

target_link_libraries(dsp_tests m)


add_executable(dsp_app
    src/main.c
)

target_link_libraries(dsp_app m)


add_test(NAME dsp_unit_tests COMMAND dsp_tests)
