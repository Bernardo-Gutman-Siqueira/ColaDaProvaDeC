// 3) Faça um programa para apresentar os n primeiros números primos.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Numeros Primos
int main(){
	int i, j, ehPrimo, qtd;
	printf("\nQuantos numeros primos? ");
	scanf("%d", &qtd);
	for(i=1; i<=qtd; i++){
		ehPrimo = 1; //considero que todo numero eh primo ate prova contraria
		for(j=sqrt(i); j>1; j--){
			if(i%j == 0){ //se o resto da divisao for 0
				ehPrimo = 0; // nao eh primo
			}
		}
		if(ehPrimo == 1){
			printf("%d eh Primo\n", i);
		}else{
			qtd++; //testo mais um numero
		}
	}
}