// 4) Faça um programa para calcular o valor de Pi de uma série alternada
// (1 - 1/3 + 1/5 - 1/7  + ... = Pi/4)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Calculo de Pi por serie
int main(){
	int i, n;
	float pi=0, denominador=1, sinal=1;
	printf("\nQual a quantidade de parcelas da serie? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		pi = pi + (1.0/denominador)*sinal; 
		sinal*=-1; //sinal = sinal * -1;
		denominador = denominador + 2;
	}
	printf("\nO valor de pi eh %.10f\n", pi*4.0);
}