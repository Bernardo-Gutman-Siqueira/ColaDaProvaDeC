// 5) Faça um programa que gere n, aleatórias, placas de veículos no padrão mercosul.

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
//gerando placas mercosul aleatorias
main(){
	srand(time(NULL));
	int i, n;
	float aleat;
	printf("\nQuantas placas deseja? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("%c", 65+rand()%23);
		printf("%c", 65+rand()%23);
		printf("%c - ", 65+rand()%23);
		printf("%d", rand()%10);
		printf("%c", 65+rand()%23);
		printf("%d", rand()%10);
		printf("%d\n", rand()%10);
	}
}