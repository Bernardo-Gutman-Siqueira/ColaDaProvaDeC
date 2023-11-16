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
		mat[i][0] = rand()%100;
	}
	for(i=0; i<n; i++){
		srand(mat[i][0]);
		for(j=1; j<n; j++){
			mat[i][j] = rand()%(mat[i][0] + 1);
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