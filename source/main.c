#include <stdio.h>
#include "fila.h"

int main()
{
    Fila* fila = CriarFila();
    Inserir(fila, 5);
    Inserir(fila, 7);
    Inserir(fila, 10);
    Inserir(fila, 47);

    Imprimir(fila);
    Remover(fila);
    Remover(fila);

    printf("\n___________\n\n");

    Imprimir(fila);
    Liberar(&fila);

    return 0;
}