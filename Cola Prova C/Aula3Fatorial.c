//1) Faça um programa para calcular o fatorial de um número lido.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<math.h> // Inclui o cabeçalho da biblioteca de funções matemáticas

int main(){ // Função principal do programa
	int n, fat=1, i; // Declaração de variáveis inteiras
	printf("\nQual o valor de n? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=n; i>1; i--){ // Loop que executa de n até 2 |||| para i de n ate 2 passo -1 faca
		fat*=i; // Calcula o fatorial multiplicando a variável fat pelo valor atual de i
	}	// fat = fat * i;
	printf("\n%d! = %d\n", n, fat); // Imprime o fatorial do número lido
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
