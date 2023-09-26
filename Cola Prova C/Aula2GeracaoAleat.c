#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo

int main(){ // Função principal do programa
	srand(time(NULL)); //Corrige o problema da geracao aleatoria repetida
	int i, n, aleatorio; // Declaração de variáveis inteiras
	printf("\nQuantos numeros aleatorios deseja? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		aleatorio = rand()%101; // Gera um número aleatório entre 0 e 100
		printf("\t%4d\n", aleatorio); // Imprime o número aleatório gerado
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
