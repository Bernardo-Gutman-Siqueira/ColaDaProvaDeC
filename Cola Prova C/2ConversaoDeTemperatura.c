// 2. Conversão de Temperatura:
// Crie um programa que leia uma temperatura em Celsius, Fahrenheit ou Kelvin (Usuário definirá) e 
// converta esta temperatura para as outras duas.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

double temperatura, celsius, fahrenheit, kelvin; // Declara as variáveis 'temperatura', 'celsius', 'fahrenheit' e 'kelvin' como double
char unidade; // Declara a variável 'unidade' como char

void printTemp() { // Função para imprimir as temperaturas convertidas
    printf("Temperatura em Celsius eh: %.2f graus celsius\n", celsius); // Imprime a temperatura em Celsius
    printf("Temperatura em Fahrenheit eh: %.2f graus fahrenheit\n", fahrenheit); // Imprime a temperatura em Fahrenheit
    printf("Temperatura em Kelvin eh: %.2f graus kelvin\n", kelvin); // Imprime a temperatura em Kelvin
}

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Digite a unidade (C, F ou K)\n:"); // Solicita ao usuário para inserir a unidade da temperatura (Celsius, Fahrenheit ou Kelvin)
        scanf(" %c",&unidade); // Lê a unidade inserida pelo usuário
        printf("Digite a temperatura\n: "); // Solicita ao usuário para inserir o valor da temperatura
        scanf("%lf", &temperatura); // Lê o valor da temperatura inserido pelo usuário
        getchar(); // Limpa o buffer de entrada

        if (unidade == 'C' || unidade == 'c') { // Se a unidade for Celsius...
            celsius = temperatura; // Atribui o valor da temperatura à variável 'celsius'
            fahrenheit = celsius * 9.0 / 5.0 + 32; // Converte Celsius para Fahrenheit
            kelvin = celsius + 273.15; // Converte Celsius para Kelvin
            printTemp(); // Chama a função para imprimir as temperaturas convertidas
        } else if (unidade == 'F' || unidade == 'f') { // Se a unidade for Fahrenheit...
            fahrenheit = temperatura; // Atribui o valor da temperatura à variável 'fahrenheit'
            celsius = (fahrenheit - 32) * 5.0 / 9.0; // Converte Fahrenheit para Celsius
            kelvin = celsius + 273.15; // Converte Celsius (já convertido) para Kelvin
            printTemp(); // Chama a função para imprimir as temperaturas convertidas
        } else if (unidade == 'K' || unidade == 'k') { // Se a unidade for Kelvin...
            kelvin = temperatura; // Atribui o valor da temperatura à variável 'kelvin'
            celsius = kelvin - 273.15; // Converte Kelvin para Celsius
            fahrenheit = celsius * 9.0 / 5.0 + 32; // Converte Celsius (já convertido) para Fahrenheit
            printTemp(); // Chama a função para imprimir as temperaturas convertidas
        } else {
            printf("Resposta inválida!\n"); // Se a unidade não for nem C, F ou K, imprime uma mensagem de erro
        }
        printf("Deseja repetir ?\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
