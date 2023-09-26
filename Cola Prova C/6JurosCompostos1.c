// 6. Calculadora de Juros Compostos 1:
// Implemente uma calculadora de juros compostos. O usuário deve inserir o valor principal, a taxa de 
// juros mensal e o número de meses. O programa deve calcular e exibir o montante final.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <math.h> // Inclui a biblioteca matemática para usar funções como pow()

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        double principal, taxa, montante; // Declara as variáveis 'principal', 'taxa' e 'montante' como double
        int meses; // Declara a variável 'meses' como int
        printf("Digite o valor principal: "); // Solicita ao usuário para inserir o valor principal
        scanf("%lf", &principal); // Lê o valor principal inserido pelo usuário
        printf("Digite a taxa de juros mensal em porcentagem %%: "); // Solicita ao usuário para inserir a taxa de juros mensal
        scanf("%lf", &taxa); // Lê a taxa de juros mensal inserida pelo usuário
        printf("Digite o numero de meses: "); // Solicita ao usuário para inserir o número de meses
        scanf("%d", &meses); // Lê o número de meses inserido pelo usuário

        taxa = taxa / 100; // Converte a taxa de juros de porcentagem para decimal
        montante = principal * pow(1 + taxa, meses); // Calcula o montante usando a fórmula dos juros compostos

        printf("O montante final eh: %.2f\n", montante); // Imprime o montante final calculado

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
