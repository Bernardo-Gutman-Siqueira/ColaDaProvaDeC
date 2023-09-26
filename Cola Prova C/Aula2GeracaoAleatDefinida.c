#include<stdio.h>
#include<stdlib.h>
#include<time.h> //cabecalho de funcoes de tempo

int main(){ //metodo principal
	srand(time(NULL)); //corrigindo o problema de geracao igual de numeros
	int i, n, inferior, superior; //declarando variaveis inteiras
	printf("\nQuantos numeros aleatorios deseja? ");
	scanf("%d", &n); //lendo um inteiro e colocando na posicao de memoria de n
	printf("\nQual o menor número? ");
	scanf("%d", &inferior);
	printf("\nQual o maior número? ");
	scanf("%d", &superior);
	
	for(i=0; i<n; i++){ //laco para executando n vezes
		printf("\t%4d\n", (inferior)+(rand()%(superior-inferior+1))); //uma tabulacao depois 4 espacos
	}
}