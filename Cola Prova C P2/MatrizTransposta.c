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
    int n, i, j;
    printf("Digite o tamanho da matriz.\n:");
    scanf("%d", &n);
    int matriz[n][n];
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            matriz[i][j] = 1 + rand() % 100;
        }
    }
    limparTela();
    printf("Sua matriz eh:\n\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nSua transposta eh:\n\n");
    for ( j = 0; j < n; j++) {
        for ( i = 0; i < n; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}