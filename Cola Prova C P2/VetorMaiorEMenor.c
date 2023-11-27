 /*Crie um programa em C que peça 10 números float,
 armazene eles em um vetor e diga qual elemento é o maior,
 o menor e seu valor.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

 int main() {
    srand(time(NULL));
    int i;
    float vet[MAX], menorF = 0.0, maiorF = 10.0, nMaior = 0.0, nMenor = 11.0;
    for(i = 0; i < MAX; i++) {
        vet[i] =  ((float)rand()/(float)(RAND_MAX)) * (maiorF - menorF) + menorF;
    }
    for(i = 0; i < MAX; i++) {
        printf("%f\n", vet[i]);
    }
    for(i = 0; i < MAX; i++) {
        if (vet[i] > nMaior) {
            nMaior = vet[i];
        }
    }
    for (i = 0; i < MAX; i++) {
        if (vet[i] < nMenor){
            nMenor = vet[i];
        }
    }
    printf("\nO maior numero eh %f", nMaior);
    printf("\nO menor numero eh %f", nMenor);
    return 0;
 }