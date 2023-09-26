// 1. Cálculo de Área de um Círculo:
// Escreva um programa em C que calcule a área de um círculo com um raio fornecido pelo usuário. Use 
// a fórmula A = πr².

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <math.h> // Inclui a biblioteca matemática para usar funções como pow()
#define PI 3.14159265358979323846 // Define o valor de PI

int main () { // Função principal do programa
    double area,raio; // Declara as variáveis 'area' e 'raio' como double
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial

    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Digite o raio desejado\n:"); // Solicita ao usuário para inserir o valor do raio
        scanf("%lf", &raio); // Lê o valor do raio inserido pelo usuário

        area = PI * (pow(raio,2)); // Calcula a área do círculo usando a fórmula A = πr²

        printf("A area do circulo eh: %.17f\n", area); // Imprime a área calculada

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf("%s",&repetir); // Lê a resposta do usuário
    }

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
