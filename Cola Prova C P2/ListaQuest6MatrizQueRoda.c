#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limparTela() {//Clear multiplataforma.
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleepSegundos(int segundos)//Sleep multiplataforma.
{
    clock_t time_end;
    time_end = clock() + segundos * CLOCKS_PER_SEC;
    while (clock() < time_end){}
}

void imprimirMatriz(int N, int matriz[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void rotacionarMatriz(int N, int matriz[N][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[N - 1 - j][i];
            matriz[N - 1 - j][i] = matriz[N - 1 - i][N - 1 - j];
            matriz[N - 1 - i][N - 1 - j] = matriz[j][N - 1 - i];
            matriz[j][N - 1 - i] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int N = rand() % 10 + 1;
    int matriz[N][N];
    //Preenche a matriz.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
    //Imprime a matriz 100 vezes, rotacionando a cada vez.
    for(int i = 0; i < 100; i++) {
        limparTela();
        imprimirMatriz(N, matriz);
        rotacionarMatriz(N, matriz);
        sleepSegundos(1);
    }
    return 0;
}