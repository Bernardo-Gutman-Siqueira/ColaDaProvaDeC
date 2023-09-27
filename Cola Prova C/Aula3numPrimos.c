// 3) Faça um programa para apresentar os n primeiros números primos.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<math.h> // Inclui o cabeçalho da biblioteca de funções matemáticas
//Numeros Primos
// Função principal do programa
int main(){
	int i, j, ehPrimo, qtd; // Declaração de variáveis inteiras
	printf("\nQuantos numeros primos? ");
	scanf("%d", &qtd); // Lê um número inteiro do usuário e armazena na variável qtd
	for(i=1; i<=qtd; i++){ // Loop que executa qtd vezes
		ehPrimo = 1; // Considero que todo numero eh primo ate prova contraria
		for(j=sqrt(i); j>1; j--){ // Loop que executa da raiz quadrada de i até 2
			if(i%j == 0){ // Se o resto da divisão de i por j for 0
				ehPrimo = 0; // O número não é primo
			}
		}
		if(ehPrimo == 1){ // Se o número é primo
			printf("%d eh Primo\n", i); // Imprime que o número é primo
		}else{
			qtd++; // Testa mais um número
		}
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
