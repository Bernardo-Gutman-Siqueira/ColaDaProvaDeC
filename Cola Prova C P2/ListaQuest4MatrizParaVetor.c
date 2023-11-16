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
    int n = rand() % 10 + 1;//Linhas.
    int m = rand() % 10 + 1;//Colunas.
    int i, j, k = 0;
    int matriz[n][m];
    int tamanhoVetor = n*m;
    int vetor[tamanhoVetor];
    //Preenche a matriz e imprime.
    printf("Matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            matriz[i][j] = rand() % 100;
            printf("%d ", matriz[i][j]);
            vetor[k] = matriz[i][j];//Coloca o número no vetor.
            k++;
        }
        printf("\n");
    }
    //Imprime o vetor.
    printf("\nVetor:\n");
    for(i = 0; i < tamanhoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}