// 5. Conversão de Unidades de Comprimento:
// Crie um programa que converta uma medida em metros para centímetros, milímetros e quilômetros. 
// O usuário deve fornecer a medida em metros, e o programa deve realizar as conversões.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        double metros, centimetros, milimetros, quilometros; // Declara as variáveis 'metros', 'centimetros', 'milimetros' e 'quilometros' como double
        printf("Digite a medida em metros: "); // Solicita ao usuário para inserir a medida em metros
        scanf("%lf", &metros); // Lê a medida em metros inserida pelo usuário

        centimetros = metros * 100; // Converte metros para centímetros
        milimetros = metros * 1000; // Converte metros para milímetros
        quilometros = metros / 1000; // Converte metros para quilômetros

        printf("%.2f metros equivalem a %.2f centimetros.\n", metros, centimetros); // Imprime a conversão de metros para centímetros
        printf("%.2f metros equivalem a %.2f milimetros.\n", metros, milimetros); // Imprime a conversão de metros para milímetros
        printf("%.2f metros equivalem a %.6f quilometros.\n", metros, quilometros); // Imprime a conversão de metros para quilômetros

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
