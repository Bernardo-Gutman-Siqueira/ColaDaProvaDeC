#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Faça um programa em C que gere n números (n pode ser qualquer quantidade, 
inclusive 1 milhão) aleatórios entre 1 e 10000 com a seguinte condição: 
Não pode haver dígitos iguais nos números gerados.
Repare que o programa deve dar a possibilidade de gerar qualquer número dentro 
do intervalo, mas, por exemplo, não pode imprimir 1431, pois o dígito 1 
aparece 2 vezes no mesmo número.*/
int verificaDigitos(int num) {
    int digitos[10] = {0};
    while (num > 0) {
        if (digitos[num % 10]) {
            return 0;
        }
        digitos[num % 10] = 1;
        num /= 10;
    }
    return 1;
}

int main() {
    int n, i, num;
    srand(time(NULL));
    printf("Digite a quantidade de numeros a serem gerados: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        do {
            num = rand() % 10000 + 1;
        } while (!verificaDigitos(num));
        printf("%d ", num);
    }
    return 0;
}