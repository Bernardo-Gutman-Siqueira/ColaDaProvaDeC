// 2) Refaça agora este mesmo programa, só que agora para calcular a área de uma parábola.

#include<stdio.h> // Inclui o cabeçalho da biblioteca padrão de entrada e saída
#include<stdlib.h> // Inclui o cabeçalho da biblioteca padrão de funções gerais
#include<math.h> // Inclui o cabeçalho da biblioteca de funções matemáticas
#include<time.h> // Inclui o cabeçalho da biblioteca de funções de tempo

// Função principal do programa
int main(){
	int i, qtdPontos, dentro=0, fora=0; // Declaração de variáveis inteiras
	float x, y, A, B, C, Delta, X1, X2, aux, Vx, Vy; // Declaração de variáveis de ponto flutuante
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual
	printf("\nQuais os valores de A, B e C? ");
	scanf("%f %f %f", &A, &B, &C); // Lê três números reais do usuário e armazena nas variáveis A, B e C
	Delta = pow(B, 2.0)-4*A*C; // Calcula o discriminante da equação quadrática
	if(Delta < 0){ // Se o discriminante é menor que zero (a equação não possui raízes reais)
		printf("\nFuncao nao possui raiz real\n");
		return -1;
	}
	X1 = (-B + sqrt(Delta))/2.0*A; // Calcula a primeira raiz da equação quadrática
	X2 = (-B - sqrt(Delta))/2.0*A; // Calcula a segunda raiz da equação quadrática
	if(X1 > X2){ // Se X1 é maior que X2 (as raízes estão invertidas), então troca os valores de X1 e X2
		aux = X1;
		X1 = X2;
		X2 = aux;
	}
	printf("\nAs raizes da equacao sao %.2f e %.2f\n", X1, X2); // Imprime as raízes da equação quadrática
	Vx = -B/2.0*A; // Calcula a coordenada x do vértice da parábola
	Vy = -Delta/4.0*A; // Calcula a coordenada y do vértice da parábola
	printf("\nO vertice esta na posicao (x, y) = (%.2f, %.2f)\n", Vx, Vy); // Imprime as coordenadas do vértice da parábola
	printf("\nQuantos pontos deseja? ");
	scanf("%d", &qtdPontos); // Lê um número inteiro do usuário e armazena na variável qtdPontos
	float y_daFuncao;
	for(i=0; i<qtdPontos; i++){ // Loop que executa qtdPontos vezes
		x = ((float)rand()/(float)RAND_MAX)*(X2-X1)+X1; // Gera um número aleatório entre X1 e X2 para a coordenada x
		y = ((float)rand()/(float)RAND_MAX)*(Vy); // Gera um número aleatório entre 0 e Vy para a coordenada y
		y_daFuncao = A*pow(x,2.0)+B*x+C; // Calcula o valor real de y para a coordenada x gerada aleatoriamente
		if(y > y_daFuncao && Vy < 0){ // Se y é maior que y_daFuncao e Vy é menor que 0 (a parábola tem concavidade para cima)
			dentro++; // Incrementa a contagem de pontos dentro da parábola
		}
		if(y < y_daFuncao && Vy > 0){ // Se y é menor que y_daFuncao e Vy é maior que 0 (a parábola tem concavidade para baixo)
			dentro++; // Incrementa a contagem de pontos dentro da parábola
		}
	}
	float areaAprox = ((float)dentro)/((float)qtdPontos)*(X2-X1)*Vy; 
	// Calcula a área aproximada sob a parábola.
	//A área é calculada como a proporção de pontos que caíram dentro da parábola (dentro/qtdPontos)
	//multiplicada pela área do retângulo que contém a parábola ((X2-X1)*Vy).
    printf("\nA area aproximada e de %.2f\n", areaAprox); // Imprime a área aproximada sob a parábola.
    return 0; // Retorna 0 indicando que o programa terminou com sucesso.
}
