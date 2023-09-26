// 3) Faça um programa que gere n números aleatórios 
// entre A e B (dados passados pelo usuário), 
// após isso diga o maior e o menor números gerados, 

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
//gerando aleatorios reais entre A e B com calculo da media
main(){
	srand(time(NULL));
	float A, B, media, soma=0, menor, maior, aux, aleat;
	int i, n;
	printf("\nQual o valor inferior? ");
	scanf("%f", &A);
	printf("\nQual o valor superior? ");
	scanf("%f", &B);
	if(A > B){ //o usuario digitou invertido, entao vamos trocar
		aux = A;
		A = B;
		B = aux;
	}
	maior = A; //maior recebe o menor valor que pode ser gerado
	menor = B; //menor recebe o maior valor que pode ser gerado
	printf("\nQuantos numeros deseja? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		aleat = ((float)rand()/(float)RAND_MAX)*(B-A)+A;
		soma+=aleat; //somando os valores gerados
		if(aleat > maior){
			maior = aleat; //o valor é maior que o anterior
		}
		if(aleat < menor){
			menor = aleat; // o valor é menor que o anterior
		}
		printf("\n%20.5f", aleat);
	}
	media = soma / (float)n;
	printf("\n\nO maior valor gerado foi %.10f\n", maior);
	printf("\n\nO menor valor gerado foi %.10f\n", menor);
	printf("\nA media de numeros gerados foi %.10f\n\n", media);
}