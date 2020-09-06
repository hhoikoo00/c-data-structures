CC			= gcc
DEBUGFLAGS	= -g
WARNFLAGS	= -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -std=c99 -fsanitize=undefined
CFLAGS		= $(DEBUGFLAGS) $(WARNFLAGS) -I$(INCLUDEDIR)/include/ -I$(LIBTESTDIR)/include/

INCLUDEDIR	= ..
LIBTESTDIR	= ../../libtest

LDLIBS		= -L$(LIBTESTDIR) -ltest
LDFLAGS		= -fsanitize=undefined
TEST		= test_list_single_int

all:	test

test:	$(TEST)

clean:
	rm -f $(TEST)

test_list_single_int:	$(INCLUDEDIR)/list_single_int.o

.SUFFIXES:	.c .o
.PHONY:		all test clean