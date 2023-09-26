//1) Faça um programa para calcular o fatorial de um número lido.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n, fat=1, i;
	printf("\nQual o valor de n? ");
	scanf("%d", &n);
	for(i=n; i>1; i--){ //para i de n ate 2 passo -1 faca
		fat*=i; //fat = fat * i;
	}
	printf("\n%d! = %d\n", n, fat);
	system("pause");
}