#ifndef LIST_SINGLE_INT_H
#define LIST_SINGLE_INT_H

#include <stdio.h>
#include <stdbool.h>

/* 
 * Type declarations 
 */

typedef struct list_single_int_elem list_single_int_elem;

typedef list_single_int_elem * list_single_int_iter;

typedef struct list_single_int list_single_int_t;

typedef void (*list_single_int_elem_callback_func)(list_single_int_elem *);

/*
 * Function declarations 
 */

list_single_int_t *list_single_int_alloc(void);
void list_single_int_init(list_single_int_t *list);
void list_single_int_free(list_single_int_t *list);

bool list_single_int_is_empty(list_single_int_t *list);
int list_single_int_size(list_single_int_t *list);

bool list_single_int_get(list_single_int_t *list, int index, int *returned);

bool list_single_int_add(list_single_int_t *list, int index, int item);
bool list_single_int_add_front(list_single_int_t *list, int item);
bool list_single_int_add_back(list_single_int_t *list, int item);

bool list_single_int_remove(list_single_int_t *list, int index);
bool list_single_int_remove_front(list_single_int_t *list);
bool list_single_int_remove_back(list_single_int_t *list);

void list_single_int_foreach(list_single_int_t *list, list_single_int_elem_callback_func func);
void list_single_int_print(list_single_int_t *list, FILE *stream);

list_single_int_iter list_single_int_begin(list_single_int_t *list);
list_single_int_iter list_single_int_next(list_single_int_iter iter);
int list_single_int_value(list_single_int_iter iter);

#endif  //LIST_SINGLE_INT_H