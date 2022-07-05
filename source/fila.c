#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* CriarFila()
{
    Fila* fila = (Fila*) malloc( sizeof(Fila) );
    
    if(fila == NULL)
    {
        printf("num deu\n");
        exit(1);
    }
    
    fila->ocupacao = 0;
    fila->inicio = 0;
    return fila;
}

int EstaVazia(Fila* fila)
{
    return fila->ocupacao == 0;
}

int EstaCheia(Fila* fila)
{
    return fila->ocupacao == TAMANHO;
}

int PegarFinal(Fila* fila)
{
    int final = (fila->inicio + fila->ocupacao) % TAMANHO;
    return final;
}

int Incrementar(int *i)
{
    *i = (*i+1) % TAMANHO;
}

void Inserir(Fila* fila, int valor)
{
    if(EstaCheia(fila))
    {
        printf("Fila cheia\n");
        return;
    }

    int final = PegarFinal(fila);
    
    fila->info[final] = valor;
    fila->ocupacao++;
    
    return;
}

void Imprimir(Fila* fila)
{
    if(EstaVazia(fila))
    {
        printf("Fila Vazia");
        return;
    }

    for(int i=fila->inicio; i < PegarFinal(fila); Incrementar(&i))
    {
        printf("Elemento Neutro: %d\n", fila->info[i]);
    }
}

int Remover(Fila* fila)
{
    if(EstaVazia(fila))
    {
        printf("Uh oh, tentativa de remover fila vazia\n");
        exit(1);
    }


    float valorRemovido = fila->info[ fila->inicio ];
    fila->ocupacao--;
    Incrementar(&fila->inicio);

    return valorRemovido;
}

void Liberar(Fila** fila)
{
    free(*fila);
    *fila = NULL;
}