#define macros for compiler and flags
CC= gcc
CFLAGS = -g -std=c99

SRCECHO= pgmEcho.c pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c
SRCREDUCE= pgmReduce.c pgmHeaders.c pgmRead.c pgmWrite.c pgmBinWrite.c pgmReadBinary.c pgmReduceSize.c
SRCCOMP = pgmComp.c pgmHeaders.c pgmRead.c pgmReadBinary.c pgmCompare.c
SRCA2B = pgma2b.c pgmHeaders.c pgmRead.c pgmBinWrite.c
SRCB2A = pgmb2a.c pgmHeaders.c pgmReadBinary.c pgmWrite.c
OBJB2A = $(SRCB2A:.c=.o)
OBJA2B = $(SRCA2B:.c=.o)
OBJREDUCE = $(SRCREDUCE:.c=.o)
OBJECHO = $(SRCECHO:.c=.o)
OBJCOMP = $(SRCCOMP:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

pgmEcho: $(OBJECHO)
	$(CC) $(CFLAGS) $(OBJECHO) -o pgmEcho

pgmComp: $(OBJCOMP)
	$(CC) $(CFLAGS) $(OBJCOMP) -o pgmComp

pgma2b: $(OBJA2B)
	$(CC) $(CFLAGS) $(OBJA2B) -o pgma2b

pgmb2a: $(OBJB2A)
	$(CC) $(CFLAGS) $(OBJB2A) -o pgmb2a

pgmReduce: $(OBJREDUCE)
	$(CC) $(CFLAGS) $(OBJREDUCE) -o pgmReduce
	

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
pgma2b.o: pgma2b.c pgmRead.o pgmBinWrite.o
	$(CC) $(CFLAGS) -c pgma2b.c pgmRead.o pgmBinWrite.o
pgmb2a.o: pgmb2a.c pgmReadBinary.o pgmWrite.o
	$(CC) $(CFLAGS) -c pgmb2a.c pgmReadBinary.o pgmWrite.o
pgmReduce.p: pgmReduce.c pgmHeaders.o pgmRead.o pgmWrite.o pgmReadBinary.o pgmBinWrite.o pgmReduceSize.o
	$(CC) $(CFLAGS) -c pgmReduce.c pgmHeaders.o pgmRead.o pgmWrite.o pgmReadBinary.o pgmBinWrite.o pgmReduceSize.o
pgmEcho.o: pgmEcho.c pgmHeaders.o pgmRead.o pgmWrite.o pgmReadBinary.o pgmBinWrite.o
	$(CC) $(CFLAGS) -c pgmEcho.c pgmHeaders.o pgmRead.o pgmWrite.o pgmReadBinary.o pgmBinWrite.o

pgmComp.o: pgmComp.c pgmHeaders.o pgmRead.o pgmReadBinary.o pgmCompare.o
	$(CC) $(CFLAGS) -c pgmComp.c pgmHeaders.o pgmRead.o pgmReadBinary.o pgmCompare.o
clean:
	rm -f *.o
