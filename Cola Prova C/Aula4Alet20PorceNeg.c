// 2) Faça um programa que gere números aleatórios reais
// entre -100 e 100 com 20% de chance de ser negativo.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo
//gerar n numeros reais entre -100 e 100 com 20% de negativos
// Função principal do programa
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	int i, n; // Declaração de variáveis inteiras
	printf("\nQuantos numeros reais? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	float aleatorio; // Declaração de variável de ponto flutuante
	for(i=0; i<n; i++){ // Loop que executa n vezes
		aleatorio = ((float)rand()/(float)RAND_MAX)*100.0; // Gera um número aleatório entre 0 e 100
		if(rand()%100 < 20){ // Se um número aleatório entre 0 e 99 é menor que 20 (20% de chance)
			aleatorio*=-1; // Transforma o número em negativo
		}
		printf("%15.10f\n", aleatorio); // Imprime o número aleatório gerado
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
