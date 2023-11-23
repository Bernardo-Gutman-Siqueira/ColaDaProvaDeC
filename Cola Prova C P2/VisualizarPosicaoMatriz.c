#include<stdio.h>
#include<stdlib.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    limparTela();
	int i, j, n;
	printf("\nMatriz n X n, digite o valor de n.\n:");
	scanf("%d", &n);
    limparTela();
    printf("Matriz %dX%d / n = %d:\n\n", n, n, n);
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            if (0/*Coloque a condição para visualizar X aqui.*/) {
                 printf("XX ");
            } else {
                printf("%d%d ", i, j);
            } 
        }
        printf("\n");
    }
	return 0;
}