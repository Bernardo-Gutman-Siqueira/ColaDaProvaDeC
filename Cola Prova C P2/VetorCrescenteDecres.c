#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void ordenar(float array[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    float vetor[MAX], menorF = 0.0, maiorF = 10.0;
    for(i = 0; i < MAX; i++) {
        vetor[i] =  ((float)rand()/(float)(RAND_MAX)) * (maiorF - menorF) + menorF;
    }
    printf("Vetor original:\n");
    for(i = 0; i < MAX; i++) {
        printf("%f\n", vetor[i]);
    }
    ordenar(vetor, MAX);
    printf("\nVetor ordenado de forma crescente:\n");
    for(i = 0; i < MAX; i++) {
        printf("%f\n", vetor[i]);
    }
    printf("\nVetor ordenado de forma decrescente:\n");
    for(i = MAX-1; i >= 0; i--) {
        printf("%f\n", vetor[i]);
    }
    return 0;
}