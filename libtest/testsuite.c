#include "testsuite.h"

#include <stdio.h>

#define SEPARATOR_LENGTH 64

static void print_separator(void) {
    for (int i = 0; i < SEPARATOR_LENGTH; ++i) {
        printf("-");
    }
    printf("\n");
}

static void print_test_name(char *test_name) {
    print_separator();
    printf("Test: %s\n", test_name);
    print_separator();
}

void testbool(bool condition, char *testname) {
#if (SHOW_ALL_TESTS == 0)
    if (!condition) {
        printf("FAIL %s\n", testname);
    }
#else
    printf("T %s: %s\n", testname, condition ? "OK" : "FAIL");
#endif
}

void run_unit_test(struct unit_test test) {
    print_test_name(test.name);
    test.runner();
}

void run_all_tests(struct unit_test tests[], int num_tests) {
    for (int i = 0; i < num_tests; i++) {
        run_unit_test(tests[i]);
    }
}