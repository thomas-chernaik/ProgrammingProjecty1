objects = pgmHeaders.o pgmRead.o pgmWrite.o pgmBinWrite.o pgmCompare.o pgmReadBinary.o pgma2b.o pgmb2a.o pgmReduceSize.o pgmSubImage.o pgmInsert.o pgmEmpty.o pgmEcho.o pgmComp.o pgmReduce.o pgmTile.o pgmAssemble.o

edit : $(objects)
	cc -o edit $(objects)

pgmHeaders.o : pgmHeaders.c
	cc -c pgmHeaders.c

pgmRead.o : pgmRead.c
	cc -c pgmRead.c

pgmWrite.o : pgmWrite.c
	cc -c pgmWrite.c

pgmBinWrite.o : pgmBinWrite.c
	cc -c pgmBinWrite.c

pgmCompare.o : pgmCompare.c
	cc -c pgmCompare.c

pgmReadBinary.o : pgmReadBinary.c
	cc -c pgmReadBinary.c

pgma2b.o : pgma2b.c pgmRead.c pgmBinWrite.c
	cc -c pgma2b.c

pgmb2a.o : pgma2b.c pgmReadBinary.c pgmWrite.c
	cc -c pgmb2a.o

pgmReduceSize.o : pgmReduceSize.c
	cc -c pgmReduceSize.c

pgmSubImage.o : pgmSubImage.c
	cc -c pgmSubImage.c

pgmInsert.o : pgmInsert.c
	cc -c pgmInsert.c

pgmEmpty.o : pgmEmpty.c
	cc -c pgmEmpty.c

pgmEcho.o : pgmEcho.c pgmHeaders.h pgmRead.h pgmWrite.h pgmBinWrite.h pgmReadBinary.h
	cc -c pgmEcho.c
pgmComp.o : pgmComp.c pgmHeaders.h pgmRead.h pgmWrite.h pgmBinWrite.h pgmReadBinary.h
	cc -c pgmComp.c

pgmReduce.o : pgmReduce.c pgmReduceSize.h pgmHeaders.h pgmRead.h pgmWrite.h pgmBinWrite.h pgmReadBinary.h 
	cc -c pgmReduce.c

pgmTile.o : pgmTile.c pgmSubImage.h pgmHeaders.h pgmRead.h pgmWrite.h pgmBinWrite.h pgmReadBinary.h
	cc -c pgmTile.c

pgmAssemble.o : pgmAssemble.c pgmInsert.h pgmEmpty.h pgmHeaders.h pgmRead.h pgmWrite.h pgmBinWrite.h pgmReadBinary.h
	cc -c pgmAssemble.c
