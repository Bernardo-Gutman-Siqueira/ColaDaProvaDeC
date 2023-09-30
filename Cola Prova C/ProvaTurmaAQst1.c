// A numero 1 você entra com "x" e "n" e aplica numa fórmula da expansão 
// da função exponencial utilizando a série de Taylor modificada.
// Código fornecido por Lorran, não sei se tá 100% certo.
#include <stdio.h>
#include <math.h>

int main() {
    float x, S; // Declaração de variáveis para armazenar o valor de entrada 'x' e o resultado 'S'
    int i, n, p, fat = 1, k = 1; // Declaração de variáveis para armazenar o valor de entrada 'n', a variável temporária 'p', o fatorial 'fat' e o contador 'k'
    printf("\nPrimeiro coloque o valor de x\n:"); // Solicita ao usuário para inserir o valor de 'x'
    scanf("%f", &x); // Lê o valor de entrada fornecido pelo usuário para 'x'
    printf("\nPor ultimo qual eh o valor de n (Coloque um numero inteiro para calculo de fatorial)\n:"); // Solicita ao usuário para inserir o valor de 'n'
    scanf("%d", &n); // Lê o valor de entrada fornecido pelo usuário para 'n'
    p = n; // Atribui o valor de 'n' a 'p'
    for (i=p; i>1; i--) { // Loop para calcular o fatorial de 'p'
		fat*=i;
    }
    S = 1 + ((n * x) / fat); // Calcula a primeira parte da série
    while (p > 1) { // Loop para calcular as partes restantes da série
        p--;
        k++;
        fat = 1;
        for (i=p; i>1; i--) { // Loop para calcular o fatorial de 'p'
		    fat*=i;
        }
        S += ((n * p * pow(x, k)) / fat); // Adiciona a parte atual da série ao resultado total
    }
    printf("\nO resultado final desta serie eh %.2f", S); // Imprime o resultado final
    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}// Código fornecido por Lorran.