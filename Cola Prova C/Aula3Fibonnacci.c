// 2) Faça um programa para imprimir os n números da série de Fibonnacci 
// (1 1 2 3 5 8 13 21 34 ...)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Serie de Fibonacci
int main(){
	int n, i, A=0, B=1, C=1;
	printf("\nQuantos termos? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("%d\n", C);
		C=A+B;
		A=B;
		B=C;
	}
	printf("\n\n");
}