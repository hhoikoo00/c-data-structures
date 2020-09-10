#include "testsuite.h"
#include "stack_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Helper functions 
 */

static stack_int_t *get_empty_stack(void) {
    stack_int_t *stack = stack_int_alloc();
    stack_int_init(stack);
    return stack;
}

static stack_int_t *get_stack_with_5_elems(void) {
    stack_int_t *stack = stack_int_alloc();
    stack_int_init(stack);

    for (int i = 0; i < 5; i++) {
        stack_int_push(stack, i);
    }

    return stack;
}

/**
 * Tests
 */

void test_stack_alloc_init_works(void) {
    stack_int_t *stack = stack_int_alloc();

    testbool(stack != NULL, "stack is correctly allocated");

    stack_int_init(stack);

    testbool(stack_int_is_empty(stack), "stack is empty after init");

    stack_int_free(stack);
}

void test_push_works(void) {
    stack_int_t *stack;
    bool success;
    int value;

    stack = get_empty_stack();
    // []

    success = stack_int_push(stack, 0);
    // [0]
    success = success && stack_int_peek(stack, &value);
    testbool(success && stack_int_size(stack) == 1 && value == 0,
             "push works on an empty stack");

    success = stack_int_push(stack, 1);
    // [1, 0]
    success = success && stack_int_peek(stack, &value);
    testbool(success && stack_int_size(stack) == 2 && value == 1,
             "push works on a singleton stack");

    stack_int_free(stack);
    stack = get_stack_with_5_elems();
    // [4, 3, 2, 1, 0]

    success = stack_int_push(stack, 5);
    // [5, 4, 3, 2, 1, 0]
    success = success && stack_int_peek(stack, &value);
    testbool(success && stack_int_size(stack) == 6 && value == 5,
             "push works on a populated stack");

    stack_int_free(stack);
}

void test_pop_works(void) {
    stack_int_t *stack;
    bool success;
    int value;

    stack = get_stack_with_5_elems();
    // [4, 3, 2, 1, 0]

    int expected[] = {4, 3, 2, 1, 0};
    success = true;
    for (int i = 0; i < 5; i++) {
        success = success && stack_int_pop(stack, &value);
        if (success) {
            testbool(expected[i] == value && stack_int_size(stack) == 5 - 1 - i,
                     "pop returns the correct value");
        }
    }

    testbool(stack_int_is_empty(stack), "stack is empty after popping all elements");

    testbool(!stack_int_pop(stack, &value), "cannot pop on an empty stack");

    stack_int_free(stack);
}

int main(void) {
    struct unit_test all_tests[] = {
        {
            .name = "stack alloc and init works",
            .runner = &test_stack_alloc_init_works
        },
        {
            .name = "stack push works",
            .runner = &test_push_works
        },
        {
            .name = "stack pop works",
            .runner = &test_pop_works
        }
    };

    int size_of_tests = sizeof(all_tests) / sizeof(all_tests[0]);

    run_all_tests(all_tests, size_of_tests);
}
