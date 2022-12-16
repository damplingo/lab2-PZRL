.PHONY: all clean run

Makefile = main.o funcs.o

all: main
run:
	./main
clean:
	rm *.o main
main: $(Makefile)
	gcc $(Makefile) -o main
main.o: main.c
	gcc -c main.c -o main.o
funcs.o: funcs.c
	gcc -c funcs.c -o funcs.o
