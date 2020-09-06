CC			= gcc
DEBUGFLAGS	= -g
WARNFLAGS	= -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -std=c99 -fsanitize=undefined
CFLAGS		= $(DEBUGFLAGS) $(WARNFLAGS) -Iinclude/

LDLIBS		= 
LDFLAGS		= -fsanitize=undefined
LIB			= libtest.a
LIBOBJS		= testsuite.o

all:	build lib

build:	$(LIBOBJS)

lib:	build
	ar rcs $(LIB) $(LIBOBJS)

clean:
	rm -f $(LIBOBJS) $(LIB)

testsuite.o:	include/testsuite.h

.SUFFIXES:	.c .o
.PHONY:		all build lib clean
