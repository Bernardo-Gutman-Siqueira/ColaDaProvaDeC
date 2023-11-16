/*Faça um programa em C que gere e apresente a matriz (n x n),
onde n é digitado pelo usuário.
Seu programa deverá gerar inicialmente um valor aleatório entre 1 e 100 para a 
diagonal prinipal. Depois todos os números gerados,
fora da diagonal principal, deverão ser a semente para
a geração na mesma linha, ou seja, se na posição 0, 0 da matriz o número 
gerado for 10, todos os número desta linha (0) deverão estar entre 0 e 10.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int n, i, j; // Declaração de variáveis
	printf("\nQual a dimenssao da matriz? "); // Solicita ao usuário a dimensão da matriz
	scanf("%d", &n); // Lê a dimensão da matriz
	int mat[n][n]; // Declaração de uma matriz nxn
	// Preenche a diagonal principal da matriz com números aleatórios
	for(i=0; i<n; i++){
		mat[i][i] = rand()%100; // Gera um número aleatório entre 0 e 99
		printf("%d\n", mat[i][i]); // Imprime o valor na diagonal principal
	}
	printf("\nMATRIZ\n"); // Imprime uma mensagem indicando o início da matriz
	// Preenche o restante da matriz com números aleatórios menores que o valor na diagonal principal
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i != j){ // Se não estamos na diagonal principal
				mat[i][j] = rand()%mat[i][i]; // Gera um número aleatório entre 0 e mat[i][i]-1
			}
			printf("%d\t", mat[i][j]); // Imprime o valor na matriz
		}
		printf("\n\n"); // Imprime uma nova linha após cada linha da matriz
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
