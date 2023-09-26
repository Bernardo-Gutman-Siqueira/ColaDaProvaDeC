#include<stdio.h>
#include<stdlib.h>
#include<time.h> //cabecalho para uso de funcoes de tempo

int main(){//metodo principal

	srand(time(NULL)); //corrige o problema da geracao aleatoria repetida

	int i, n, aleatorio; //declaracao de variaveis inteiras
    
	printf("\nQuantos numeros aleatorios deseja? ");
	scanf("%d", &n); //lendo uma variavel inteira e colocando na memoria de n
	for(i=0; i<n; i++){
		aleatorio = rand()%101; //gerando um aleatorio entre 0 e 100
		printf("\t%4d\n", aleatorio); 
	}
}