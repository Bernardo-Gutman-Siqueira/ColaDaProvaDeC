#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    srand(time(NULL));
    limparTela();
    int n, i, j, k;
    printf("Digite o tamanho das matrizes.\n:");
    scanf("%d", &n);
    int matriz1[n][n], matriz2[n][n], resultado[n][n];
    // Gera duas matrizes de números aleatórios
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            matriz1[i][j] = 1 + rand() % 10;
            matriz2[i][j] = 1 + rand() % 10;
            resultado[i][j] = 0;
        }
    }
    limparTela();
    printf("A matriz:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\nMultiplicada pela matriz:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\nEh igual a.\n\n");
    // Multiplica as duas matrizes
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            for ( k = 0; k < n; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    // Imprime a matriz resultante
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
    return 0;
}
