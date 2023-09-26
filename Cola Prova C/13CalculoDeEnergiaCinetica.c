// 13. Cálculo de Energia Cinética:
// Implemente um programa que calcule a energia cinética de um objeto em movimento com base em 
// sua massa e velocidade. Use a fórmula E = 0.5 * m * v², onde E é a energia cinética, m é a massa e v 
// é a velocidade.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    float massa, velocidade, energia; // Declara as variáveis 'massa', 'velocidade' e 'energia' como float
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Digite a massa do objeto em kg: "); // Solicita ao usuário para inserir a massa do objeto
        scanf("%f", &massa); // Lê a massa inserida pelo usuário
        printf("Digite a velocidade do objeto em m/s: "); // Solicita ao usuário para inserir a velocidade do objeto
        scanf("%f", &velocidade); // Lê a velocidade inserida pelo usuário

        energia = 0.5 * massa * velocidade * velocidade; // Calcula a energia cinética usando a fórmula E = 0.5 * m * v²

        printf("A energia cinetica do objeto eh: %.2f Joules\n", energia); // Imprime a energia cinética calculada

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
