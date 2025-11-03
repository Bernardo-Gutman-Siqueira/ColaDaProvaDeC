#include <stdio.h>
#include <stdlib.h>

typedef double Tinfo;

typedef struct TNo {
    Tinfo info;
    struct TNo *pProx;
} TNo;

typedef struct {
    TNo *pInicio;
    TNo *pFim;  
} TFila;

void inicializar(TFila *f) {
    (*f).pInicio = NULL;
    (*f).pFim = NULL;
}

void finalizar(TFila *f) {
    while ( (*f).pInicio != NULL ) {
        TNo *aux = (*f).pInicio;
        (*f).pInicio = aux->pProx;
        free(aux);
   }   
    (*f).pFim = NULL;
}

int vazia(TFila f) {
    return f.pInicio == NULL;  
}

int cheia() {
    TNo *aux = (TNo*)malloc(sizeof(TNo));
    if (aux == NULL) {
        free(aux);
        return 1;
    } else {
        free(aux);
        return 0;
    }
}

Tinfo primeiro(TFila f) {
    if (vazia(f)) {
        printf("Fila vazia nao tem primeiro\n");
        exit(-1);
    }
    return f.pInicio->info;
}

Tinfo ultimo(TFila f) {
    if (vazia(f)) {
        printf("Fila vazia nao tem ultimo\n");
        exit(-1);
    }
    return f.pFim->info;
}

Tinfo inserir(TFila *f, Tinfo info) {
    TNo* novo;
    if (cheia(*f)) {
        printf("Fila cheia nao pode inserir\n");
        exit(-1);
    }
    novo = (TNo*) malloc(sizeof(TNo));
    novo->info = info;
    novo->pProx = NULL;
    if (vazia(*f)) {
        (*f).pInicio = novo;
    } else {
        (*f).pFim->pProx = novo; 
    }
    (*f).pFim = novo;
    return info;
}

Tinfo remover(TFila *f) {
    TNo *vitima;
    Tinfo info;
    if (vazia(*f)) {
        printf("Fila vazia nao pode remover\n");
        exit(-1);
    }
    vitima = (*f).pInicio;
    (*f).pInicio = (*f).pInicio->pProx;
    info = vitima->info;
    free(vitima);
    if ( (*f).pInicio == NULL ){
    (*f).pFim = NULL;
  }
    return info;
}

int main() {
    TFila fila;
    inicializar(&fila);
    inserir(&fila, 10);
    inserir(&fila, 20);
    inserir(&fila, 30);
    printf("Primeiro elemento: %.1f\n", primeiro(fila));
    printf("Ultimo elemento: %.1f\n", ultimo(fila));
    remover(&fila);
    printf("Primeiro elemento apos remocao: %.1f\n", primeiro(fila));
    printf("Ultimo elemento: %.1f\n", ultimo(fila));
    finalizar(&fila);
    return 0;
}
