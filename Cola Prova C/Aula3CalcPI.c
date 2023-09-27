// 4) Faça um programa para calcular o valor de Pi de uma série alternada
// (1 - 1/3 + 1/5 - 1/7  + ... = Pi/4)

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<math.h> // Inclui o cabeçalho da biblioteca de funções matemáticas
//Calculo de Pi por serie
// Função principal do programa
int main(){
	int i, n; // Declaração de variáveis inteiras
	float pi=0, denominador=1, sinal=1; // Declaração de variáveis de ponto flutuante
	printf("\nQual a quantidade de parcelas da serie? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		pi = pi + (1.0/denominador)*sinal;  // Calcula a soma da série alternada
		sinal*=-1; // Sinal = sinal * -1;
		denominador = denominador + 2; // Incrementa o denominador em 2 para a próxima iteração
	}
	printf("\nO valor de pi eh %.10f\n", pi*4.0); // Imprime o valor calculado de Pi
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
