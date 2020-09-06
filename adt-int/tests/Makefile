CC			= gcc
LIBTESTDIR	= ../../libtest
DEBUGFLAGS	= -g
WARNFLAGS	= -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -std=c99 -fsanitize=undefined
CFLAGS		= $(DEBUGFLAGS) $(WARNFLAGS) -Iinclude/ -I$(TESTDIR)/include/

LDLIBS		= -L$(TESTDIR) -ltest
LDFLAGS		= -fsanitize=undefined
TEST		= 

all:	test

test:	$(TEST)

clean:
	rm -f $(TEST)



.SUFFIXES:	.c .o
.PHONY:		all test clean