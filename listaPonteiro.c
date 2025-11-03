#include<stdio.h>
#include<stdlib.h>

typedef double TInfo;

typedef struct TNo{
   TInfo info;
   struct TNo *pProx;
} TNo;

typedef struct {
  TNo *pInicio;  
} TLista;

void inicializar(TLista *l) {
  (*l).pInicio = NULL;
}

void finalizar(TLista *l) {
   TNo *aux;
   while ((*l).pInicio != NULL ) {
      aux = (*l).pInicio;
      (*l).pInicio = aux->pProx;
      free(aux);
   }
}

int vazia(TLista l) {
   return l.pInicio == NULL; 
}

int cheia() {
  TNo *aux;
  aux = (TNo*)malloc(sizeof(TNo));
  if (aux == NULL) {
    return 1;
  } else {
     free(aux);
     return 0;
  }
}

int obterQtd(TLista l) {
   int qtd;
   TNo *aux;
   qtd = 0;
   aux = l.pInicio;
   while (aux != NULL) {
      qtd++;
      aux = aux->pProx;
   }
   return qtd;   
}

TInfo obterElemento(TLista l, int pos) {
   TNo *aux;
   aux = l.pInicio;
   while (pos > 0 && aux != NULL) {
      aux = aux->pProx; 
      pos--;
   }
   
   if (pos > 0 || aux == NULL) {
      printf("indice fora da faixa");   
      exit(1);
   }

   return aux->info;
}

TInfo atribuirElemento(TLista *l, int pos, TInfo info) {
   TNo *aux;
   aux = (*l).pInicio;
   while (pos >0 && aux != NULL) {
      aux = aux->pProx; 
      pos--;
   }
   if (pos > 0 || aux == NULL) {
      printf("indice fora da faixa");
      exit(1);
   }
   return aux->info = info;
}

TInfo inserirNoInicio(TLista *l, TInfo info) {
  TNo* novo;
  if (cheia(*l)) {
      printf("nao pode inserir na lista cheia!");   
      exit(1);
  }
  novo = (TNo*) malloc(sizeof(TNo));
  novo->info = info;
  novo->pProx = (*l).pInicio;  
  (*l).pInicio = novo;
  return info;
}

TInfo inserirNoFim(TLista *l, TInfo info) {
  TNo *novo, *aux, *ant;
  if (cheia(*l)) {
      printf("nao pode inserir na lista cheia!");   
      exit(1);
  }
  novo = (TNo*) malloc(sizeof(TNo));
  novo->info = info;
  novo->pProx = NULL;  
  aux = (*l).pInicio;
  ant = NULL;
  while (aux!=NULL) {
    ant = aux;
    aux = aux->pProx;
  }

  if (ant==NULL) {
     (*l).pInicio = novo;
  } else {
     ant->pProx = novo;
  }
  
  return info;
}

TInfo inserirNaPosicao(TLista *l, int pos, TInfo info) {
  TNo *novo, *aux, *ant;
  if (cheia(*l)) {
      printf("nao pode inserir na lista cheia!");   
      exit(1);
  }
 
  aux = (*l).pInicio;
  ant = NULL;
  while (aux!=NULL && pos>0) {
    ant = aux;
    aux = aux->pProx;
    pos--;
  }

  if (pos!=0) {
      printf("indice fora da faixa");
      exit(1);
  }
  novo = (TNo*) malloc(sizeof(TNo));
  novo->info = info;
  novo->pProx = aux;  
  if (ant == NULL) {
    (*l).pInicio = novo;
  } else {
    ant->pProx = novo;
  }
  return info;     
}

TInfo inserirOrdenado(TLista *l, TInfo info) {
  TNo *novo,*aux,*ant;
  if (cheia(*l)) {
      printf("nao pode inserir na lista cheia!");   
      exit(1);
  }
  aux = (*l).pInicio;
  ant = NULL;
  while (aux!=NULL &&  aux->info < info) {
    ant = aux;
    aux = aux->pProx;
  }
  novo = (TNo*) malloc(sizeof(TNo));
  novo->info = info;
  novo->pProx = aux;  
  if (ant == NULL) {
    (*l).pInicio = novo;
  } else {
    ant->pProx = novo;
  }
  return info;  
}

TInfo removerDoInicio(TLista *l) {
  TNo *vitima;
  TInfo info;
  if (vazia(*l)) {
      printf("nao pode remover na lista vazia!");   
      exit(1);
  }
  vitima = (*l).pInicio;
  (*l).pInicio = (*l).pInicio->pProx;
  info = vitima->info;
  free(vitima);
  return info;  
}

TInfo removerDoFim(TLista *l) {
  TNo *vitima, *aux,*ant;
  TInfo info;
  if (vazia(*l)) {
      printf("nao pode remover na lista vazia!");   
      exit(1);
  }

  aux = (*l).pInicio;
  ant = NULL;
  while (aux->pProx!=NULL) {
    ant = aux;
    aux = aux->pProx;
  }

  vitima = aux;  
  if (ant==NULL) {
    (*l).pInicio = NULL;
  } else {
    ant->pProx = NULL;
  }

  info = vitima->info;
  free(vitima);
  return info;  
}

TInfo removerElemento(TLista *l, TInfo info) {
  TNo *vitima, *aux,*ant;
  if (vazia(*l)) {
      printf("nao pode remover na lista vazia!");   
      exit(1);
  }

  aux = (*l).pInicio;
  ant = NULL;
  while (aux!=NULL && aux->info!=info) {
    ant = aux;
    aux = aux->pProx;
  }
  if (aux==NULL) {
      printf("nao pode remover da lista, um elemento que nao existe!");   
      exit(1);
  }  

  vitima = aux;  
  if (ant==NULL) {
    (*l).pInicio = vitima->pProx;
  } else {
    ant->pProx = vitima->pProx;
  }

  info = vitima->info;
  free(vitima);
  return info;  
}

TInfo removerDaPosicao(TLista *l, int pos) {
  TNo *vitima, *aux, *ant;
  TInfo info;   
  if (vazia(*l)) {
      printf("nao pode remover na lista vazia!");   
      exit(1);
  }

  aux = (*l).pInicio;
  ant = NULL;
  while (aux!=NULL && pos > 0) {
    ant = aux;
    aux = aux->pProx;
    pos--;
  }
  if (pos > 0 || aux == NULL) {
      printf("indice fora da faixa, no remover");   
      exit(1);
  }  

  vitima = aux;
  if (ant==NULL) {
    (*l).pInicio = vitima->pProx;
  } else { 
    ant->pProx = vitima->pProx;
  }

  info = vitima->info;
  free(vitima);
  return info;  
}

int main() {

  return 0;
}
