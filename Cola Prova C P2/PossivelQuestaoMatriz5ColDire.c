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
		mat[i][n-1] = rand()%100;
	}
	for(i=0; i<n; i++){
		srand(mat[i][n-1]);
		for(j=0; j<n-1; j++){
			mat[i][j] = rand()%(mat[i][n-1] + 1);
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
