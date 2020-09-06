CC			= gcc
DEBUGFLAGS	= -g
WARNFLAGS	= -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -std=c99 -fsanitize=undefined
CFLAGS		= $(DEBUGFLAGS) $(WARNFLAGS) -Iinclude/

LDLIBS		= 
LDFLAGS		= -fsanitize=undefined
LIB			= libadt-int.a
LIBOBJS		= 

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



.SUFFIXES:	.c .o
.PHONY:		all build lib test clean
