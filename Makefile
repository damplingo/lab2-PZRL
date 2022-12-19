.PHONY: all clean run

comand= main.o funcs.o funcs2.o funcs8.o funcs16.o

all: main
run: main
	./main
clean:
	rm *.o main
main: $(comand)
	gcc $(comand) -o main
main.o: main.c
	gcc -c main.c -o main.o
funcs.o: funcs.c
	gcc -c funcs.c -o funcs.o
funcs2.o: funcs2.c
	gcc -c funcs2.c -o funcs2.o
funcs8.o: funcs8.c
	gcc -c funcs8.c -o funcs8.o
funcs16.o: funcs16.c
	gcc -c funcs16.c -o funcs16.o
