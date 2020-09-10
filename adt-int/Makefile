CC			= gcc
DEBUGFLAGS	= -g
WARNFLAGS	= -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -std=c99 -fsanitize=undefined
CFLAGS		= $(DEBUGFLAGS) $(WARNFLAGS) -Iinclude/

LDLIBS		= 
LDFLAGS		= -fsanitize=undefined
LIB			= libadt_int.a
LIBOBJS		= list_single_int.o list_double_int.o stack_int.o

all:	build lib test

build:	$(LIBOBJS)

lib:	build
ifdef LIB
	ar rcs $(LIB) $(LIBOBJS)
endif

test:
	cd test; make all

clean:
	cd test; make clean
	rm -f $(wildcard *.o) $(wildcard *.a)

list_single_int.o:	include/list_single_int.h
list_double_int.o:	include/list_double_int.h
stack_int.o:	include/stack_int.h

.SUFFIXES:	.c .o
.PHONY:		all build lib test clean
