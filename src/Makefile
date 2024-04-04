OBJ = gen.o

all: $(OBJ)
	$(info --- building main)
	clang -Wall -o main main.c -L. -lpthread $(OBJ) -std=c11

gen.o: gen.c gen.h
	$(info --- compiling gen)
	clang -c -o $(OBJ) gen.c	

run:
	./main

clear:
	rm -f *.o main
