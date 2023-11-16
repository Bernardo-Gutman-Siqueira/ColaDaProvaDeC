#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    int matriz[n][n];
    srand(time(0));
    // Preenche a primeira e a última coluna com números aleatórios
    for(i = 0; i < n; i++) {
        matriz[i][0] = rand() % 100; // Primeira coluna
        matriz[i][n-1] = rand() % 100; // Última coluna
    }
    // Preenche cada linha com números aleatórios entre os elementos da primeira e última coluna
    for(i = 0; i < n; i++) {
        int min = matriz[i][0]; // Elemento da primeira coluna
        int max = matriz[i][n-1]; // Elemento da última coluna
        if(min > max) {
            int temp = min;
            min = max;
            max = temp;
        }
        for(j = 1; j < n-1; j++) { // Ignora a primeira e a última coluna
            matriz[i][j] = min + rand() % (max - min + 1);
        }
    }
    // Imprime a matriz
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
