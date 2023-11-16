#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
// Função principal do programa
int main(){
	int i, j, n; // Declaração de variáveis
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	printf("\nQual a dimensao da matriz? "); // Solicita ao usuário a dimensão da matriz
	scanf("%d", &n); // Lê a dimensão da matriz
	int mat[n][n]; // Declaração de uma matriz nxn
	// Preenche a diagonal principal da matriz com números aleatórios
	for(i=0; i<n; i++){
		mat[i][i] = rand()%100; // Gera um número aleatório entre 0 e 99
	}
	// Preenche o restante da matriz com números aleatórios menores que o valor na diagonal principal
	for(i=0; i<n; i++){
		for(j=0; j<n; j++) {
			if(i != j){ // Se não estamos na diagonal principal
				mat[i][j] = rand() % mat[i][i]; // Gera um número aleatório entre 0 e mat[i][i]-1
			}
			printf("%d\t", mat[i][j]); // Imprime o valor na matriz
		}
		printf("\n\n"); // Imprime uma nova linha após cada linha da matriz
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
