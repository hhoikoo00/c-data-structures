#include "stack_int.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list_single_int.h"

/**
 * Type definitions
 */

struct stack_int {
    list_single_int_t *implementation;
};

/*
 * Function body
 */

stack_int_t *stack_int_alloc(void) {
    return malloc(sizeof(stack_int_t));
}

void stack_int_init(stack_int_t *stack) {
    stack->implementation = list_single_int_alloc();
    list_single_int_init(stack->implementation);
}

void stack_int_free(stack_int_t *stack) {
    list_single_int_free(stack->implementation);
    free(stack);
}

bool stack_int_is_empty(stack_int_t *stack) {
    return list_single_int_is_empty(stack->implementation);
}

int stack_int_size(stack_int_t *stack) {
    return list_single_int_size(stack->implementation);
}

bool stack_int_push(stack_int_t *stack, int value) {
    return list_single_int_add_front(stack->implementation, value);
}

bool stack_int_peek(stack_int_t *stack, int *returned) {
    return list_single_int_get(stack->implementation, 0, returned);
}

bool stack_int_pop(stack_int_t *stack, int *returned) {
    bool success = stack_int_peek(stack, returned);
    return success && list_single_int_remove_front(stack->implementation);
}

void stack_int_print(stack_int_t *stack, FILE *stream) {
    list_single_int_print(stack->implementation, stream);
}
