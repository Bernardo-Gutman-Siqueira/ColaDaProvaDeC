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

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main(){
	int i, qtdPontos, dentro=0, fora=0;
	float x, y, hipotenusa;
	srand(time(NULL));
	printf("\nQuantos pontos deseja? ");
	scanf("%d", &qtdPontos);
	for(i=0; i<qtdPontos; i++){
		x = ((float)rand()/(float)RAND_MAX); //aleatorio entre 0 e 1
		y = ((float)rand()/(float)RAND_MAX); //aleatorio entre 0 e 1
		hipotenusa = sqrt(pow(x, 2.0)+pow(y, 2.0)); 
		if(hipotenusa <= 1){
			dentro++;
		}else{
			fora++;
		}
	}
	printf("\nProbabilidade de pontos dentro do circulo %.2f", 
		(dentro/(float)qtdPontos));
	printf("\nProbabilidade de pontos fora do circulo %.2f", 
		(fora/(float)qtdPontos));
	printf("\nA area aproximada do circulo e %.2f\n",
		(dentro/(float)qtdPontos*4.0)); //area do quadrado e 4
	return 0;
}