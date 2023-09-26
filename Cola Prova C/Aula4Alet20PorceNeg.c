// 2) Faça um programa que gere números aleatórios reais
// entre -100 e 100 com 20% de chance de ser negativo.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//gerar n numeros reais entre -100 e 100 com 20% de negativos
main(){
	srand(time(NULL)); //setar o gerador de aleatorios
	int i, n;
	printf("\nQuantos numeros reais? ");
	scanf("%d", &n);
	float aleatorio;
	for(i=0; i<n; i++){
		aleatorio = ((float)rand()/(float)RAND_MAX)*100.0; //gera um numero entre 0 e 100
		if(rand()%100 < 20){ // 20 em 100 numeros (20%)
			aleatorio*=-1; //transformo o numero em negativo
		}
		printf("%15.10f\n", aleatorio);
	}
}