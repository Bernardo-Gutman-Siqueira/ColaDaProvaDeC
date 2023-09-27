// 4) Faça um programa que gere letras aleatórias.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo
//gerar n caracteres aleatorios
// Função principal do programa
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	int i, n; // Declaração de variáveis inteiras
	printf("\nQuantos caracteres deseja? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		printf("%c\n", 65+rand()%23); // Imprime um caractere aleatório entre 'A' e 'W'
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
