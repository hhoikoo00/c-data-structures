#include "testsuite.h"
#include "list_double_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Helper functions 
 */

static list_double_int_t *get_empty_list(void) {
    list_double_int_t *list_test = list_double_int_alloc();
    list_double_int_init(list_test);
    return list_test;
}

static list_double_int_t *get_list_with_5_elems(void) {
    list_double_int_t *list_test = list_double_int_alloc();
    list_double_int_init(list_test);

    for (int i = 0; i < 5; i++) {
        list_double_int_add_back(list_test, i);
    }

    return list_test;
}

/**
 * Tests
 */

void test_composite(void);

void test_list_alloc_init_works(void) {
    list_double_int_t *list_test = list_double_int_alloc();

    testbool(list_test != NULL, "list is correctly allocated");

    list_double_int_init(list_test);

    testbool(list_double_int_is_empty(list_test), "list is empty after initialization");

    list_double_int_free(list_test);
}

void test_add_element_sequentially(void) {
    list_double_int_t *list = get_empty_list();

    testbool(list_double_int_is_empty(list), "list is initially empty");

    for (int i = 0; i < 10; ++i) {
        list_double_int_add(list, i, 10 - i);
    }

    testbool(list_double_int_size(list) == 10, "list contains 10 elements after insert");

    int value;
    bool test_exists = true;
    bool test_correct_value = true;
    for (int i = 0; i < 10; ++i) {
        test_exists = test_exists && (list_double_int_get(list, i, &value));
        if (test_exists) {
            test_correct_value = test_correct_value && (value == 10 - i);
        }
    }
    // list has correct values only if the elements do exist
    test_correct_value = test_exists && test_correct_value;

    testbool(test_exists, "list does have all elements");
    testbool(test_correct_value, "list contains correct values");

    list_double_int_free(list);
}

void test_add_element_front(void) {
    list_double_int_t *list;
    int value;
    bool exists;

    list = get_empty_list();
    // []

    list_double_int_add_front(list, 10);
    // [10]
    exists = list_double_int_get(list, 0, &value);
    testbool(list_double_int_size(list) == 1, "list has 1 element after insert");
    testbool(exists && value == 10, "works with an empty list");

    list_double_int_add_front(list, 20);
    // [20, 10]
    exists = list_double_int_get(list, 0, &value);
    testbool(list_double_int_size(list) == 2, "list has 2 elements after insert");
    testbool(exists && value == 20, "works with a singleton list");

    list_double_int_free(list);

    list = get_list_with_5_elems();
    // [0, 1, 2, 3, 4]

    list_double_int_add_front(list, 10);
    // [10, 0, 1, 2, 3, 4]
    exists = list_double_int_get(list, 0, &value);
    testbool(exists && value == 10, "works with a populated list");

    list_double_int_free(list);
}

void test_add_element_back(void) {
    list_double_int_t *list;
    int value;
    bool exists;

    list = get_empty_list();
    // []

    list_double_int_add_back(list, 10);
    // [10]
    exists = list_double_int_get(list, 0, &value);
    testbool(list_double_int_size(list) == 1, "list has 1 element after insert");
    testbool(exists && value == 10, "works with an empty list");

    list_double_int_add_back(list, 20);
    // [10, 20]
    exists = list_double_int_get(list, 1, &value);
    testbool(list_double_int_size(list) == 2, "list has 2 elements after insert");
    testbool(exists && value == 20, " works with a singleton list");

    list_double_int_free(list);

    list = get_list_with_5_elems();
    // [0, 1, 2, 3, 4]

    list_double_int_add_back(list, 10);
    // [0, 1, 2, 3, 4, 10]
    exists = list_double_int_get(list, 5, &value);
    testbool(exists && value == 10, "works with a populated list");

    list_double_int_free(list);
}

void test_add_element_random(void) {
    list_double_int_t *list;
    int value;
    bool exists;

    list = get_empty_list();
    // []
    list_double_int_add(list, 0, 0);
    // [0]
    list_double_int_add(list, 1, 4);
    // [0, 4]
    list_double_int_add(list, 1, 3);
    // [0, 3, 4]
    list_double_int_add(list, 1, 2);
    // [0, 2, 3, 4]
    list_double_int_add(list, 1, 1);
    // [0, 1, 2, 3, 4]
    list_double_int_add(list, 5, 5);
    // [0, 1, 2, 3, 4, 5]

    bool testresult = true;
    for (int i = 0; i < 6; ++i) {
        exists = list_double_int_get(list, i, &value);
        testresult = testresult && exists && (value == i);
    }
    testbool(testresult, "repeatedly adding elements at the edge works");

    list_double_int_free(list);

    list = get_list_with_5_elems();
    // [0, 1, 2, 3, 4]
    list_double_int_add(list, 2, 10);
    // [0, 1, 10, 2, 3, 4]

    testbool(list_double_int_size(list) == 6, "adding an item in the middle increases the size");

    testresult = true;
    int expected[] = {1, 10, 2};
    for (int i = 1; i < 4; ++i) {
        exists = list_double_int_get(list, i, &value);
        testresult = testresult && exists && (value == expected[i - 1]);
    }
    testbool(testresult, "value is added correctly in the middle");

    list_double_int_free(list);
}

