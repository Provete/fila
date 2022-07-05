#ifndef filaestatica
#define filaestatica

#define TAMANHO 10

typedef struct fila
{
    int info[TAMANHO];
    int ocupacao;
    int inicio;
} Fila;

Fila* CriarFila();
int EstaVazia(Fila* fila);
int EstaCheia(Fila* fila);
void Inserir(Fila* fila, int valor);
int Remover(Fila* fila);
void Imprimir(Fila* fila);
void Liberar(Fila** fila);

#endif