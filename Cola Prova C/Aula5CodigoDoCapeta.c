// 1) Faça um programa em C que gere pontos aleatórios entre 0 e 1 
// (coordenadas x e y no plano).
// Considere um círculo de raio igual a 1,
// dentro de um quadrado. Conte quantos pontos cairam dentro do círculo e quantos fora.
// Use a probabilidade para calcular a área do círculo, ou seja, 
// quantos porcento dos pontos caíram dentro do círculo.
// Multiplique este valor pela área do quadrado para saber
// a área o círculo que neste caso é Pi.
// Este método é chamado de Método de Monte Carlo e serve para fazer previsões 
// com geração massiva de números aleatórios.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<math.h> // Inclui o cabeçalho da biblioteca de funções matemáticas
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo

// Função principal do programa
int main(){
	int i, qtdPontos, dentro=0, fora=0; // Declaração de variáveis inteiras
	float x, y, hipotenusa; // Declaração de variáveis de ponto flutuante
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	printf("\nQuantos pontos deseja? ");
	scanf("%d", &qtdPontos); // Lê um número inteiro do usuário e armazena na variável qtdPontos
	for(i=0; i<qtdPontos; i++){ // Loop que executa qtdPontos vezes
		x = ((float)rand()/(float)RAND_MAX); // Gera um número aleatório entre 0 e 1 para a coordenada x
		y = ((float)rand()/(float)RAND_MAX); // Gera um número aleatório entre 0 e 1 para a coordenada y
		hipotenusa = sqrt(pow(x, 2.0)+pow(y, 2.0));  // Calcula a hipotenusa (distância do ponto ao centro do círculo)
		if(hipotenusa <= 1){ // Se a hipotenusa é menor ou igual a 1 (o ponto está dentro do círculo)
			dentro++; // Incrementa a contagem de pontos dentro do círculo
		}else{ // Se a hipotenusa é maior que 1 (o ponto está fora do círculo)
			fora++; // Incrementa a contagem de pontos fora do círculo
		}
	}
	printf("\nProbabilidade de pontos dentro do circulo %.2f", 
		(dentro/(float)qtdPontos)); // Imprime a probabilidade de pontos dentro do círculo
	printf("\nProbabilidade de pontos fora do circulo %.2f", 
		(fora/(float)qtdPontos)); // Imprime a probabilidade de pontos fora do círculo
	printf("\nA area aproximada do circulo e %.2f\n",
		(dentro/(float)qtdPontos*4.0)); // Calcula e imprime a área aproximada do círculo usando o método de Monte Carlo (area do quadrado x4)
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
