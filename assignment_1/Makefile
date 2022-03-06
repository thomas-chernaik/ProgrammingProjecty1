#define macros for compiler and flags
CC= gcc
CFLAGS = -g -std=c99

SRC= pgmEcho.c pgmHeaders.c pgmRead.c pgmWrite.c
OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

pgmEcho: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o pgmEcho

pgmHeaders.o: pgmHeaders.c pgmHeaders.h
	$(CC) $(CFLAGS) -c pgmHeaders.c pgmHeaders.h
pgmRead.o: pgmRead.c pgmRead.h
	$(CC) $(CFLAGS) -c pgmRead.c pgmRead.h
pgmWrite.o: pgmWrite.c pgmWrite.h
	$(CC) $(CFLAGS) -c pgmWrite.c pgmWrite.h
pgmEcho.o: pgmEcho.c pgmEcho.h pgmHeaders.o pgmRead.o pgmWrite.o
	$(CC) $(CFLAGS) -c pgmEcho.c pgmEcho.h pgmHeaders.o pgmRead.o pgmWrite.o
clean:
	rm -f *.o
