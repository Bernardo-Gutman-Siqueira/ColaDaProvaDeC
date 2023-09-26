#include<stdio.h>
#include<stdlib.h>
#include<time.h> //cabecalho de funcoes de tempo

int main(){ //metodo principal
	srand(time(NULL)); //corrigindo o problema de geracao igual de numeros
	int  aleatorio, erros, chute, recorde=100, continuar=1;
	while(continuar == 1){
		aleatorio = 1+rand()%100; //gero um numero entre 1 e 100
		erros = 0;
		chute = -1;
		while(aleatorio != chute){ //enquanto não acertar o chute
			printf("\nDigite um numero ");
			scanf("%d", &chute);
			if(chute != aleatorio){
				erros++; //variavel erros e incrementada de 1
				if(chute > aleatorio){ //errei para mais
					printf("\nVc errou\nO numero e menor");
				}else{ //errei para menos
					printf("\nVc errou\nO numero e maior");
				}
			}else{
				if(erros < recorde){
					recorde = erros;
					printf("\nParabens\nVc bateu seu recorde\n");
				}
				printf("\nVc acertou o numero %d", aleatorio);
				printf("\nErrou %d vezes\nSeu recorde eh %d\n", erros, recorde);
			}
		}
		printf("\nDeseja continuar?\t0 - Nao\t1 - Sim ");
		scanf("%d", &continuar);
	}
}