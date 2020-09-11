#ifndef QUEUE_INT_H
#define QUEUE_INT_H

#include <stdbool.h>
#include <stdio.h>

/* 
 * Type declarations 
 */

typedef struct queue_int queue_int_t;

/*
 * Function declarations 
 */

queue_int_t *queue_int_alloc(void);
void queue_int_init(queue_int_t *queue);
void queue_int_free(queue_int_t *queue);

bool queue_int_is_empty(queue_int_t *queue);
int queue_int_size(queue_int_t *queue);

bool queue_int_enqueue(queue_int_t *queue, int value);
bool queue_int_peek(queue_int_t *queue, int *returned);
bool queue_int_dequeue(queue_int_t *queue, int *returned);

void queue_int_print(queue_int_t *queue, FILE *stream);

#endif  //QUEUE_INT_H