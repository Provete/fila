default: main.o fila.o
	gcc main.o fila.o -o release/final.o

main.o: source/main.c
	gcc -c source/main.c -o main.o

fila.o: source/fila.c
	gcc -c source/fila.c -o fila.o

.PHONY: execute
execute: release/final.o
	./release/final.o