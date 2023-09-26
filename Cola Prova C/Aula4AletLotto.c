// 6) Faça um programa que peça ao usuário 3 números inteiros 
// e gere indeterminados números até que os 3 digitados tenham saído pelo menos uma vez.
// Diga quantos sorteios foram feitos até os 3 saírem e quantas vezes cada um saiu.

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
main(){
	srand(time(NULL));
	int N1, N2, N3, aleat, qtdN1=0, qtdN2=0, qtdN3=0, qtd=0;
	printf("\nQuais os 3 numeros entre 0 e 99? ");
	scanf("%d %d %d", &N1, &N2, &N3);
	while(qtdN1 == 0 || qtdN2 == 0 || qtdN3 == 0){
		aleat = rand()%100;
		qtd++;
		if(aleat == N1){
			qtdN1++;
		}
		if(aleat == N2){
			qtdN2++;
		}
		if(aleat == N3){
			qtdN3++;
		}
	}
	printf("\nForam gerados %d numeros", qtd);
	printf("\nO numero %d saiu %d vezes", N1, qtdN1);
	printf("\nO numero %d saiu %d vezes", N2, qtdN2);
	printf("\nO numero %d saiu %d vezes\n", N3, qtdN3);
}