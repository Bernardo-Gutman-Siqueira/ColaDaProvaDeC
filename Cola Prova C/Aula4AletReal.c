// 1) Faça um programa que gere números aleatórios reais.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
// Gerando aleatorios reais
// Função principal do programa
int main() {
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	int i, n; // Declaração de variáveis inteiras
	float aleat; // Declaração de variável de ponto flutuante
	printf("\nQuantos numeros reais deseja? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		aleat = ((float)rand()/(float)RAND_MAX); // Gera um número aleatório entre 0 e 1
		printf("%5d numero gerado\t%.10f\n", (i+1), aleat); // Imprime o número aleatório gerado
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
