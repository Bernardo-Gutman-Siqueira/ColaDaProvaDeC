// 11. Simulação de Lançamento de Projéteis:
// Desenvolva um programa que simule o movimento de um projétil lançado com uma determinada 
// velocidade inicial e ângulo de lançamento. O programa deve calcular a altura máxima atingida e o 
// alcance horizontal.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <math.h> // Inclui a biblioteca matemática para usar funções como pow() e sin()
#define GravidadeTerra 9.80 // Define a gravidade da Terra
#define PI 3.14159265358979323846 // Define o valor de PI

int main() { // Função principal do programa
    double velocidadeInicial, angulo, alturaMax, alcance, anguloRad; // Declara as variáveis 'velocidadeInicial', 'angulo', 'alturaMax', 'alcance' e 'anguloRad' como double
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Digite a velocidade inicial: "); // Solicita ao usuário para inserir a velocidade inicial
        scanf("%lf", &velocidadeInicial); // Lê a velocidade inicial inserida pelo usuário
        printf("Digite o angulo: "); // Solicita ao usuário para inserir o ângulo
        scanf("%lf", &angulo); // Lê o ângulo inserido pelo usuário

        anguloRad = angulo * PI / 180.0; // Converte o ângulo de graus para radianos

        alturaMax = (pow(velocidadeInicial, 2) * pow(sin(anguloRad), 2)) / (2 * GravidadeTerra); // Calcula a altura máxima usando a fórmula h = (v^2 * sin^2(a)) / (2 * g)
        alcance = (pow(velocidadeInicial, 2) * sin(2 * anguloRad)) / GravidadeTerra; // Calcula o alcance usando a fórmula R = (v^2 * sin(2a)) / g

        printf("Altura maxima atingida: %.2f metros\n", alturaMax); // Imprime a altura máxima atingida
        printf("Alcance horizontal: %.2f metros\n", alcance); // Imprime o alcance horizontal

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
