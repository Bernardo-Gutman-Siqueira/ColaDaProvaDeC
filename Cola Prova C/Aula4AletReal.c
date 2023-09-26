// 1) Faça um programa que gere números aleatórios reais.

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
//gerando aleatorios reais
main(){
	srand(time(NULL));
	int i, n;
	float aleat;
	printf("\nQuantos numeros reais deseja? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		aleat = ((float)rand()/(float)RAND_MAX); //gera um numero aleatorio entre 0 e 1
		printf("%5d numero gerado\t%.10f\n", (i+1), aleat);
	}
}