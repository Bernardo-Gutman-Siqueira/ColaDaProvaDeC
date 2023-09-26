// 12. Conversão de Unidades de Massa:
// Crie um programa que converta uma massa de quilogramas para gramas, libras e onças. O programa 
// deve solicitar a massa em quilogramas.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    float quilogramas , gramas, libras, oncas; // Declara as variáveis 'quilogramas', 'gramas', 'libras' e 'oncas' como float
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Digite a massa em kg: "); // Solicita ao usuário para inserir a massa em quilogramas
        scanf("%f", &quilogramas); // Lê a massa em quilogramas inserida pelo usuário

        gramas = quilogramas * 1000; // Converte quilogramas para gramas
        libras = quilogramas * 2.20462; // Converte quilogramas para libras
        oncas = quilogramas * 35.274; // Converte quilogramas para onças

        printf("%.2f quilogramas eh igual a:\n", quilogramas); // Imprime a massa em quilogramas
        printf("%.2f gramas.\n", gramas); // Imprime a conversão de quilogramas para gramas
        printf("%.2f libras.\n", libras); // Imprime a conversão de quilogramas para libras
        printf("%.2f oncas.\n", oncas); // Imprime a conversão de quilogramas para onças

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
