#include "tests.h"

int tests_run = 0;
int tests_failed = 0;

int main(int argc, char const *argv[])
{

    printf("Starting tests...\n");
    RUN_TEST(test_sine_generator_at_zero);
    RUN_TEST(test_sine_generator_at_one);

    printf("\n--- Test Summary ---\n");
    if (tests_failed == 0) {
        printf("All %d tests passed!\n", tests_run);
        return 0;
    } else {
        printf("%d out of %d tests failed.\n", tests_failed, tests_run);
        return 1;
    }

    return 0;
}
