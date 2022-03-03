CC= gcc
DIR= ../src
CFLAGS = -std=c99 -g 


objects =  tests.o pgmHeaders.o

src = $(objects:.o=.c)

edit : $(objects)

clean:
	rm -f $(objects)

tests : tests.c pgmHeaders.o 

pgmHeaders.o : pgmHeaders.c pgmHeaders.h
	cc -c pgmHeaders.c 
