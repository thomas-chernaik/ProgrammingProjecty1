#define macros for compiler and flags
CC= gcc
CFLAGS = -g -std=c99

SRC= pgmEcho.c pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c
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
pgmReadBinary.o: pgmReadBinary.c pgmReadBinary.h
	$(CC) $(CFLAGS) -c pgmReadBinary.c pgmReadBinary.h
pgmBinWrite.o: pgmBinWrite.c pgmBinWrite.h
	$(CC) $(CFLAGS) -c pgmBinWrite.c pgmBinWrite.h

pgmEcho.o: pgmEcho.c pgmEcho.h pgmHeaders.o pgmRead.o pgmWrite.o pgmReadBinary.o pgmBinWrite.o
	$(CC) $(CFLAGS) -c pgmEcho.c pgmEcho.h pgmHeaders.o pgmRead.o pgmWrite.o pgmReadBinary.o pgmBinWrite.o

clean:
	rm -f *.o
