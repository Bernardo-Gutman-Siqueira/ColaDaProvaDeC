// 2) Refaça agora este mesmo programa, só que agora para calcular a área de uma parábola.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main(){
	int i, qtdPontos, dentro=0, fora=0;
	float x, y, A, B, C, Delta, X1, X2, aux, Vx, Vy;
	srand(time(NULL));
	printf("\nQuais os valores de A, B e C? ");
	scanf("%f %f %f", &A, &B, &C);
	Delta = pow(B, 2.0)-4*A*C;
	if(Delta < 0){
		printf("\nFuncao nao possui raiz real\n");
		return -1;
	}
	X1 = (-B + sqrt(Delta))/2.0*A;
	X2 = (-B - sqrt(Delta))/2.0*A;
	if(X1 > X2){ //X1 tem que ser sempre menor
		aux = X1;
		X1 = X2;
		X2 = aux;
	}
	printf("\nAs raizes da equacao sao %.2f e %.2f\n", X1, X2);
	Vx = -B/2.0*A; //vertice X
	Vy = -Delta/4.0*A; //vertice Y
	printf("\nO vertice esta na posicao (x, y) = (%.2f, %.2f)\n", Vx, Vy);
	printf("\nQuantos pontos deseja? ");
	scanf("%d", &qtdPontos);
	float y_daFuncao;
	for(i=0; i<qtdPontos; i++){
		x = ((float)rand()/(float)RAND_MAX)*(X2-X1)+X1;
		y = ((float)rand()/(float)RAND_MAX)*(Vy);
		y_daFuncao = A*pow(x,2.0)+B*x+C; //real do ponto y com x aleatorio
		if(y > y_daFuncao && Vy < 0){ // parabola concavidade pra cima
			dentro++;
		}
		if(y < y_daFuncao && Vy > 0){ //parabola concavidade pra baixo
			dentro++;
		}
	}
	float areaAprox = ((float)dentro)/((float)qtdPontos)*(X2-X1)*Vy;
	printf("\nA area aproximada e de %.2f\n", areaAprox);
}