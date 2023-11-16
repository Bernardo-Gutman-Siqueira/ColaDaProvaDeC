#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
/*Faça um programa em C que gere e apresente a matriz (n x n),
onde n é digitado pelo usuário.
Seu programa deverá gerar inicialmente um valor aleatório entre 1 e 100 para a diagonal 
secundaria. Depois todos os números gerados, fora da diagonal secundaria, deverão 
ser a semente para a geração na mesma linha.*/
int main(){
	int i, j, n; // Declaração de variáveis
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	printf("\nQual a dimensao da matriz? "); // Solicita ao usuário a dimensão da matriz
	scanf("%d", &n); // Lê a dimensão da matriz
	int mat[n][n]; // Declaração de uma matriz nxn
	// Preenche a diagonal secundária da matriz com números aleatórios
	for(i=0; i<n; i++){
		mat[i][n-i-1] = rand()%100; // Gera um número aleatório entre 0 e 99
	}
	// Preenche o restante da matriz com números aleatórios menores que o valor na diagonal secundária
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i != n-j-1){ // Se não estamos na diagonal secundária
				mat[i][j] = rand()%(mat[i][n-i-1]+1); // Gera um número aleatório entre 0 e mat[i][n-i-1]
			}
		}
	}
	// Imprime a matriz
	printf("\nMATRIZ\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", mat[i][j]); // Imprime o valor na matriz
		}
		printf("\n\n"); // Imprime uma nova linha após cada linha da matriz
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
