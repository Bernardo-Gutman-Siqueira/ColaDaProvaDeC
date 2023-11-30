#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool EhPrimo(int num) {
    if (num <= 1) return false;
    if (num % 2 == 0 && num > 2) return false;
    for(int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int GeraPrimo() {
    int num;
    do {
        num = 100 + rand() % 100 + 1;
    } while(!EhPrimo(num));
    return num;
}

int main() {
    srand(time(NULL));
    int n, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float *vetor = malloc(n * sizeof(int));
    if(n%2 == 0) {
        int meioEs = ((n/2)-1);
        int meioDi = (n/2);
        vetor[meioEs] = GeraPrimo();
        vetor[meioDi] = GeraPrimo();
        for(i = (n/2); i < n; i++) {
            float divisorPar = ((float)rand()/(float)(RAND_MAX)) * (5.0 - 0.5) + 0.5;
            vetor[i+1] = vetor[i]/divisorPar;
        }
        for(i = (n/2); i > 0; i--) {
            float divisorPar2 = ((float)rand()/(float)(RAND_MAX)) * (5.0 - 0.5) + 0.5;
            vetor[i-1] = vetor[i]/divisorPar2;
        }
    } else {
        int meio = n/2;
        vetor[meio] = GeraPrimo();
        for(i = (n/2); i < n; i++) {
            float divisor = ((float)rand()/(float)(RAND_MAX)) * (5.0 - 0.5) + 0.5;
            vetor[i+1] = vetor[i]/divisor;
        }
        for(i = (n/2); i > 0; i--) {
            float divisor2 = ((float)rand()/(float)(RAND_MAX)) * (5.0 - 0.5) + 0.5;
            vetor[i-1] = vetor[i]/divisor2;
        }
    }
    printf("Vetor resultante: \n");
    for(i = 0; i < n; i++) {
        printf("Vetor %d:%f\n", i, vetor[i]);
    }
    free(vetor);
    return 0;
}