 /*Leia um vetor de 16 posições e troque os 8 primeiros valores
 pelos 8 últimos e vice-e-versa. Escreva ao final o vetor obtido.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirVetor(int *vetor, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int tam, i, temp;
    // Lê o tamanho do vetor
    do {
        printf("Digite o tamanho do vetor (par): ");
        scanf("%d", &tam);
    } while ((tam%2) != 0);
        int vetor[tam];
        // Preenche o vetor com números aleatórios
        for(i = 0; i < tam; i++) {
            vetor[i] = rand() % 100;
        }
        printf("\nVetor original:\n");
        imprimirVetor(vetor, tam);
        // Troca os primeiros valores pelos últimos e vice-versa
        for(i = 0; i < tam/2; i++) {
            temp = vetor[i];
            vetor[i] = vetor[i + tam/2];
            vetor[i + tam/2] = temp;
        }
        printf("Vetor apos a troca:\n");
        imprimirVetor(vetor, tam);
    return 0;
}