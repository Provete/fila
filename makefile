default: main.o fila_dinamica.o
	gcc main.o fila_dinamica.o -o release/final.o

main.o: source/main.c
	gcc -c source/main.c -o main.o

fila.o: source/fila.c
	gcc -c source/fila.c -o fila.o

fila_dinamica.o: source/fila_dinamica.c
	gcc -c source/fila_dinamica.c -o fila_dinamica.o

.PHONY: execute
execute: release/final.o
	./release/final.o