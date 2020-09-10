#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <stdbool.h>

#define SHOW_ALL_TESTS 1

struct unit_test {
    char *name;
    void (*runner)(void);
};

void testbool(bool condition, char *test_name);
void run_unit_test(struct unit_test test);
void run_all_tests(struct unit_test tests[], int num_tests);

#endif //TESTSUITE_H