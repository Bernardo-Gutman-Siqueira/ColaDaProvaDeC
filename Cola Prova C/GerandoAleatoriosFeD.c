#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    float menorF, maiorF;
    double menorD, maiorD;
    int menorI, maiorI, nF = 0, nD = 0, nI = 0, i, j, k;

    printf("Quantos floats deseja gerar ?\n: ");
    scanf("%d", &nF);
    printf("Quantos doubles deseja gerar ?\n: ");
    scanf("%d", &nD);
    printf("Quantos inteiros deseja gerar ?\n: ");
    scanf("%d", &nI);

    printf("\n");// Pular linha..

    if (nF > 0) { // Caso o número de itens gerados seja 0, não pergunte.
        printf("Digite o menor valor para float: ");
        scanf("%f", &menorF);
        printf("Digite o maior valor para float: ");
        scanf("%f", &maiorF);
        if (menorF > maiorF) { // Se o usuário trocou o menor com o maior
            float temp = menorF;
            menorF = maiorF;
            maiorF = temp; // Corrige a troca
        }
        printf("\n");// Pular linha..
    }
    
    if (nD > 0) {// Caso o número de itens gerados seja 0, não pergunte.
        printf("Digite o menor valor para double: ");
        scanf("%lf", &menorD);
        printf("Digite o maior valor para double: ");
        scanf("%lf", &maiorD);
        if (menorD > maiorD) { // Se o usuário trocou o menor com o maior
            double temp = menorD;
            menorD = maiorD;
            maiorD = temp; // Corrige a troca
        }
        printf("\n");// Pular linha..
    }
    
    if (nI > 0) {// Caso o número de itens gerados seja 0, não pergunte.
        printf("Digite o menor valor para inteiro: ");
        scanf("%d", &menorI);
        printf("Digite o maior valor para inteiro: ");
        scanf("%d", &maiorI);
        if (menorI > maiorI) { // Se o usuário trocou o menor com o maior
            int temp = menorI;
            menorI = maiorI;
            maiorI = temp; // Corrige a troca
        }
        printf("\n");// Pular linha..
    }
    
    for ( i = 0; i < nF; i++)
    {// Loop que gera um número aleatório entre menor e maior para float.
        float randFloat = ((float)rand()/(float)(RAND_MAX)) * (maiorF - menorF) + menorF;
        printf("Float: %f\n", randFloat);
    }
    for ( j = 0; j < nD; j++)
    {// Loop que gera um número aleatório entre menor e maior para double.
        double randDouble = ((double)rand()/(double)(RAND_MAX)) * (maiorD - menorD) + menorD;
        printf("Double: %lf\n", randDouble);
    }
    for ( k = 0; k < nI; k++)
    {// Loop que gera um número aleatório entre menor e maior para Int.
        int randInt = (rand() % (maiorI - menorI + 1)) + menorI;
        printf("Int: %d\n", randInt);
    }
    return 0;
}