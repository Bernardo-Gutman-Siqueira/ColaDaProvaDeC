// 15. Conversão de Unidades de Velocidade:
// Crie um programa que converta velocidades entre unidades, como metros por segundo (m/s), 
// quilômetros por hora (km/h) e milhas por hora (mph). O programa deve solicitar ao usuário qual 
// unidade lida e converter para as outras duas.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial

void desejaRep() { // Função para perguntar ao usuário se ele deseja repetir o processo
    printf("Deseja repetir ? (s ou n)\n:");
    scanf(" %c",&repetir); // Lê a resposta do usuário
}

int main() { // Função principal do programa
    float velocidade; // Declara a variável 'velocidade' como float
    int opcao; // Declara a variável 'opcao' como int
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Conversao de Unidades de Velocidade.\n");
        printf("Digite a velocidade.\n:");
        scanf("%f", &velocidade); // Lê a velocidade inserida pelo usuário
        printf("Escolha a unidade da velocidade digitada:\n");
        printf("1. Metros por segundo (m/s)\n");
        printf("2. Quilometros por hora (km/h)\n");
        printf("3. Milhas por hora (mph)\n:");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        switch (opcao) { // Verifica qual opção foi escolhida
            case 1: // Se a opção for metros por segundo...
                printf("%.2f m/s = %.2f km/h\n", velocidade, velocidade * 3.6); // Converte e imprime a velocidade em km/h
                printf("%.2f m/s = %.2f mph\n", velocidade, velocidade * 2.23694); // Converte e imprime a velocidade em mph
                desejaRep(); // Chama a função para perguntar ao usuário se ele deseja repetir o processo
                break;
            case 2: // Se a opção for quilômetros por hora...
                printf("%.2f km/h = %.2f m/s\n", velocidade, velocidade / 3.6); // Converte e imprime a velocidade em m/s
                printf("%.2f km/h = %.2f mph\n", velocidade, velocidade / 1.60934); // Converte e imprime a velocidade em mph
                desejaRep(); // Chama a função para perguntar ao usuário se ele deseja repetir o processo
                break;
            case 3: // Se a opção for milhas por hora...
                printf("%.2f mph = %.2f m/s\n", velocidade, velocidade / 2.23694); // Converte e imprime a velocidade em m/s
                printf("%.2f mph = %.2f km/h\n", velocidade, velocidade * 1.60934); // Converte e imprime a velocidade em km/h
                desejaRep(); // Chama a função para perguntar ao usuário se ele deseja repetir o processo
                break;
            default: 
                printf("Opcao invalida.\n");  // Se nenhuma das condições acima for verdadeira, imprime uma mensagem de erro 
        }  
    }
    return 0;  // Retorna 0 indicando que o programa foi executado com sucesso 
}
