#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    int tamanhoVetor = rand() % 15 + 1;
    int vetor[tamanhoVetor];
    int i, j, k, m, n;
    //Preenche o vetor e imprime.
    printf("Vetor de tamanho %d:\n", tamanhoVetor);
    for(i = 0; i < tamanhoVetor; i++) {
        vetor[i] = rand() % 99 + 1;
        printf("%d ", vetor[i]);
    }
    /*A função ceil() é uma função matemática que retorna o menor número inteiro 
    que é maior ou igual ao número fornecido.
    Ela é usada para arredondar um número para cima.
    Isso garante que a matriz terá espaço suficiente para todos os elementos do vetor.*/
    m = ceil(sqrt(tamanhoVetor));
    n = ceil((double)tamanhoVetor / m);
    int matriz[n][m];
    //Preenche a matriz com os números do vetor e imprime a matriz.
    printf("\n\nMatriz %dx%d:\n", n, m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            k = i * m + j;
            if(k < tamanhoVetor) {
                matriz[i][j] = vetor[k];
                printf("%d ", matriz[i][j]);
            } else {
                matriz[i][j] = 0;//Preenche vazio com 0.
                printf("%d ", matriz[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}