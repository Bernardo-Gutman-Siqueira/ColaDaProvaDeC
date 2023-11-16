#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
// Função principal do programa
int main(){
	int i, j, n, m; // Declaração de variáveis
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	printf("\nQual a qtd de linhas da matriz? "); // Solicita ao usuário a quantidade de linhas da matriz
	scanf("%d", &n); // Lê a quantidade de linhas da matriz
	printf("\nQual a qtd de colunas da matriz? "); // Solicita ao usuário a quantidade de colunas da matriz
	scanf("%d", &m); // Lê a quantidade de colunas da matriz
	FILE *arquivo = fopen("ArquivoMatriz.txt", "w"); // Abre o arquivo "ArquivoMatriz.txt" para escrita
	// Verifica se o arquivo foi aberto com sucesso
	if(arquivo == NULL){
		printf("\nNao foi possivel criar o arquivo\n"); // Imprime uma mensagem de erro se o arquivo não pôde ser aberto
		return -1; // Retorna -1 indicando que o programa terminou com erro
	}
	// Gera uma matriz aleatória e escreve no arquivo
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			fprintf(arquivo, "%.2f\t", ((float)rand()/(float)RAND_MAX)*100); // Gera um número aleatório entre 0 e 100 e escreve no arquivo
		}
		fprintf(arquivo, "\n\n"); // Escreve uma nova linha após cada linha da matriz
	}
	fclose(arquivo); // Fecha o arquivo
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
