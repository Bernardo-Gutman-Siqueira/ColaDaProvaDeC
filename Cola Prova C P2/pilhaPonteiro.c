#include <stdio.h>
#include <stdlib.h>

typedef double Tinfo;

typedef struct Tno {
    Tinfo info;
    struct Tno *pProx;
} Tno;

typedef struct {
    Tno *pTopo;
} TPilha;

void inicializar(TPilha *p) {
    p->pTopo = NULL;
}

void finalizar(TPilha *p) {
    Tno *aux;
    while (p->pTopo != NULL) {
        aux = p->pTopo;
        p->pTopo = aux->pProx;
        free(aux);
    }
}

int vazia(TPilha p) {
    return (p.pTopo == NULL);
}

int cheia() {
    Tno *aux = (Tno*) malloc(sizeof(Tno));
    if (aux == NULL)
        return 1;
    else {
        free(aux);
        return 0;    
    }
}

Tinfo topo(TPilha p) {
    if (vazia(p)) {
        printf("Erro: pilha vazia!\n");
        exit(-3);
    }
    return p.pTopo->info;
}

void inserir(TPilha *p, Tinfo info) {
    Tno *aux;
    if (cheia(*p)) {
        printf("Erro: memoria insuficiente!\n");
        exit(-1);
    } else {
        aux = (Tno*) malloc(sizeof(Tno));
        aux->info = info;
        aux->pProx = p->pTopo;
        p->pTopo = aux;
    }   
}

Tinfo remover(TPilha *p) {
    Tinfo info;
    Tno *aux;
    if (vazia(*p)) {
        printf("Erro: pilha vazia!\n");
        exit(-2);
    } else {
        info = p->pTopo->info;
        aux = p->pTopo;
        p->pTopo = p->pTopo->pProx;
        free(aux);
        return info;	
    }
}

int main() {
    TPilha pilha;
    inicializar(&pilha);
    inserir(&pilha, 1.1);
    inserir(&pilha, 2.2);
    inserir(&pilha, 3.3);
    printf("Topo da pilha: %.1f\n", topo(pilha));
    remover(&pilha);
    printf("Novo topo da pilha: %.1f\n", topo(pilha));
    finalizar(&pilha);
    return 0;
}
