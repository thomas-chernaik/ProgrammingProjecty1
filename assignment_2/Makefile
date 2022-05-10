#define macros for compiler and flags
CC = gcc
CFLAGS = -g -std=c99

SRCECHO = gtopoRead.c gtopoWrite.c
SRCCOMP = gtopoRead.c gtopoCompare.c
SRCREDUCE = gtopoRead.c gtopoWrite.c gtopoReduceSize.c
SRCTILE = gtopoRead.c gtopoWrite.c gtopoSubImage.c
SRCPRINTLAND = gtopoRead.c gtopoPrint.c

OBJECHO = $(SRCECHO:.c=.o)
OBJCOMP = $(SRCCOMP:.c=.o)
OBJREDUCE = $(SRCREDUCE:.c=.o)
OBJTILE = $(SRCTILE:.c=.o)
OBJPRINTLAND = $(SRCPRINTLAND:.c=.o)

#idk what this bit does i need to try deleting it and seeing if it breaks the makefile
.c.o:
	$(CC) $(CFLAGS) -c -o $A@ $<

all: gtopoEcho gtopoComp gtopoReduce gtopoTile gtopoPrintLand

gtopoEcho: gtopoEcho.c $(OBJECHO)
	$(CC) $(CFLAGS) gtopoEcho.c $(OBJECHO) -o gtopoEcho
gtopoComp: gtopoComp.c $(OBJCOMP)
	$(CC) $(CFLAGS) gtopoComp.c $(OBJCOMP) -o gtopoComp
gtopoReduce: gtopoReduce.c $(OBJREDUCE)
	$(CC) $(CFLAGS) gtopoReduce.c $(OBJREDUCE) -o gtopoReduce
gtopoTile: gtopoTile.c $(OBJTILE)
	$(CC) $(CFLAGS) gtopoTile.c $(OBJTILE) -o gtopoTile
gtopoPrintLand: gtopoPrintLand.c $(OBJPRINTLAND)
	$(CC) $(CFLAGS) gtopoPrintLand.c $(OBJPRINTLAND) -o gtopoPrintLand


gtopoRead.o: gtopoRead.c gtopoRead.h
	$(CC) $(CFLAGS) -c gtopoRead.c gtopoRead.h

gtopoWrite.o: gtopoWrite.c gtopoWrite.h
	$(CC) $(CFLAGS) -c gtopoWrite.c gtopoWrite.h

gtopoCompare.o: gtopoCompare.c gtopoCompare.h
	$(CC) $(CFLAGS) -c gtopoCompare.c gtopoCompare.h

gtopoReduceSize.o: gtopoReduceSize.c gtopoReduceSize.h
	$(CC) $(CFLAGS) -c gtopoReduceSize.c gtopoReduceSize.h

gtopoSubImage.o: gtopoSubImage.c gtopoSubImage.h
	$(CC) $(CFLAGS) -c gtopoSubImage.c gtopoSubImage.h
gtopoPrint.o: gtopoPrint.c gtopoPrint.h
	$(CC) $(CFLAGS) -c gtpoPrint.c gtopoPrint.h

clean:
	rm -f *.o *.gch gtopoEcho gtopoComp gtopoReduce gtopoTile
