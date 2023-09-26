// 9. Cálculo de Força em Física:
// Implemente um programa que calcule a força resultante de um objeto, dados sua massa e a 
// aceleração. Use a fórmula F = m * a, onde F é a força, m é a massa e a é a aceleração

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        double massa, aceleracao, forca; // Declara as variáveis 'massa', 'aceleracao' e 'forca' como double
        printf("Digite a massa do objeto (em kg): "); // Solicita ao usuário para inserir a massa do objeto
        scanf("%lf", &massa); // Lê a massa inserida pelo usuário
        printf("Digite a aceleracao do objeto em m/s ao quadrado: "); // Solicita ao usuário para inserir a aceleração do objeto
        scanf("%lf", &aceleracao); // Lê a aceleração inserida pelo usuário

        forca = massa * aceleracao; // Calcula a força usando a fórmula F = m * a

        printf("A forca resultante e: %.2f N\n", forca); // Imprime a força resultante calculada

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
