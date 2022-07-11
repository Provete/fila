#include <stdio.h>
#include "fila_dinamica.h"

int main()
{
    Fila* fila = CriarFila();
    Inserir(fila, 5.4);
    Inserir(fila, -45.213);
    Inserir(fila, 5564.41222);
    Inserir(fila, 546335.411);
    Inserir(fila, -45645.2);

    Imprimir(fila);

    return 0;
}