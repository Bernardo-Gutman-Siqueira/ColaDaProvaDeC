// 3. Resistência Elétrica em Paralelo:
// Escreva um programa que calcule a resistência total de resistores em um circuito elétrico em paralelo. 
// O usuário deve inserir a quantidade de resistores e depois os valores das resistências de cada um. O
// programa deve calcular o resultado.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        int n, i; // Declara as variáveis 'n' e 'i' como int
        double r, rt = 0; // Declara as variáveis 'r' e 'rt' como double e atribui 0 a 'rt'
        printf("Digite o numero de resistores: "); // Solicita ao usuário para inserir o número de resistores
        scanf("%d", &n); // Lê o número de resistores inserido pelo usuário
        for (i = 0; i < n; i++) { // Loop que se repete 'n' vezes
            printf("Digite o valor do resistor %d: ", i + 1); // Solicita ao usuário para inserir o valor do resistor
            scanf("%lf", &r); // Lê o valor do resistor inserido pelo usuário
            rt += 1 / r; // Calcula a resistência total em paralelo
        }
        rt = 1 / rt; // Converte a resistência total para o formato correto
        printf("A resistencia total eh: %.2f\n", rt); // Imprime a resistência total calculada
        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
