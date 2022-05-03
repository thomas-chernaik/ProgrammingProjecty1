#define macros for compiler and flags
CC = gcc
CFLAGS = -g -std=c99

SRCECHO = gtopoRead.c gtopoWrite.c
SRCCOMP = gtopoRead.c gtopoCompare.c

OBJECHO = $(SRCECHO:.c=.o)
OBJCOMP = $(SRCCOMP:.c=.o)
#idk what this bit does i need to try deleting it and seeing if it breaks the makefile
.c.o:
	$(CC) $(CFLAGS) -c -o $A@ $<

all: gtopoEcho gtopoComp

gtopoEcho: gtopoEcho.c $(OBJECHO)
	$(CC) $(CFLAGS) gtopoEcho.c $(OBJECHO) -o gtopoEcho
gtopoComp: gtopoComp.c $(OBJCOMP)
	$(CC) $(CFLAGS) gtopoComp.c $(OBJCOMP) -o gtopoComp


gtopoRead.o: gtopoRead.c gtopoRead.h
	$(CC) $(CFLAGS) -c gtopoRead.c gtopoRead.h

gtopoWrite.o: gtopoWrite.c gtopoWrite.h
	$(CC) $(CFLAGS) -c gtopoWrite.c gtopoWrite.h

gtopoCompare.o: gtopoCompare.c gtopoCompare.h
	$(CC) $(CFLAGS) -c gtopoCompare.c gtopoCompare.h

clean:
	rm -f *.o *.gch gtopoEcho
