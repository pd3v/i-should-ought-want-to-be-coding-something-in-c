OBJ = rnd.o

all: $(OBJ)
	clang -Wall -o main main.c -L. -lrnd.o -std=c11

rnd.o: rnd.c rnd.h
	clang -c -o rnd.o rnd.c

run:
	./main

clean:
	rm -f *.o
