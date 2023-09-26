// 4. Média de Notas:
// Desenvolva um programa em C que calcule a média das 3 notas (P1, P2 e P3) e diga se o aluno passou 
// ou não na disciplina de Programação I. Lembre-se que o aluno pode deixar de fazer uma prova, ou 
// pode fazer as 3. A média aritmética é obtida das duas maiores notas.

#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    char repetir = 's'; // Declara a variável 'repetir' como char e atribui 's' como valor inicial
    printf("Calculadora de notas, caso tenha perdido a prova digite 0.\n"); // Imprime as instruções para o usuário
    while (repetir == 's' || repetir == 'S') // Enquanto o valor de 'repetir' for 's' ou 'S', o loop continuará
    {
        double p1, p2, p3, media; // Declara as variáveis 'p1', 'p2', 'p3' e 'media' como double
        printf("Digite a nota da P1: "); // Solicita ao usuário para inserir a nota da P1
        scanf("%lf", &p1); // Lê a nota da P1 inserida pelo usuário
        printf("Digite a nota da P2: "); // Solicita ao usuário para inserir a nota da P2
        scanf("%lf", &p2); // Lê a nota da P2 inserida pelo usuário
        printf("Digite a nota da P3: "); // Solicita ao usuário para inserir a nota da P3
        scanf("%lf", &p3); // Lê a nota da P3 inserida pelo usuário

        if (p1 == 0 || p2 == 0 || p3 == 0) { // Se qualquer uma das notas for 0...
            media = (p1 + p2 + p3) / 2; // Calcula a média das duas maiores notas
        }
        else if (p1 < p2 && p1 < p3) { // Se a nota da P1 for menor que as notas da P2 e P3...
            media = (p2 + p3) / 2; // Calcula a média das notas da P2 e P3
        }
        else if (p2 < p1 && p2 < p3) { // Se a nota da P2 for menor que as notas da P1 e P3...
            media = (p1 + p3) / 2; // Calcula a média das notas da P1 e P3
        }
        else { // Se nenhuma das condições acima for verdadeira...
            media = (p1 + p2) / 2; // Calcula a média das notas da P1 e P2
        }

        printf("A media das duas maiores notas eh: %.2f\n", media); // Imprime a média calculada

        if (media < 6.0) { // Se a média for menor que 6.0...
            printf("Aluno Reprovado.\n"); // Imprime que o aluno foi reprovado
        } else { // Se nenhuma das condições acima for verdadeira...
            printf("Aluno Aprovado.\n"); // Imprime que o aluno foi aprovado
        }

        printf("Deseja repetir ? (s ou n)\n:"); // Pergunta ao usuário se ele deseja repetir o processo
        scanf(" %c",&repetir); // Lê a resposta do usuário
    }
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
