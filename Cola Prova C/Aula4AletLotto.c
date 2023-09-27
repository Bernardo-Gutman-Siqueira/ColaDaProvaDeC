// 6) Faça um programa que peça ao usuário 3 números inteiros 
// e gere indeterminados números até que os 3 digitados tenham saído pelo menos uma vez.
// Diga quantos sorteios foram feitos até os 3 saírem e quantas vezes cada um saiu.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais

// Função principal do programa
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	int N1, N2, N3, aleat, qtdN1=0, qtdN2=0, qtdN3=0, qtd=0; // Declaração de variáveis inteiras
	printf("\nQuais os 3 numeros entre 0 e 99? ");
	scanf("%d %d %d", &N1, &N2, &N3); // Lê três números inteiros do usuário e armazena nas variáveis N1, N2 e N3
	while(qtdN1 == 0 || qtdN2 == 0 || qtdN3 == 0){ // Loop que executa enquanto qualquer um dos números não tenha sido gerado pelo menos uma vez
		aleat = rand()%100; // Gera um número aleatório entre 0 e 99
		qtd++; // Incrementa a contagem total de números gerados
		if(aleat == N1){ // Se o número gerado é igual a N1
			qtdN1++; // Incrementa a contagem de vezes que N1 foi gerado
		}
		if(aleat == N2){ // Se o número gerado é igual a N2
			qtdN2++; // Incrementa a contagem de vezes que N2 foi gerado
		}
		if(aleat == N3){ // Se o número gerado é igual a N3
			qtdN3++; // Incrementa a contagem de vezes que N3 foi gerado
		}
	}
	printf("\nForam gerados %d numeros", qtd); // Imprime a quantidade total de números gerados
	printf("\nO numero %d saiu %d vezes", N1, qtdN1); // Imprime quantas vezes o número N1 foi gerado
	printf("\nO numero %d saiu %d vezes", N2, qtdN2); // Imprime quantas vezes o número N2 foi gerado
	printf("\nO numero %d saiu %d vezes\n", N3, qtdN3); // Imprime quantas vezes o número N3 foi gerado
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
