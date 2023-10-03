// 2) Faça um programa que gere dois números aleatórios, o primeiro entre 10 e 100, o
// segundo entre 50 e 1000. Após isso gere n números aleatórios reais, (n também
// aleatório entre 300 e 600), entre o primeiro e o segundo. Ao final apresente a média
// de todos os números no intervalo entre o primeiro e o segundo e a quantidade de
// números gerados.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int min1 = 10, max1 = 100;
    int min2 = 50, max2 = 1000;
    int min3 = 300, max3 = 600;
    int n1aletMenor, n2aletMaior, nGerados, aux, i;
    float aleatorios, media = 0;
    
    n1aletMenor = (rand() % (max1 - min1 + 1)) + min1;
    n2aletMaior = (rand() % (max2 - min2 + 1)) + min2;
    nGerados = (rand() % (max3 - min3 + 1)) + min3;

    if (n1aletMenor > n2aletMaior) {
            aux = n1aletMenor;
            n1aletMenor = n2aletMaior;
            n2aletMaior = aux;
        }

    for (i = 0; i < nGerados; i++)
    {
        aleatorios = ((float)rand()/(float)(RAND_MAX)) * (n2aletMaior - n1aletMenor) + n1aletMenor;
        media += aleatorios;
    }
    
    media /= nGerados;

    printf("A media foi %f.\n", media);
    printf("%d numeros foram gerados.", nGerados);
    return 0;
}