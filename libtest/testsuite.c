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

void run_unit_test(char *test_name, void (*test_runner)(void)) {
    print_test_name(test_name);
    test_runner();
}