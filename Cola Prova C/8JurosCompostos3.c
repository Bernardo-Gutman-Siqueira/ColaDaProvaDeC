// 8. Calculadora de Juros Compostos 3:
// Refaça novamente o exercício, só que agora use juros mensais serão aleatórios entre -1% e 1% ao 
// mês, com probabilidade de ser negativo de 30%. O usuário deve digitar o valor inicial e o tempo do 
// investimento. Ao final informar o valor total

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão para usar funções como rand()
#include <time.h> // Inclui a biblioteca de tempo para usar funções como time()
#include <math.h> // Inclui a biblioteca matemática para usar funções como pow()

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        double principal, taxa, montante; // Declara as variáveis 'principal', 'taxa' e 'montante' como double
        int meses, i; // Declara as variáveis 'meses' e 'i' como int
        printf("Digite o valor inicial: "); // Solicita ao usuário para inserir o valor inicial
        scanf("%lf", &principal); // Lê o valor inicial inserido pelo usuário
        printf("Digite o tempo em meses: "); // Solicita ao usuário para inserir o tempo em meses
        scanf("%d", &meses); // Lê o tempo em meses inserido pelo usuário

        srand(time(NULL)); // Inicializa o gerador de números aleatórios com a hora atual

        montante = principal; // Atribui o valor inicial à variável 'montante'
        for (i = 0; i < meses; i++) { // Loop que se repete 'meses' vezes
            if (rand() % 100 < 30) // Se um número aleatório entre 0 e 99 for menor que 30 (30% de chance)...
                taxa = -(rand() % 11) / 10.0; // Gera uma taxa de juros aleatória entre -1% e 0%
            else // Se não...
                taxa = (rand() % 11) / 10.0; // Gera uma taxa de juros aleatória entre 0% e 1%
            montante *= 1 + taxa / 100; // Calcula o montante usando a fórmula dos juros compostos
        }

        printf("O valor total apos %d meses eh: %.2f\n", meses, montante); // Imprime o valor total após 'meses' meses

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
