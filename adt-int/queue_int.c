#include "queue_int.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list_double_int.h"

/**
 * Type definitions
 */

struct queue_int {
    list_double_int_t *implementation;
};

/*
 * Function body
 */

queue_int_t *queue_int_alloc(void) {
    return malloc(sizeof(queue_int_t));
}

void queue_int_init(queue_int_t *queue) {
    queue->implementation = list_double_int_alloc();
    list_double_int_init(queue->implementation);
}

void queue_int_free(queue_int_t *queue) {
    list_double_int_free(queue->implementation);
    free(queue);
}

bool queue_int_is_empty(queue_int_t *queue) {
    return list_double_int_is_empty(queue->implementation);
}

int queue_int_size(queue_int_t *queue) {
    return list_double_int_size(queue->implementation);
}

bool queue_int_enqueue(queue_int_t *queue, int value) {
    return list_double_int_add_back(queue->implementation, value);
}

bool queue_int_peek(queue_int_t *queue, int *returned) {
    return list_double_int_get(queue->implementation, 0, returned);
}

bool queue_int_dequeue(queue_int_t *queue, int *returned) {
    bool success = queue_int_peek(queue, returned);
    return success && list_double_int_remove_front(queue->implementation);
}

void queue_int_print(queue_int_t *queue, FILE *stream) {
    list_double_int_print(queue->implementation, stream);
}
