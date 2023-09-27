// 5) Faça um programa que gere n, aleatórias, placas de veículos no padrão mercosul.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
//gerando placas mercosul aleatorias
// Função principal do programa
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	int i, n; // Declaração de variáveis inteiras
	printf("\nQuantas placas deseja? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		printf("%c", 65+rand()%23); // Imprime um caractere aleatório entre 'A' e 'W'
		printf("%c", 65+rand()%23); // Imprime um caractere aleatório entre 'A' e 'W'
		printf("%c - ", 65+rand()%23); // Imprime um caractere aleatório entre 'A' e 'W'
		printf("%d", rand()%10); // Imprime um dígito aleatório entre 0 e 9
		printf("%c", 65+rand()%23); // Imprime um caractere aleatório entre 'A' e 'W'
		printf("%d", rand()%10); // Imprime um dígito aleatório entre 0 e 9
		printf("%d\n", rand()%10); // Imprime um dígito aleatório entre 0 e 9
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
