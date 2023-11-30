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
        num = rand() % 100 + 1;
    } while(!EhPrimo(num));
    return num;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = malloc(n * sizeof(int));//A função malloc aloca um bloco de memória do tamanho especificado.
    for(int i = 0; i < n; i++) {//n * sizeof(int) dá o tamanho total do vetor em bytes.
        if(i % 2 == 0) {
            vetor[i] = GeraPrimo();
        }
    }
    for(int i = 1; i < n; i += 2) {
        vetor[i] = (vetor[i-1] + (i+1 < n ? vetor[i+1] : 0)) / 2;
    }
    printf("Vetor resultante: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);//libera a memória.
    return 0;
}