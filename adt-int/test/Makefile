CC			= gcc
DEBUGFLAGS	= -g
WARNFLAGS	= -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -std=c99 -fsanitize=undefined
CFLAGS		= $(DEBUGFLAGS) $(WARNFLAGS) -I$(INCLUDEDIR)/include/ -I$(LIBTESTDIR)/include/

INCLUDEDIR	= ..
LIBTESTDIR	= ../../libtest

LDLIBS		= -L$(LIBTESTDIR) -ltest -L$(INCLUDEDIR) -ladt_int
LDFLAGS		= -fsanitize=undefined
TEST		= test_list_single_int test_list_double_int test_stack_int

all:	clean testsuite test 

test:	$(TEST)

testsuite:
	cd $(LIBTESTDIR); make all

clean:
	rm -f $(TEST)

test_list_single_int:	$(INCLUDEDIR)/list_single_int.o
test_list_double_int:	$(INCLUDEDIR)/list_double_int.o
test_stack_int:	$(INCLUDEDIR)/stack_int.o

.SUFFIXES:	.c .o
.PHONY:		all test clean