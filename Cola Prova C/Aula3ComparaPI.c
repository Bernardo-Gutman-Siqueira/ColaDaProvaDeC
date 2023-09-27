// 5) Compare o erro do valor obtido do exercício anterior 
// com a variável de ambiente do C (M_PI) do cabeçalho math.h

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
		sinal*=-1; // Alterna o sinal para a próxima iteração
		denominador = denominador + 2; // Incrementa o denominador em 2 para a próxima iteração
	}
	pi*=4.0;  // Multiplica o valor calculado por 4 para obter uma aproximação de Pi
	printf("\nO valor de pi eh \t\t%.20f", pi); // Imprime o valor calculado de Pi
	printf("\nO valor real de pi eh \t\t%.20f", M_PI); // Imprime o valor real de Pi definido na biblioteca math.h
	printf("\nO erro do calculo foi de \t%.20f\n", (pi-M_PI)); // Calcula e imprime a diferença entre o valor calculado e o valor real de Pi
	return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
