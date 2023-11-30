#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int i, j, n;
	srand(time(NULL));
	printf("\nQual a dimensao da matriz? ");
	scanf("%d", &n);
	int mat[n][n];
	for(i=0; i<n; i++){
		mat[i][n-i-1] = n;
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i == n-j-1){
				mat[i][j] = n;
 		    } else if(i == n-j) {
 		        mat[i][j] = n+1;
 		     } else if(i == n-j+1) {
 		        mat[i][j] = n+2;
 		     } 
 		     else if(i == n-j-2) {
 		        mat[i][j] = n-1;
 		     } else if(i == n-j-3) {
 		        mat[i][j] = n-2;
 		     } 
 		     else {
 		        mat[i][j] = 0;
 		    }
		}
	}
	printf("\nMATRIZ %dx%d\n", n, n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n\n");
	}
	return 0;
}