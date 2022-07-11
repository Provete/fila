#ifndef fila_dinamica_h
#define fila_dinamica_h

typedef struct noLista
{
    float valor;
    struct noLista* proximo;
} NoLista;

typedef struct fila
{
    NoLista* inicio;
    NoLista* final;
} Fila;

Fila* CriarFila();
int EstaVazia(Fila* fila);
void Inserir(Fila* fila, float valor);
void Imprimir(Fila* fila);
float Remover(Fila* fila);
void LiberarFila(Fila** fila);

#endif