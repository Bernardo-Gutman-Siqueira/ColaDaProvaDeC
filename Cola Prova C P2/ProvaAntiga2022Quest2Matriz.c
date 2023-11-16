#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Faça um programa em C que gere e apresente a matriz (n x m)
com a seguinte configuração:
O primeiro número da matriz é aleatório entre 1 e 30.
Os demais números serão gerados da soma ou subtração de outro número 
aleatório com o anteriormente gerado. A soma ou subtração também deverão 
ser aleatórias.*/
int main() {
    int n, m, i, j;
    int matriz[100][100];
    srand(time(NULL));
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);
    matriz[0][0] = rand() % 30 + 1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(i == 0 && j == 0) continue;
            int operacao = rand() % 2;
            int num = rand() % 30 + 1;
            if(operacao == 0) {
                matriz[i][j] = matriz[i][j-1] + num;
            } else {
                matriz[i][j] = matriz[i][j-1] - num;
            }
        }
    }

    printf("Matriz gerada: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
