/*Faça um programa que gere uma matriz n x n (n lido pelo usuário)
com números aleatórios dispostos
na matriz da seguinte maneira para um n = 6:
Repare que as diagonais principal e secundária possuem zeros,
todas as demais posições da matriz possuem aleatórios diferentes de 0.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int i, j, n;
    srand(time(NULL));
	printf("\nQual a dimensao da matriz? ");
	scanf("%d", &n);
	int mat[n][n];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i == j || i+j == n-1){ // Se estamos na diagonal principal ou secundária
				mat[i][j] = 0;
			}else{
				mat[i][j] = rand()%100 + 1; // Gera um número aleatório entre 1 e 100
			}
		}
	}
	printf("\nMATRIZ\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n\n");
	}
	return 0;
}