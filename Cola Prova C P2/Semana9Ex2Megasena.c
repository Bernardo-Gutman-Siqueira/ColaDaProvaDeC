#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*2) Faça um programa que simule um jogo da megasena.
O jogador deverá escolher entre 6 e 15 números e o programa irá 
sortear jogos aleatórios com 6 números até que o jogador tenha ganhado uma sena.
Mostre ao final quantos sorteios ocorreram até ganhar.
Apresente também a quantidade de quinas e quadras que
o jogador ganhou durante este tempo.*/
int main() {
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int i, j, jogo[15], sena[6], qtdNum, quinas=0, quadras=0, acertos, qtdsorteios=0; // Declaração de variáveis
	printf("\nQuantos numeros deseja jogar? "); // Solicita ao usuário a quantidade de números
	scanf("%d", &qtdNum); // Lê a quantidade de números
	// Lê os números do jogo
	for(i=0; i<qtdNum; i++){
		printf("\nQual o %d° numero? ", (i+1));
		scanf("%d", &jogo[i]);
	}
	do{
		acertos = 0;
		// Gera o sorteio da megasena
		for(i=0; i<6; i++){
			sena[i] = 1+rand()%60; // Gera um número aleatório entre 1 e 60
			for(j=i-1; j>=0; j--){
				if(sena[i] == sena[j]){ // Se este número já saiu
					i--; // Decrementa i e sorteia o número novamente
				}
			}
		}
		// Verifica quantos números do jogo foram sorteados
		for(i=0; i<qtdNum; i++){
			for(j=0; j<6; j++){
				if(jogo[i] == sena[j]){
					acertos++; // Incrementa a contagem de acertos
				}
			}
		} // Ao final, temos a quantidade de números acertados
		if(acertos == 5){ // Se acertou uma quina
			quinas++;
		}
		if(acertos == 4){ // Se acertou uma quadra
			quadras++;
		}
		qtdsorteios++;
	}while(acertos < 6); // Continua até acertar a sena
	printf("\nAcertei a sena apos %d sorteios\n",qtdsorteios);
	printf("\nNeste tempo foram %d quinas e %d quadras\n\n", quinas, quadras);
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}

