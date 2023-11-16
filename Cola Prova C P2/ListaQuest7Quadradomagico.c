#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO3 3
#define TAMANHO4 4

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void embaralha(int *array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void geraMatrizAleatoria3(int matriz[TAMANHO3][TAMANHO3]) {
    int numeros[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    embaralha(numeros, 9);
    for (int i = 0; i < TAMANHO3; i++) {
        for (int j = 0; j < TAMANHO3; j++) {
            matriz[i][j] = numeros[i * TAMANHO3 + j];
        }
    }
}

void geraMatrizAleatoria4(int matriz[TAMANHO4][TAMANHO4]) {
    int numeros[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    embaralha(numeros, 16);
    for (int i = 0; i < TAMANHO4; i++) {
        for (int j = 0; j < TAMANHO4; j++) {
            matriz[i][j] = numeros[i * TAMANHO4 + j];
        }
    }
}

int ehQuadradoMagico3(int matriz[TAMANHO3][TAMANHO3]) {
    int constanteMagica = 0;
    for (int i = 0; i < TAMANHO3; i++) {
        constanteMagica += matriz[0][i];
    }
    for (int i = 0; i < TAMANHO3; i++) {
        int somaLinha = 0;
        int somaColuna = 0;
        for (int j = 0; j < TAMANHO3; j++) {
            somaLinha += matriz[i][j];
            somaColuna += matriz[j][i];
        }
        if (somaLinha != constanteMagica || somaColuna != constanteMagica) {
            return 0;
        }
    }
    int somaDiagonal1 = 0;
    int somaDiagonal2 = 0;
    for (int i = 0; i < TAMANHO3; i++) {
        somaDiagonal1 += matriz[i][i];
        somaDiagonal2 += matriz[i][TAMANHO3 - i - 1];
    }
    if (somaDiagonal1 != constanteMagica || somaDiagonal2 != constanteMagica) {
        return 0;
    }
    return 1;
}

int ehQuadradoMagico4(int matriz[TAMANHO4][TAMANHO4]) {
    int constanteMagica = 0;
    for (int i = 0; i < TAMANHO4; i++) {
        constanteMagica += matriz[0][i];
    }
    for (int i = 0; i < TAMANHO4; i++) {
        int somaLinha = 0;
        int somaColuna = 0;
        for (int j = 0; j < TAMANHO4; j++) {
            somaLinha += matriz[i][j];
            somaColuna += matriz[j][i];
        }
        if (somaLinha != constanteMagica || somaColuna != constanteMagica) {
            return 0;
        }
    }
    int somaDiagonal1 = 0;
    int somaDiagonal2 = 0;
    for (int i = 0; i < TAMANHO4; i++) {
        somaDiagonal1 += matriz[i][i];
        somaDiagonal2 += matriz[i][TAMANHO4 - i - 1];
    }
    if (somaDiagonal1 != constanteMagica || somaDiagonal2 != constanteMagica) {
        return 0;
    }
    return 1;
}

void imprimeMatriz3(int matriz[TAMANHO3][TAMANHO3]) {
    for (int i = 0; i < TAMANHO3; i++) {
        for (int j = 0; j < TAMANHO3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimeMatriz4(int matriz[TAMANHO4][TAMANHO4]) {
    for (int i = 0; i < TAMANHO4; i++) {
        for (int j = 0; j < TAMANHO4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    limparTela();
    int matriz3[TAMANHO3][TAMANHO3];
    int matriz4[TAMANHO4][TAMANHO4];
    do {
        geraMatrizAleatoria3(matriz3);
    } while (!ehQuadradoMagico3(matriz3));
    printf("Matriz 3x3:\n\n");
    imprimeMatriz3(matriz3);
    printf("\nGerando Matriz 4x4...\nIsso pode levar minutos...");
    do {
        geraMatrizAleatoria4(matriz4);
    } while (!ehQuadradoMagico4(matriz4));
    limparTela();
    printf("Matriz 3x3:\n\n");
    imprimeMatriz3(matriz3);
    printf("\nMatriz 4x4:\n\n");
    imprimeMatriz4(matriz4);
    return 0;
}