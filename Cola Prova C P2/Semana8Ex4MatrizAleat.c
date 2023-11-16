#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<math.h> // Inclui o arquivo de cabeçalho para funções matemáticas
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
//4) Crie uma matriz de números aleatórios
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int i, j, linhas, colunas; // Declaração de variáveis
	printf("\nQuantas linhas na matriz? "); // Solicita ao usuário o número de linhas da matriz
	scanf("%d", &linhas); // Lê o número de linhas da matriz
	printf("\nQuantas colunas na matriz? "); // Solicita ao usuário o número de colunas da matriz
	scanf("%d", &colunas); // Lê o número de colunas da matriz
	int mat[linhas][colunas]; // Declaração de matriz de tamanho linhas x colunas.
	// Preenche a matriz com números aleatórios
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			mat[i][j] = rand()%100; // Gera um número aleatório
		}
	}
	// Imprime a matriz
	printf("\nA matriz ficou assim: \n");
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			printf("%d\t", mat[i][j]); // Imprime o elemento da matriz
		}
		printf("\n\n"); // Imprime uma nova linha após cada linha da matriz
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
