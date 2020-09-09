#ifndef LIST_DOUBLE_INT_H
#define LIST_DOUBLE_INT_H

#include <stdio.h>
#include <stdbool.h>

/* 
 * Type declarations 
 */

typedef struct list_double_int_elem list_double_int_elem;

typedef list_double_int_elem *list_double_int_iter;

typedef struct list_double_int list_double_int_t;

typedef void (*list_double_int_elem_callback_func)(list_double_int_elem *);

/*
 * Function declarations 
 */

list_double_int_t *list_double_int_alloc(void);
void list_double_int_init(list_double_int_t *list);
void list_double_int_free(list_double_int_t *list);

bool list_double_int_is_empty(list_double_int_t *list);
int list_double_int_size(list_double_int_t *list);

bool list_double_int_get(list_double_int_t *list, int index, int *returned);

bool list_double_int_add(list_double_int_t *list, int index, int item);
bool list_double_int_add_front(list_double_int_t *list, int item);
bool list_double_int_add_back(list_double_int_t *list, int item);

bool list_double_int_remove(list_double_int_t *list, int index);
bool list_double_int_remove_front(list_double_int_t *list);
bool list_double_int_remove_back(list_double_int_t *list);

void list_double_int_foreach(list_double_int_t *list, list_double_int_elem_callback_func func);
void list_double_int_print(list_double_int_t *list, FILE *stream);

list_double_int_iter list_double_int_begin(list_double_int_t *list);
list_double_int_iter list_double_int_end(list_double_int_t *list);
list_double_int_iter list_double_int_next(list_double_int_iter iter);
list_double_int_iter list_double_int_prev(list_double_int_iter iter);
int list_double_int_value(list_double_int_iter iter);

#endif  //LIST_DOUBLE_INT_H