#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*1) Faça um programa que simule a probabilidade de números aleatórios 
criando um vetor de 100 posições e gerando n aleatórios.
Teste para n pequeno e vá aumentando a quantidade de números até que 
cada número tenha saído aproximadamente 1% da vezes.*/
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

	int i, n, aleat, vet[100]; // Declaração de variáveis

	printf("\nQuantos numeros deseja? "); // Solicita ao usuário a quantidade de números
	scanf("%d",&n); // Lê a quantidade de números

	// Inicializa o vetor com zeros
	for(i=0; i<100; i++){
		vet[i] = 0;
	}

	// Gera n números aleatórios e incrementa a contagem correspondente no vetor
	for(i=0; i<n; i++){
		aleat = rand()%100; // Gera um número aleatório entre 0 e 99
		vet[aleat]++; // Incrementa a contagem do número gerado
	}

	// Imprime a contagem de cada número e a porcentagem correspondente
	for(i=0; i<100; i++){
		printf("\nO numero %5d saiu %5d vezes\t%.2f%%",
			i, vet[i], ((float)vet[i]/(float)n)*100.0); // Imprime o número, a contagem e a porcentagem
	}

	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
