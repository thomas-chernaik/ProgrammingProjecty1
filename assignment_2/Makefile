#define macros for compiler and flags
CC = gcc
CFLAGS = -g -std=c99

SRCECHO = gtopoRead.c gtopoWrite.c

OBJECHO = $(SRCECHO:.c=.o)

#idk what this bit does i need to try deleting it and seeing if it breaks the makefile
.c.o:
	$(CC) $(CFLAGS) -c -o $A@ $<

all: gtopoEcho

gtopoEcho: gtopoEcho.c $(OBJECHO)
	$(CC) $(CFLAGS) gtopoEcho.c $(OBJECHO) -o gtopoEcho



gtopoRead.o: gtopoRead.c gtopoRead.h
	$(CC) $(CFLAGS) -c gtopoRead.c gtopoRead.h

gtopoWrite.o: gtopoWrite.c gtopoWrite.h
	$(CC) $(CFLAGS) -c gtopoWrite.c gtopoWrite.h



clean:
	rm -f *.o *.gch gtopoEcho
