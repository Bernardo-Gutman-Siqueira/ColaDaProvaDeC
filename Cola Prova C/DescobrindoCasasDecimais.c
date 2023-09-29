//Faça um programa que descubra as casas decimais de Float e Double.
#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    float f = 1; // Declaração de uma variável do tipo float
    double d = 1; // Declaração de uma variável do tipo double

    int casasDecimaisF = 0,casasDecimaisD = 0; // Declaração de duas variáveis inteiras para armazenar o número de casas decimais

    while ( f > 0) { // Enquanto o valor de f for maior que zero
        f /= 10.0; // Divide o valor de f por 10
        casasDecimaisF++; // Incrementa o contador de casas decimais para float
    }

    while ( d > 0) { // Enquanto o valor de d for maior que zero
        d /= 10.0; // Divide o valor de d por 10
        casasDecimaisD++; // Incrementa o contador de casas decimais para double
    }

    printf("Float sao %d casas decimais e Double sao %d casas.",casasDecimaisF,casasDecimaisD); // Imprime o número de casas decimais para float e double

    return 0; // Retorna zero indicando que o programa terminou com sucesso
}