void test_size(void) {
    list_double_int_t *list = get_empty_list();
    testbool(list_double_int_size(list) == 0, "size of empty list is 0");

    list_double_int_add_front(list, 1);
    testbool(list_double_int_size(list) == 1, "size of singleton list is 1");

    bool testresult = true;
    for (int i = 1; i <= 10; i++) {
        list_double_int_add_back(list, i);
        testresult = testresult && (list_double_int_size(list) == i + 1);
    }
    testbool(testresult, "size calculated correctly after repeated insertion");

    int list_size = list_double_int_size(list);
    testresult = true;
    for (int i = 0; i < list_size; i++) {
        testresult = testresult && (list_double_int_size(list) == list_size - i);
        list_double_int_remove_back(list);
    }
    testbool(testresult, "size calculated correctly after repeated deletion");
    testbool(list_double_int_size(list) == 0, "the list is empty again");

    list_double_int_free(list);
}

void test_remove_front(void) {
    list_double_int_t *list;
    bool success;
    int returned;

    list = get_empty_list();
    // []
    testbool(!list_double_int_remove_front(list), "removing on an empty list fails and returns false");

    list_double_int_add_back(list, 0);
    // [0]
    success = list_double_int_remove_front(list);
    // []
    testbool(success && !list_double_int_get(list, 0, &returned) && list_double_int_is_empty(list),
             "removing on a singleton list will empty the list");

    list_double_int_free(list);
    list = get_list_with_5_elems();
    // [0, 1, 2, 3, 4]

    success = list_double_int_remove_front(list);
    // [1, 2, 3, 4]
    testbool(success && list_double_int_get(list, 0, &returned) && list_double_int_size(list) == 4 && returned == 1,
             "removing on a populated list successfully removes the first element");

    list_double_int_free(list);
}

void test_remove_back(void) {
    list_double_int_t *list;
    bool success;
    int returned;

    list = get_empty_list();
    // []
    testbool(!list_double_int_remove_back(list), "removing on an empty list fails and returns false");

    list_double_int_add_back(list, 0);
    // [0]
    success = list_double_int_remove_back(list);
    // []
    testbool(success && !list_double_int_get(list, 0, &returned) && list_double_int_is_empty(list),
             "removing on a singleton list will empty the list");

    list_double_int_free(list);
    list = get_list_with_5_elems();
    // [0, 1, 2, 3, 4]

    success = list_double_int_remove_back(list);
    // [0, 1, 2, 3]
    testbool(success && list_double_int_get(list, 3, &returned) && list_double_int_size(list) == 4 && returned == 3,
             "removing on a populated list successfully removes the last element");

    list_double_int_free(list);
}

void test_remove_random(void) {
    list_double_int_t *list;
    bool success;
    int returned;
    bool testresult;

    list = get_empty_list();
    // []
    testresult = true;
    for (int i = 0; i < 3; i++) {
        testresult = testresult && !list_double_int_remove(list, i);
    }
    testbool(testresult, "trying to remove on an empty list returns false");

    list_double_int_free(list);
    list = get_list_with_5_elems();
    // [0, 1, 2, 3, 4]

    success = list_double_int_remove(list, 0);
    // [1, 2, 3, 4]
    list_double_int_get(list, 0, &returned);
    testbool(success && list_double_int_size(list) == 4 && returned == 1,
             "removing the first element with remove works");

    success = list_double_int_remove(list, 2);
    // [1, 2, 4]
    list_double_int_get(list, 2, &returned);
    testbool(success && list_double_int_size(list) == 3 && returned == 4,
             "removing the middle element with remove works");

    success = list_double_int_remove(list, 2);
    // [1, 2]
    list_double_int_get(list, 1, &returned);
    testbool(success && list_double_int_size(list) == 2 && returned == 2 && !list_double_int_get(list, 2, &returned),
             "removing the last element with remove works");

    list_double_int_remove(list, 1);
    // [1]
    success = list_double_int_remove(list, 0);
    // []
    testbool(success && list_double_int_is_empty(list),
             "removing on a singleton list works");

    list_double_int_free(list);
}

int main(void) {
    run_unit_test("list alloc and init works", &test_list_alloc_init_works);
    run_unit_test("adding items sequentially works", &test_add_element_sequentially);
    run_unit_test("add_front works", &test_add_element_front);
    run_unit_test("add_back works", &test_add_element_back);
    run_unit_test("add works for arbitary random insertion", &test_add_element_random);
    run_unit_test("size works", &test_size);
    run_unit_test("remove_front works", &test_remove_front);
    run_unit_test("remove_back works", &test_remove_back);
    run_unit_test("remove works", &test_remove_random);

    // run_unit_test("composite test: for temporary testing", &test_composite);
}

void test_composite(void) {
    list_double_int_t *list = get_list_with_5_elems();
    list_double_int_print(list, stdout);

    list_double_int_free(list);

    list = get_empty_list();
    list_double_int_print(list, stdout);

    list_double_int_add_front(list, 2);
    list_double_int_print(list, stdout);

    list_double_int_add_front(list, 5);
    list_double_int_print(list, stdout);

    list_double_int_add_back(list, 10);
    list_double_int_print(list, stdout);

    list_double_int_add(list, 1, 1);
    list_double_int_print(list, stdout);

    list_double_int_remove_front(list);
    list_double_int_print(list, stdout);

    list_double_int_remove_back(list);
    list_double_int_print(list, stdout);

    list_double_int_remove(list, 1);
    list_double_int_print(list, stdout);

    list_double_int_remove(list, 2);
    list_double_int_print(list, stdout);

    list_double_int_free(list);
}