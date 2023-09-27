// 3) Faça um programa que gere n números aleatórios 
// entre A e B (dados passados pelo usuário), 
// após isso diga o maior e o menor números gerados, 

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais

// Função principal do programa
//gerando aleatorios reais entre A e B com calculo da media
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	float A, B, media, soma=0, menor, maior, aux, aleat; // Declaração de variáveis de ponto flutuante
	int i, n; // Declaração de variáveis inteiras
	printf("\nQual o valor inferior? ");
	scanf("%f", &A); // Lê um número real do usuário e armazena na variável A
	printf("\nQual o valor superior? ");
	scanf("%f", &B); // Lê um número real do usuário e armazena na variável B
	if(A > B){ // Se o usuário digitou os valores invertidos, então troca os valores de A e B
		aux = A;
		A = B;
		B = aux;
	}
	maior = A; // O maior recebe o menor valor que pode ser gerado
	menor = B; // O menor recebe o maior valor que pode ser gerado
	printf("\nQuantos numeros deseja? ");
	scanf("%d", &n); // Lê um número inteiro do usuário e armazena na variável n
	for(i=0; i<n; i++){ // Loop que executa n vezes
		aleat = ((float)rand()/(float)RAND_MAX)*(B-A)+A; // Gera um número aleatório entre A e B
		soma+=aleat; // Soma os valores gerados
		if(aleat > maior){
			maior = aleat; // O valor é maior que o anterior
		}
		if(aleat < menor){
			menor = aleat; // O valor é menor que o anterior
		}
		printf("\n%20.5f", aleat); // Imprime o número aleatório gerado
	}
	media = soma / (float)n; // Calcula a média dos números gerados
	printf("\n\nO maior valor gerado foi %.10f\n", maior); // Imprime o maior valor gerado
	printf("\n\nO menor valor gerado foi %.10f\n", menor); // Imprime o menor valor gerado
	printf("\nA media de numeros gerados foi %.10f\n\n", media); // Imprime a média dos números gerados
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
