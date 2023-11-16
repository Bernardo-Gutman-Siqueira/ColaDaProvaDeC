#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//1) Faça um vetor de números aleatórios.
int main(){
	srand(time(NULL));
	int i, n;
	printf("\nQuantos numeros no vetor? ");
	scanf("%d", &n);
	int vet[n]; // declaracao de vetor de tamanho n
	for(i=0; i<n; i++){
		vet[i] = rand()%100;
	}
	printf("\nOs valores do vetor sao:\n");
	for(i=0; i<n; i++){
		printf("Posicao %d = %d\n", i, vet[i]);
	}
	return 0;
}