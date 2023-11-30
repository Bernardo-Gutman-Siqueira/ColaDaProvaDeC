#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);
    int matriz[n][n];
    srand(time(NULL));

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i + j == n - 1) {
                matriz[i][j] = rand() % 100 + 1; // Gera números aleatórios para a diagonal secundária
            } else if(i + j < n - 1) {
                matriz[i][j] = 0; // Preenche o triângulo superior com zeros
            } else {
                matriz[i][j] = rand() % (matriz[i][n - 1 - i] + 1); // Gera números aleatórios para o triângulo inferior que são menores ou iguais ao número na diagonal secundária
            }
        }
    }

    printf("Matriz gerada: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}