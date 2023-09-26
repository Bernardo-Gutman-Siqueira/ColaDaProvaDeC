// 14. Simulação de Movimento de um Pêndulo:
// Escreva um programa que simule o movimento de um pêndulo simples, à cada 1 segundo, em um 
// campo gravitacional. O programa deve calcular a posição angular em função do tempo e o usuário 
// deve informar o comprimento do pêndulo e o ângulo inicial (em graus)

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <math.h> // Inclui a biblioteca matemática para usar funções como cos() e sqrt()
#define GravidadeTerra 9.80 // Define a gravidade da Terra
#define PI 3.14159265358979323846 // Define o valor de PI

int main() { // Função principal do programa
    double comprimento, anguloInicial, angulo, tempo = 0.0; // Declara as variáveis 'comprimento', 'anguloInicial', 'angulo' e 'tempo' como double
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        printf("Digite o comprimento do pendulo em metros: "); // Solicita ao usuário para inserir o comprimento do pêndulo
        scanf("%lf", &comprimento); // Lê o comprimento inserido pelo usuário
        printf("Digite o angulo inicial em graus: "); // Solicita ao usuário para inserir o ângulo inicial
        scanf("%lf", &anguloInicial); // Lê o ângulo inicial inserido pelo usuário

        anguloInicial = anguloInicial * PI / 180.0; // Converte o ângulo inicial de graus para radianos

        for (int i = 0; i < 10; i++) { // Loop que se repete 10 vezes
            angulo = anguloInicial * cos(sqrt(GravidadeTerra / comprimento) * tempo); // Calcula a posição angular usando a fórmula θ = θ₀ * cos(sqrt(g / l) * t)
            printf("No tempo t = %.2f s, a posicao angular eh %.2f graus\n", tempo, angulo*180/PI); // Imprime a posição angular em função do tempo
            tempo += 1.0; // Incrementa o tempo em 1 segundo
        }

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
