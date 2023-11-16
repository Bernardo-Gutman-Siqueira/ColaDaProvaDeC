#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
/*Faça um algoritmo que gere um vetor de n posições,
onde todas as posições pares do vetor (0, 2, 4, 6, ...) possuem números 
aleatórios e todas as posições ímpares do vetor serão a média das duas
posições ímpares, ou seja, anterior e posterior.*/
int main() {
    int n, i;
    int vetor[MAX];
    srand(time(NULL));
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        if(i % 2 == 0) {
            vetor[i] = rand() % MAX;
        }
    }
    for(i = 1; i < n-1; i+=2) {
        vetor[i] = (vetor[i-1] + vetor[i+1]) / 2;
    }
    printf("Vetor gerado: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}