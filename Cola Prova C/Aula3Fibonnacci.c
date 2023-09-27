// 2) Faça um programa para imprimir os n números da série de Fibonnacci 
// (1 1 2 3 5 8 13 21 34 ...)

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais

//Serie de Fibonacci
// Função principal do programa
int main(){
	int n, i, A=0, B=1, C=1; // Declaração de variáveis inteiras
	printf("\nQuantos termos? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		printf("%d\n", C); // Imprime o termo atual da série de Fibonacci
		C=A+B; // Calcula o próximo termo da série de Fibonacci como a soma dos dois termos anteriores
		A=B; // Atualiza o termo A para o próximo termo na série
		B=C; // Atualiza o termo B para o próximo termo na série
	}
	printf("\n\n");
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
