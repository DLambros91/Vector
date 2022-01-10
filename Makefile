CC=g++

CFLAGS=-g -Wall -Wpedantic -Werror

all: main

main: main.o
	${CC} ${CFLAGS} -o main main.o

main.o: main.cc vector.h
	${CC} ${CFLAGS} -c main.cc

clean:
	${RM} *.o main