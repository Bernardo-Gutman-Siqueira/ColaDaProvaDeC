// 10. Cálculo de Tensão e Corrente em Circuitos Elétricos:
// Crie um programa que permita ao usuário calcular a tensão, corrente ou resistência em um circuito 
// elétrico usando a Lei de Ohm (V = I * R). O programa deve solicitar ao usuário qual variável ele deseja 
// calcular e ler as outras duas.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial

void dsjRepetir() { // Função para perguntar ao usuário se ele deseja repetir o processo
    printf("Deseja repetir ? (s ou n)\n:");
    scanf(" %c",&repetir); // Lê a resposta do usuário
}

int main() { // Função principal do programa
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        double tensao, corrente, resistencia; // Declara as variáveis 'tensao', 'corrente' e 'resistencia' como double
        char opcao; // Declara a variável 'opcao' como char
        printf("Digite a variavel que deseja calcular (T para tensao, C para corrente ou R para resistencia): "); // Solicita ao usuário para escolher a variável que deseja calcular
        scanf(" %c", &opcao); // Lê a opção escolhida pelo usuário

        if (opcao == 'T' || opcao == 't') { // Se a opção for tensão...
            printf("Digite o valor da corrente em A: "); // Solicita ao usuário para inserir o valor da corrente
            scanf("%lf", &corrente); // Lê o valor da corrente inserido pelo usuário
            printf("Digite o valor da resistencia em ohms: "); // Solicita ao usuário para inserir o valor da resistência
            scanf("%lf", &resistencia); // Lê o valor da resistência inserido pelo usuário
            tensao = corrente * resistencia; // Calcula a tensão usando a fórmula V = I * R
            printf("A tensao eh: %.2f V\n", tensao); // Imprime a tensão calculada
            dsjRepetir(); // Chama a função para perguntar ao usuário se ele deseja repetir o processo
        } else if (opcao == 'C' || opcao == 'c') { // Se a opção for corrente...
            printf("Digite o valor da tensao em V: "); // Solicita ao usuário para inserir o valor da tensão
            scanf("%lf", &tensao); // Lê o valor da tensão inserido pelo usuário
            printf("Digite o valor da resistencia em ohms: "); // Solicita ao usuário para inserir o valor da resistência
            scanf("%lf", &resistencia); // Lê o valor da resistência inserido pelo usuário
            corrente = tensao / resistencia; // Calcula a corrente usando a fórmula I = V / R
            printf("A corrente eh: %.2f A\n", corrente); // Imprime a corrente calculada
            dsjRepetir(); // Chama a função para perguntar ao usuário se ele deseja repetir o processo
        } else if (opcao == 'R' || opcao == 'r') { // Se a opção for resistência...
            printf("Digite o valor da tensao em V: "); // Solicita ao usuário para inserir o valor da tensão
            scanf("%lf", &tensao); // Lê o valor da tensão inserido pelo usuário
            printf("Digite o valor da corrente em A: "); // Solicita ao usuário para inserir o valor da corrente
            scanf("%lf", &corrente); // Lê o valor da corrente inserido pelo usuário
            resistencia = tensao / corrente; // Calcula a resistência usando a fórmula R = V / I
            printf("A resistencia eh: %.2f ohms\n", resistencia); // Imprime a resistência calculada
            dsjRepetir(); // Chama a função para perguntar ao usuário se ele deseja repetir o processo
        } else {
            printf("Opcao invalida!\n");  // Se nenhuma das condições acima for verdadeira, imprime uma mensagem de erro 
        }
    }
    return 0;  // Retorna 0 indicando que o programa foi executado com sucesso 
}
