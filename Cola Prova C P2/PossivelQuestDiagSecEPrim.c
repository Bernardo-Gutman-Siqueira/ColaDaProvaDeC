#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Os números são gerados de acordo com os numeros da matriz secundaria e primaria
na mesma linha.*/
int main() {
    int n, i, j;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    int matriz[n][n];
    srand(time(0));
    // Preenche a diagonal principal e secundária com números aleatórios
    for(i = 0; i < n; i++) {
        matriz[i][i] = rand() % 100; // Diagonal principal
        matriz[i][n-i-1] = rand() % 100; // Diagonal secundária
    }
    // Preenche cada linha com números aleatórios entre os elementos da diagonal
    for(i = 0; i < n; i++) {
        int min = matriz[i][i]; // Elemento da diagonal principal
        int max = matriz[i][n-i-1]; // Elemento da diagonal secundária

        if(min > max) {
            int temp = min;
            min = max;
            max = temp;
        }
        for(j = 0; j < n; j++) {
            if(j != i && j != n-i-1) { // Ignora os elementos da diagonal
                matriz[i][j] = min + rand() % (max - min + 1);
            }
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