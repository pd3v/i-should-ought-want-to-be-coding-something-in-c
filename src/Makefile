OBJ = gen.o rnd.o 

all: $(OBJ)
	$(info --- building main)
	clang -Wall -o main main.c -L. -lpthread gen.o rnd.o -std=c11

gen.o: gen.c gen.h
	$(info --- compiling gen)
	clang -c -o gen.o gen.c	

# rnd.o: rnd.c rnd.h
# 	clang -c -o rnd.o rnd.c

run:
	./main

clear:
	rm -f *.o
