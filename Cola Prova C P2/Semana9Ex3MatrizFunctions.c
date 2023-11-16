/*3) Faça um programa com função com o seguinte menu:
   1 - Gerar matriz aleatória.
   2 - Gerar matriz diagonal principal.
   3 - Gerar matriz diagonal secundária.
   4 - Gerar matriz triangular superior.
   5 - Gerar matriz triangular inferior.
   6 - Imprimir matriz.
   7 - sair.*/
#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
int mat[100][100]; // Declaração global de uma matriz 100x100
// Protótipos das funções
void imprime(int n);  
void geraAleatoria(int n);
void geraDiagPri(int n);
void geraDiagSec(int n);
void geraTriangSup(int n);
void geraTriangInf(int n);
int menu();
int leN();
// Função principal do programa
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int opcao, n; // Declaração de variáveis
	do{
		opcao = menu(); // Chama a função menu que retorna a opção escolhida pelo usuário
		switch(opcao){ // Escolhe a ação com base na opção escolhida
			case 1:
				n = leN(); // Lê a dimensão da matriz
				geraAleatoria(n); // Gera uma matriz aleatória
			break;
			case 2:
				n = leN(); // Lê a dimensão da matriz
				geraDiagPri(n); // Gera uma matriz com a diagonal principal
			break;
			case 3:
				n = leN(); // Lê a dimensão da matriz
				geraDiagSec(n); // Gera uma matriz com a diagonal secundária
			break;
			case 4:
				n = leN(); // Lê a dimensão da matriz
				geraTriangSup(n); // Gera uma matriz triangular superior
			break;
			case 5:
				n = leN(); // Lê a dimensão da matriz
				geraTriangInf(n); // Gera uma matriz triangular inferior
			break;
			case 6:
				imprime(n); // Imprime a matriz
			break;
			default:
				printf("\nOpcao invalida\n"); // Imprime uma mensagem de erro se a opção for inválida
			break;
		}//fim do switch
	}while(opcao != 7); // Continua até que o usuário digite 7 para sair
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
// Função para imprimir a matriz
void imprime(int n){
	int i, j;
 	printf("\n\nA MATRIZ FICOU ASSIM\n\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", mat[i][j]); // Imprime o elemento da matriz
		}
		printf("\n\n"); // Imprime uma nova linha após cada linha da matriz
	}
}  
// Função para gerar uma matriz aleatória
void geraAleatoria(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			mat[i][j] = rand()%100; // Gera um número aleatório entre 0 e 99
		}
	}
}
// Função para gerar uma matriz com a diagonal principal
void geraDiagPri(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i == j){ // Se estamos na diagonal principal
				mat[i][j] = rand()%100; // Gera um número aleatório entre 0 e 99
			}else{
				mat[i][j] = 0; // Caso contrário, atribui 0
			}
		}
	}
}
// Função para gerar uma matriz com a diagonal secundária
void geraDiagSec(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i+j == n-1){ // Se estamos na diagonal secundária
				mat[i][j] = rand()%100; // Gera um número aleatório entre 0 e 99
			}else{
				mat[i][j] = 0; // Caso contrário, atribui 0
			}
		}
	}
}
// Função para gerar uma matriz triangular superior
void geraTriangSup(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(j >= i){ // Se estamos na parte superior da matriz
				mat[i][j] = rand()%100; // Gera um número aleatório entre 0 e 99
			}else{
				mat[i][j] = 0; // Caso contrário, atribui 0
			}
		}
	}
}
// Função para gerar uma matriz triangular inferior
void geraTriangInf(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(j <= i){ // Se estamos na parte inferior da matriz
				mat[i][j] = rand()%100; // Gera um número aleatório entre 0 e 99
			}else{
				mat[i][j] = 0; // Caso contrário, atribui 0
			}
		}
	}
}
// Função para ler a dimensão da matriz
int leN(){
	int n;
	printf("\nQual a dimensao da matriz? ");
	scanf("%d", &n); // Lê a dimensão da matriz
	return n; // Retorna a dimensão da matriz
}
// Função para exibir o menu e ler a opção escolhida pelo usuário
int menu(){
	int op;
	printf("\n1 - Gerar matriz aleatória");
    printf("\n2 - Gerar matriz diagonal principal");
    printf("\n3 - Gerar matriz diagonal secundária");
    printf("\n4 - Gerar matriz triangular superior");
    printf("\n5 - Gerar matriz triangular inferior");
    printf("\n6 - Imprimir matriz");
    printf("\n7 - sair");
    printf("\nQual a sua opcao? ");
    scanf("%d", &op); // Lê a opção escolhida
    return op; // Retorna a opção escolhida
}
