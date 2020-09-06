#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <stdbool.h>

#define SHOW_ALL_TESTS 1

void testbool(bool condition, char *test_name);
void run_unit_test(char *test_name, void (*test_runner)(void));

#endif //TESTSUITE_H