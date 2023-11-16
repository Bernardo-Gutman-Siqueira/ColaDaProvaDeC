#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//2) Modifique o exercício anterior e ordene o vetor aleatório
int main(){
	srand(time(NULL));
	int i, j, n, aux;
	printf("\nQuantos numeros no vetor? ");
	scanf("%d", &n);
	int vet[n]; // declaracao de vetor de tamanho n
	for(i=0; i<n; i++){
		vet[i] = rand()%100;
	}
	printf("\nOs valores do vetor sao:\n");
	for(i=0; i<n; i++){
		printf("%d\n", vet[i]);
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(vet[i] > vet[j]){ //estao trocados
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	printf("\nOs valores do vetor ordenado sao:\n");
	for(i=0; i<n; i++){
		printf("%d\n", vet[i]);
	}
	return 0;
}