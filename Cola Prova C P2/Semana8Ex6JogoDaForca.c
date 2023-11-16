#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
//6) Crie um programa que simule o jogo da forca
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
	int i, qtdLetras, acertos=0, erros=0, acertei;
	char palavra[20], oculta[20], letra, lixo;
	printf("\nQual a palavra? ");
	scanf("%s", palavra);
	qtdLetras = strlen(palavra); //retorna o tamanho da palavra digitada
	for(i=0; i<qtdLetras; i++){
		oculta[i] = '_';
	}
	limparTela();//limpa a tela no windows e no Linux respectivamente
	while(acertos < qtdLetras && erros < 5){
		limparTela();
		for(i=0; i<qtdLetras; i++){
			printf("%c ", oculta[i]);
		}
		printf("\nQual a letra deseja chutar? ");
		scanf("%c", &lixo); //le e descarta o enter
		scanf("%c", &letra);
		acertei = 0;
		for(i=0; i<qtdLetras; i++){
			if(palavra[i] == letra){ //acertou uma letra
				oculta[i] = letra;
				acertos++;
				acertei = 1; 
			}
		}
		if(acertei == 0){ //nao existia a letra na palavra
			erros++;
		}
	}
	printf("\nVc errou %d letras da palavra %s\n\n", erros, palavra);
	return 0;
}