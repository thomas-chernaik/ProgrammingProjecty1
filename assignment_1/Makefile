CC= gcc
DIR= ../src
CFLAGS = -std=c99 -g 


objects = pgmHeaders.o tests.o

src = $(objects:.o=.c)

edit : $(objects)

clean:
	rm -f $(objects)

tests.o : tests.c 
