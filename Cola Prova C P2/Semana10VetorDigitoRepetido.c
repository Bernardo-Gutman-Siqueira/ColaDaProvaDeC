#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
// Função principal do programa
int main(){
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int i, j, aleat, tmp, resto, vet[10], n, temDigitosRepetidos; // Declaração de variáveis
	printf("\nQuantos numeros deseja? "); // Solicita ao usuário a quantidade de números
	scanf("%d", &n); // Lê a quantidade de números
	for(i=0; i<n; i++){ // Gera n números aleatórios
		aleat = rand()%100000; // Gera um número aleatório entre 0 e 99999
		tmp = aleat; // Armazena o número aleatório em uma variável temporária
		// Inicializa o vetor com zeros
		for(j=0; j<10; j++){
			vet[j] = 0;
		}
		temDigitosRepetidos = 0; // Inicializa a variável que indica se o número tem dígitos repetidos
		// Verifica se o número tem dígitos repetidos
		while(tmp > 0){
			resto = tmp%10; // Pega o último dígito do número
			vet[resto]++; // Incrementa a contagem do dígito
			// Se o dígito aparece mais de uma vez no número
			if(vet[resto] > 1){
				temDigitosRepetidos = 1; // Indica que o número tem dígitos repetidos
			}
			tmp = tmp/10; // Descarta o último dígito do número
		}
		// Se o número tem dígitos repetidos
		if(temDigitosRepetidos == 1){
			printf("%d\n", aleat); // Imprime o número
		}
	}
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
