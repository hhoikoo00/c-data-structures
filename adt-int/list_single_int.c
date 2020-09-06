#include "list_single_int.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Type definitions
 */

struct list_single_int_elem {
    int value;
    struct list_single_int_elem *next;
};

struct list_single_int {
    /* header always points to the null element */
    list_single_int_elem *header;
};

/**
 * Helper functions
 */

static list_single_int_elem *
list_single_int_elem_create(int value) {
    list_single_int_elem *elem = malloc(sizeof(list_single_int_elem));
    if (elem == NULL) {
        perror("elem allocation failed");
        exit(EXIT_FAILURE);
    }
    elem->value = value;
    elem->next = NULL;
    return elem;
}

static void list_single_int_elem_free(list_single_int_elem *elem) {
    free(elem);
}

/*
 * Function body
 */

/**
 * Allocate memory for a new list
 * 
 * @return A new uninitialized list allocated on the heap
 */
list_single_int_t *list_single_int_alloc(void) {
    return malloc(sizeof(list_single_int_t));
}

/**
 * Initialize an uninitialized list
 * 
 * @param list an uninitialized list
 */
void list_single_int_init(list_single_int_t *list) {
    assert(list != NULL);

    list->header = list_single_int_elem_create(0);
}

/** 
 * Free the allocated memory for the list and all elements in it
 *  
 * @param list list to free the allocated memory
 */
void list_single_int_free(list_single_int_t *list) {
    assert(list != NULL);

    list_single_int_foreach(list, &list_single_int_elem_free);
    free(list->header);
    free(list);
}

/**
 * Check if the list is empty or not
 * 
 * @param list list to check
 * @return true if list is empty; false if not
 */
bool list_single_int_is_empty(list_single_int_t *list) {
    assert(list != NULL);

    return list->header->next == NULL;
}

/**
 * Returns the number of elements in the list
 * 
 * @param list list to check
 * @return the size of the list i.e. number of elements
 */
int list_single_int_size(list_single_int_t *list) {
    assert(list != NULL);

    int size = 0;

    list_single_int_elem *cur = list->header->next;
    // traverse through the list
    while (cur != NULL) {
        ++size;
        cur = cur->next;
    }
    return size;
}

/**
 * Get the element at the specified index, if it exists
 * 
 * @param list list to get the element
 * @param index position at the list to get the element
 * @param returned pointer to a variable to store the result
 * @return whether there is an element at the given index
 */
