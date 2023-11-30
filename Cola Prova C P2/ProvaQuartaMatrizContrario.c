#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int n;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);
    int matriz[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= n/2) {
                if(j >= i - n/2 && j <= n/2 + n - i - 1) {
                    matriz[i][j] = rand() % 21 + 30;
                } else {
                    matriz[i][j] = 0;
                }
            } else {
                matriz[i][j] = 0;
            }
        }
    }
    printf("Matriz resultante:\n");
    for(int i = n/2; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
