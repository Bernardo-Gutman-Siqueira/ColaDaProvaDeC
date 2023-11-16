#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Linha de baixo gera seed para colunas.
int main() {
    srand(time(NULL));
    int i, j, n;
    printf("\nQual a dimensao da matriz? ");
    scanf("%d", &n);
    int mat[n][n];

    // Gera a última linha com números aleatórios entre 0 e 99
    for (j = 0; j < n; j++) {
        mat[n-1][j] = rand() % 100;
    }

    // Define a semente fora do loop
    for (j = 0; j < n; j++) {
        srand(mat[n-1][j]);
        for (i = 0; i < n-1; i++) {
            mat[i][j] = rand() % (mat[n-1][j] + 1);
        }
    }

    printf("\nMATRIZ\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}

