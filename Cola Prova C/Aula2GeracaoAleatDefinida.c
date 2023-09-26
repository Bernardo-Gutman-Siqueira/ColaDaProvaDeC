#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo

int main(){ // Função principal do programa
	srand(time(NULL)); //Corrigindo o problema de geracao igual de numeros
	int i, n, inferior, superior; // Declaração de variáveis inteiras
	printf("\nQuantos numeros aleatorios deseja? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	printf("\nQual o menor numero? ");
	scanf("%d", &inferior); // Lê um número inteiro do usuário e armazena na variável inferior
	printf("\nQual o maior numero? ");
	scanf("%d", &superior); // Lê um número inteiro do usuário e armazena na variável superior
	
	for(i=0; i<n; i++){ // Loop que executa n vezes
		printf("\t%4d\n", (inferior)+(rand()%(superior-inferior+1))); // Imprime um número aleatório entre inferior e superior (inclusive)
	} //  /t = uma tabulacao depois 4 espacos
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
