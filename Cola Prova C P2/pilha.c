#include <stdio.h>

#define MAX 100

/*
vazia   : retorna verdadeiro se a pilha estivar vazia
cheia   : retorna verdadeiro se a pilha esta cheia, ou seja, nao podemos inserir mais nenhum elemento.
inserir : insere um elemento no final da pilha
remover : remove o elemento que esta no final da pilha
tamanho : retorna o numero de elementos na pilha
print   : imprime os elementos da pilha
*/

typedef struct {
    int vetor[MAX], fim, tamanho;
} Pilha;

void iniciar(Pilha *p) {
    (*p).fim = -1;
    (*p).tamanho = 0;
}

int taCheia(Pilha *p) {
    if ((*p).tamanho == MAX){
        printf("Pilha cheia\n");
        return 1;
    } else {
        return 0;
    }
    
}

int taVazia(Pilha *p) {
    if ((*p).tamanho == 0) {
        printf("Pilha vazia\n");
        return 1;
    } else {
        return 0;
    }
}

void inserir(Pilha *p, int valor) {
    if (taCheia(p)) {
        printf("Pilha cheia\n");
    } else {
        (*p).fim++;
        (*p).vetor[(*p).fim] = valor;
        (*p).tamanho++;
    }  
}

void remover(Pilha *p) {
    if (taVazia(p)) {
        printf("Pilha vazia\n");
    } else {
        (*p).fim--;
        (*p).tamanho--;
    }
    
}

int main() {
    Pilha p;
    iniciar(&p);
    inserir(&p, 10);
    inserir(&p, 20);
    inserir(&p, 30);
    inserir(&p, 40);
    inserir(&p, 50);
    remover(&p);
    inserir(&p, 66);
    for (int i = (p).tamanho ; i > 0 ; i--) {
        printf("%d\n", (p).vetor[i-1]);
    }
    return 0;
}
