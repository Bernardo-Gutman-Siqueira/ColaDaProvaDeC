#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    int **matriz;

    /* Solicita ao usuário o tamanho da matriz */
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    /* Aloca memória para a matriz */
    matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    /* Preenche a primeira e última linha de cada coluna com números aleatórios */
    srand(time(NULL));
    for (j = 0; j < n; j++) {
        matriz[0][j] = rand() % 100;  /* Gera um número aleatório entre 0 e 99 */
        matriz[n - 1][j] = rand() % 100;  /* Gera um número aleatório entre 0 e 99 */
    }

    /* Preenche as linhas intermediárias de cada coluna com números aleatórios entre o primeiro e o último número da coluna */
    for (j = 0; j < n; j++) {
        int min = matriz[0][j] < matriz[n - 1][j] ? matriz[0][j] : matriz[n - 1][j];
        int max = matriz[0][j] > matriz[n - 1][j] ? matriz[0][j] : matriz[n - 1][j];
        for (i = 1; i < n - 1; i++) {
            matriz[i][j] = min + rand() % (max - min + 1);  /* Gera um número aleatório entre min e max */
        }
    }

    /* Imprime a matriz */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    /* Libera a memória alocada para a matriz */
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