bool list_single_int_get(list_single_int_t *list, int index, int *returned) {
    assert(list != NULL && returned != NULL);
    assert(0 <= index);

    list_single_int_elem *cur = list->header->next;
    // traverse through the list
    while (cur != NULL) {
        if (index-- == 0) {
            // desired position reached
            *returned = cur->value;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

/**
 * Add a given item to the list at a given index
 * 
 * @param list list to add the element
 * @param index index of the list to add the element
 * @param item item to add
 * @return whether the item was successfully added
 */
bool list_single_int_add(list_single_int_t *list, int index, int item) {
    assert(list != NULL);
    assert(0 <= index);

    list_single_int_elem *prev;
    list_single_int_elem *cur = list->header;
    // traverse through the list
    while (cur != NULL) {
        prev = cur;
        cur = prev->next;

        if (index-- == 0) {
            // desired position reached
            list_single_int_elem *new_elem = list_single_int_elem_create(item);
            prev->next = new_elem;
            new_elem->next = cur;
            return true;
        }
    }
    return false;
}

/**
 * Add a given item to the beginning of the list
 * 
 * @param list list to add the element
 * @param item item to add
 * @return whether the item was successfully added
 */
bool list_single_int_add_front(list_single_int_t *list, int item) {
    assert(list != NULL);

    list_single_int_elem *first = list_single_int_elem_create(item);
    list_single_int_elem *second = list->header->next;

    list->header->next = first;
    first->next = second;

    return true;
}

/**
 * Add a given item to the end of the list
 * 
 * @param list list to add the element
 * @param item item to add
 * @return whether the item was successfully added
 */
bool list_single_int_add_back(list_single_int_t *list, int item) {
    assert(list != NULL);

    list_single_int_elem *prev;
    list_single_int_elem *cur = list->header;

    // traverse through the list
    while (cur != NULL) {
        prev = cur;
        cur = prev->next;
    }

    list_single_int_elem *new_elem = list_single_int_elem_create(item);
    prev->next = new_elem;
    assert(cur == NULL);
    new_elem->next = cur;
    return true;
}

/**
 * Remove an item of the list at a given index
 * 
 * @param list list to remove the element
 * @param index index of the list to remove the element
 * @return whether the item was successfully removed
 */
bool list_single_int_remove(list_single_int_t *list, int index) {
    assert(list != NULL);
    assert(0 <= index);

    if (list_single_int_is_empty(list)) {
        return false;
    }

    list_single_int_elem *prev;
    list_single_int_elem *cur = list->header;
    // traverse through the list
    while (cur != NULL) {
        prev = cur;
        cur = prev->next;

        if (index-- == 0) {
            // desired position reached
            list_single_int_elem *next = cur->next;
            prev->next = next;
            list_single_int_elem_free(cur);
            return true;
        }
    }
    return false;
}

/**
 * Remove an item of the list at the beginning
 * 
 * @param list list to remove the element
 * @return whether the item was successfully removed
 */
bool list_single_int_remove_front(list_single_int_t *list) {
    assert(list != NULL);

    if (list_single_int_is_empty(list)) {
        return false;
    }

    list_single_int_elem *first = list->header->next;
    list_single_int_elem *second = first->next;

    list->header->next = second;
    list_single_int_elem_free(first);
    return true;
}

/**
 * Remove an item of the list at the end
 * 
 * @param list list to remove the element
 * @return whether the item was successfully removed
 */
bool list_single_int_remove_back(list_single_int_t *list) {
    assert(list != NULL);

    if (list_single_int_is_empty(list)) {
        return false;
    }

    list_single_int_elem *prev;
    list_single_int_elem *cur = list->header;
    // traverse through the list
    while (cur->next != NULL) {
        prev = cur;
        cur = prev->next;
    }

    assert(cur->next == NULL);
    prev->next = cur->next;
    list_single_int_elem_free(cur);
    return true;
}

/**
 * Applies the given callback function to each element in the list
 * 
 * @param list list to iterate on
 * @param func callback function that operates on individual list
 */
void list_single_int_foreach(list_single_int_t *list, list_single_int_elem_callback_func func) {
    assert(list != NULL && func != NULL);

    list_single_int_elem *cur;
    list_single_int_elem *next = list->header->next;
    // next maintains reference to the next element in case func 
    // destroys cur (like free())
    while (next != NULL) {
        cur = next;
        next = cur->next;
        func(cur);
    }
}

/**
 * Prints the given list to a given file object with an array-like syntax
 * 
 * @param list list to print
 * @param stream stream to print the list to
 */
void list_single_int_print(list_single_int_t *list, FILE *stream) {
    if (list_single_int_is_empty(list)) {
        fprintf(stream, "[]\n");
        return;
    }

    fprintf(stream, "[");
    fprintf(stream, "%d", list->header->next->value);
    list_single_int_elem *elem = list->header->next->next;
    while (elem != NULL) {
        fprintf(stream, ", %d", elem->value);
        elem = elem->next;
    }
    fprintf(stream, "]\n");
}

/**
 * Returns an iterator for the given list that iterates from the beginning
 * 
 * @param list list to get the iterator from
 * @return iterator that points to the beginning of the list
 */
list_single_int_iter list_single_int_begin(list_single_int_t *list) {
    return list->header->next;
}

/**
 * Makes the iterator to point to the next element and returns that iterator
 * Iterator given as the parameter is advanced
 * 
 * @param iter iterator to advance
 * @return the advanced iterator
 */
list_single_int_iter list_single_int_next(list_single_int_iter iter) {
    assert(iter != NULL);

    iter = iter->next;

    return iter;
}

/**
 * Returns the value stored in the current element the iterator points to
 * 
 * @param iter iterator to get the value of 
 * @return value of the element pointed by the iterator
 */
int list_single_int_value(list_single_int_iter iter) {
    assert(iter != NULL);

    return iter->value;
}