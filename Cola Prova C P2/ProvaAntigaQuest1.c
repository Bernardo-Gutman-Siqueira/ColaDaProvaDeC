#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*Faça um programa em C que peça para o usuário digitar dois números inteiros,
o primeiro número será para criar um vetor aleatório com números entre 0 e 100,
sem repetição.
O segundo será a quantidade de números aleatórios a serem gerados entre 0 e 1000.
Ao final seu programa deverá dizer quantas vezes cada número do primeiro vetor saíram.*/
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int i, j, qtdNumAleat, qtdNumNoVetor, aleat; // Declaração de variáveis
	printf("\nQuantos numeros no vetor? "); // Solicita ao usuário a quantidade de números no vetor
	scanf("%d", &qtdNumNoVetor); // Lê a quantidade de números no vetor
	printf("\nQuantos numeros aleatorios? "); // Solicita ao usuário a quantidade de números aleatórios
	scanf("%d", &qtdNumAleat); // Lê a quantidade de números aleatórios
	int vet[qtdNumNoVetor][2]; // Declaração de um vetor bidimensional
	// Inicializa o vetor e gera números aleatórios
	for(i=0; i<qtdNumNoVetor; i++){
		vet[i][0] = rand()%101; // Gera um número aleatório entre 0 e 100
		vet[i][1] = 0; // Inicializa a contagem de vezes que o número saiu
		// Verifica se o número já existe no vetor
		for(j=i-1; j>=0; j--){
			if(vet[i][0] == vet[j][0]){ // Se o número já existe no vetor
				i--; // Decrementa i e gera o número novamente
			}
		}
	}
	// Gera números aleatórios e incrementa a contagem correspondente no vetor
	for(i=0; i<qtdNumAleat; i++){
		aleat = rand()%101; // Gera um número aleatório entre 0 e 100
		for(j=0; j<qtdNumNoVetor; j++){
			if(vet[j][0] == aleat){ // Se o número existe no vetor
				vet[j][1]++; // Incrementa a contagem de vezes que o número saiu
			}
		}
	}
	// Imprime a contagem de vezes que cada número saiu
	for(j=0; j<qtdNumNoVetor; j++){
		printf("O numero %d saiu %d vezes\n", vet[j][0], vet[j][1]);
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}