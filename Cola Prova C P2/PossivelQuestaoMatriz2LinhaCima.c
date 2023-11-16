#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Nesse exemplo a primeira linha serve de seed para todos os numeros da coluna.
int main(){
	int i, j, n;
	srand(time(NULL));
	printf("\nQual a dimensao da matriz? ");
	scanf("%d", &n);
	int mat[n][n];
	for(j=0; j<n; j++){
		mat[0][j] = rand()%100;
	}
	for(i=1; i<n; i++){
		for(j=0; j<n; j++){
			mat[i][j] = rand()%(mat[0][j]+1);
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

