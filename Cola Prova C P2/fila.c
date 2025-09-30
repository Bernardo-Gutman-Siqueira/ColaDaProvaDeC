#include <stdio.h>

#define MAX 100

/*
vazia   : retorna verdadeiro se a fila estivar vazia
cheia   : retorna verdadeiro se a fila esta cheia, ou seja, nao podemos inserir mais nenhum elemento.
print   : imprime os elementos da fila
inserir : insere um elemento no final da fila
remover : remove o elemento que esta no inicio da fila
tamanho : retorna o numero de elementos na fila
*/

typedef struct {
    int vetor[MAX], inicio, fim, tamanho;
} Fila;

void iniciar(Fila *f) {
    (*f).inicio = 0;
    (*f).fim = -1;
    (*f).tamanho = 0; 
}

int taCheia(Fila *f) {
    if ((*f).tamanho == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int taVazia(Fila *f) {
    if ((*f).tamanho == 0) {
        return 1;
    } else {
        return 0;
    }
}

void inserir(Fila *f, int valor) {
    if (taCheia(f)) {
        printf("Fila cheia\n");
    } else {
        (*f).fim = ((*f).fim + 1) % MAX;
        (*f).vetor[(*f).fim] = valor;
        (*f).tamanho++;
    }
}

void remover(Fila *f) {
    if (taVazia(f)) {
        printf("Fila vazia\n");
    } else {
        (*f).inicio = ((*f).inicio + 1) % MAX;
        (*f).tamanho--;
    }
}

int main() {
    Fila f;
    iniciar(&f);
    inserir(&f, 10);
    inserir(&f, 20);
    inserir(&f, 30);
    inserir(&f, 40);
    inserir(&f, 50);
    remover(&f);
    remover(&f);
    remover(&f);
    printf("Fila tem %d elementos\n", f.tamanho);
    for (int i = 0; i < f.tamanho; i++) {
        printf("%d ", f.vetor[(f.inicio + i) % MAX]);
    }
    return 0;
}
