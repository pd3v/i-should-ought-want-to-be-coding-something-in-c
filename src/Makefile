rnd.o: rnd.c rnd.h
	clang -c -o rnd.o rnd.c

all:
	clang -Wall -o main main.c -L. -lrnd.o -std=c11

run:
	./main

clean:
	rm -f *.o
