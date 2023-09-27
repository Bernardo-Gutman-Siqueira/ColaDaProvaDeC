#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo

int main(){ // Função principal do programa
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	int  aleatorio, erros, chute, recorde=100, continuar=1; // Declaração de variáveis inteiras
	while(continuar == 1){ // Loop que executa enquanto o usuário deseja continuar
		aleatorio = 1+rand()%100; // Gera um número aleatório entre 1 e 100
		erros = 0; // Inicializa a contagem de erros
		chute = -1; // Inicializa a variável chute
		while(aleatorio != chute){ // Loop que executa enquanto o usuário não acertar o número
			printf("\nDigite um numero ");
			scanf("%d", &chute); // Lê um número inteiro do usuário e armazena na variável chute
			if(chute != aleatorio){ // Se o usuário não acertou o número
				erros++; // Incrementa a contagem de erros
				if(chute > aleatorio){ // Se o usuário chutou um número maior que o número aleatório
					printf("\nVc errou\nO numero e menor");
				}else{ // Se o usuário chutou um número menor que o número aleatório
					printf("\nVc errou\nO numero e maior");
				}
			}else{ // Se o usuário acertou o número
				if(erros < recorde){ // Se a contagem de erros é menor que o recorde atual
					recorde = erros; // Atualiza o recorde com a contagem atual de erros
					printf("\nParabens\nVc bateu seu recorde\n");
				}
				printf("\nVc acertou o numero %d", aleatorio);
				printf("\nErrou %d vezes\nSeu recorde eh %d\n", erros, recorde);
			}
		}
		printf("\nDeseja continuar?\t0 - Nao\t1 - Sim ");
		scanf("%d", &continuar); // Lê a escolha do usuário se deseja continuar ou não e armazena na variável continuar
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
