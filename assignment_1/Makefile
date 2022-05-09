#define macros for compiler and flags
CC= gcc
CFLAGS = -g -std=c99 -Wall

SRCECHO= pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c
SRCTILE = pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c pgmSubImage.c
SRCREDUCE= pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c pgmReduceSize.c
SRCASS= pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c pgmInsert.c pgmEmpty.c
SRCCOMP = pgmHeaders.c pgmRead.c pgmReadBinary.c pgmCompare.c
SRCA2B = pgmHeaders.c pgmRead.c pgmBinWrite.c
SRCB2A = pgmHeaders.c pgmReadBinary.c pgmWrite.c
OBJASS = $(SRCASS:.c=.o)
OBJTILE = $(SRCTILE:.c=.o)
OBJB2A = $(SRCB2A:.c=.o)
OBJA2B = $(SRCA2B:.c=.o)
OBJREDUCE = $(SRCREDUCE:.c=.o)
OBJECHO = $(SRCECHO:.c=.o)
OBJCOMP = $(SRCCOMP:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble



pgmEcho: pgmEcho.c $(OBJECHO)
	$(CC) $(CFLAGS) pgmEcho.c $(OBJECHO) -o pgmEcho

pgmComp: pgmComp.c $(OBJCOMP)
	$(CC) $(CFLAGS) pgmComp.c $(OBJCOMP) -o pgmComp

pgma2b: pgma2b.c $(OBJA2B)
	$(CC) $(CFLAGS) pgma2b.c $(OBJA2B) -o pgma2b

pgmb2a: pgmb2a.c $(OBJB2A)
	$(CC) $(CFLAGS) pgmb2a.c $(OBJB2A) -o pgmb2a

pgmReduce: pgmReduce.c $(OBJREDUCE)
	$(CC) $(CFLAGS) pgmReduce.c $(OBJREDUCE) -o pgmReduce 

pgmTile: pgmTile.c $(OBJTILE)
	$(CC) $(CFLAGS) pgmTile.c $(OBJTILE) -o pgmTile	

pgmAssemble: pgmAssemble.c $(OBJASS)
	$(CC) $(CFLAGS) pgmAssemble.c $(OBJASS) -o pgmAssemble

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
pgmCompare.o: pgmCompare.c pgmCompare.h
	$(CC) $(CFLAGS) -c pgmCompare.c pgmCompare.h
pgmReduceSize.o: pgmReduceSize.c pgmReduceSize.h
	$(CC) $(CFLAGS) -c pgmReduceSize.c pgmReduceSize.h
pgmSubImage.o: pgmSubImage.c pgmSubImage.h
	$(CC) $(CFLAGS) -c pgmSubImage.c pgmSubImage.h 
pgmEmpty.o: pgmEmpty.c pgmEmpty.h
	$(CC) $(CFLAGS) -c pgmEmpty.c pgmEmpty.h
pgmInsert.o: pgmInsert.c pgmInsert.h
	$(CC) $(CFLAGS) -c pgmInsert.c pgmInsert.h
clean:
	rm -f *.o *.gch pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble
