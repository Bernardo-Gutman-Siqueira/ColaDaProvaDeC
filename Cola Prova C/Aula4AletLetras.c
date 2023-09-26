// 4) Faça um programa que gere letras aleatórias.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//gerar n caracteres aleatorios
main(){
	srand(time(NULL)); //setar o gerador de aleatorios
	int i, n;
	printf("\nQuantos caracteres deseja? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("%c\n", 65+rand()%23);
	}
}