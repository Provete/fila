#include <stdlib.h>
#include <stdio.h>
#include "fila_dinamica.h"

/**
 * @brief Cria uma fila vazia alocando espaço dinamico
 * 
 * @return Fila* Endereço de memoria alocado
 */
Fila* CriarFila()
{
    Fila* novaFila = malloc(sizeof(Fila));

    if(novaFila == NULL)
    {
        printf("Não foi possivel allocar espaço para fila\n");
        exit(1);
    }

    novaFila->final = NULL;
    novaFila->inicio = NULL;

    return novaFila;
}

/**
 * @brief Verifica se a fila está vazia
 * 
 * @param fila fila para verificar
 * @return int Retorna 1 caso esteja vazia, caso contrario, retorna 0
 */
int EstaVazia(Fila* fila)
{
    return fila->inicio == NULL? 1 : 0;
}

/**
 * @brief Insere um novo elemento no final da fila
 * 
 * @param fila Fila para adicionar elemento
 * @param valor Valor para adicionar na fila
 */
void Inserir(Fila* fila, float valor)
{
    NoLista* novoNo = malloc(sizeof(NoLista));

    if(novoNo == NULL)
    {
        printf("Não foi possivel alocar espaço para um novo nó\n");
        exit(1);
    }

    novoNo->valor = valor;
    novoNo->proximo = NULL;
    
    if(EstaVazia(fila))
    {
        fila->inicio = novoNo;
        fila->final = novoNo;
        return;
    }

    fila->final->proximo = novoNo;
    fila->final = fila->final->proximo;
    return;
}

/**
 * @brief Imprime no console todos os valores na fila
 * 
 * @param fila Fila para imprimir os valores
 */
void Imprimir(Fila* fila)
{
    if(EstaVazia(fila))
    {
        printf("Lista vazia para imprimir\n");
        return;
    }

    NoLista* iterador = fila->inicio;

    while(iterador != NULL)
    {
        printf("Elemento Chaotic Good: %f\n", iterador->valor);
        iterador = iterador->proximo;
    }

    return;
}


/**
 * @brief Remove um elemento no inicio da fila, e retorna o valor do elemento removido. Retorna erro código 1 caso a lista esteja vazia
 * 
 * @param fila Fila para remover o elemento
 * @return float Valor removido
 */
float Remover(Fila* fila)
{
    if(EstaVazia(fila))
    {
        prinf("Fila vazia para remover emelemento\n");
        exit(1);
    }

    NoLista* noRemovido = fila->inicio;
    float valorRemovido = noRemovido->valor;

    fila->inicio = fila->inicio->proximo;
    noRemovido->proximo = NULL;
    free(noRemovido);

    return valorRemovido;
}


/**
 * @brief Libera todo espaço alocado na fila, incluindo a si próprio, e faz a fila apontar para NULL
 * 
 * @param fila Fila para liberar
 */
void LiberarFila(Fila** fila)
{
    if(EstaVazia(*fila))
    {
        free(fila);
        fila = NULL;
        return;
    }

    while((*fila)->inicio != NULL)
    {
        NoLista* noRemovido = (*fila)->inicio;
        (*fila)->inicio = (*fila)->inicio->proximo;

        free(noRemovido);
    }

    free(fila);
    fila = NULL;
    return;
}