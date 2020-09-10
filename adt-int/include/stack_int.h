#ifndef STACK_INT_H
#define STACK_INT_H

#include <stdbool.h>
#include <stdio.h>

/* 
 * Type declarations 
 */

typedef struct stack_int stack_int_t;

/*
 * Function declarations 
 */

stack_int_t *stack_int_alloc(void);
void stack_int_init(stack_int_t *stack);
void stack_int_free(stack_int_t *stack);

bool stack_int_is_empty(stack_int_t *stack);
int stack_int_size(stack_int_t *stack);

bool stack_int_push(stack_int_t *stack, int value);
bool stack_int_peek(stack_int_t *stack, int *returned);
bool stack_int_pop(stack_int_t *stack, int *returned);

void stack_int_print(stack_int_t *stack, FILE *stream);

#endif  //STACK_INT_H