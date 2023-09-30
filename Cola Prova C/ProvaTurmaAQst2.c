// O outro era para gerar um número aleatório entre 1000 e 10000,
// aí com gerar um valor entre 1 e 5 e dividir o numero indefinidamente
// até que esteja entre 0 e 1
// Código fornecido por Lorran, não sei se tá 100% certo.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    float numeroInicial, numero, aleatorio; 
    int qtdAleatorio;
    numero = ((float)rand()/(float)RAND_MAX) * 9000 + 1000; // Gera um número aleatório entre 1000 e 10000
    numeroInicial = numero; // Armazena o número inicial para uso posterior
    while (numero > 1) {// Continua o loop até que o número esteja entre 0 e 1
        aleatorio = ((float)rand()/(float)RAND_MAX) * 4 + 1; // Gera um número aleatório entre 1 e 5
        numero /= aleatorio; // Divide o número pelo valor aleatório
        qtdAleatorio++; // Conta a quantidade de números aleatórios gerados
    }
    printf("\nCom um numero inicial de %.2f foi gerado %d numeros aleatorios com o valor final de %.2f", numeroInicial, qtdAleatorio, numero);
    // Imprime o número inicial,a quantidade de números aleatórios gerados 
    //e o valor final
    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}// Código fornecido por Lorran.