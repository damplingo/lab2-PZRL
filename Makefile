.PHONY: all clean run

Makefile = main.o funcs.o funcs2.o funcs8.o

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
funcs2.o: funcs2.c
	gcc -c funcs2.c -o funcs2.o
funcs8.o: funcs8.c
	gcc -c funcs8.c -o funcs8.o
