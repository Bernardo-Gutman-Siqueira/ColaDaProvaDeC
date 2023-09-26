// 5) Compare o erro do valor obtido do exercício anterior 
// com a variável de ambiente do C (M_PI) do cabeçalho math.h

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Calculo de Pi por serie
int main(){
	int i, n;
	float pi=0, denominador=1, sinal=1;
	printf("\nQual a quantidade de parcelas da serie? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		pi = pi + (1.0/denominador)*sinal; 
		sinal*=-1; //sinal = sinal * -1;
		denominador = denominador + 2;
	}
	pi*=4.0; 
	printf("\nO valor de pi eh \t\t%.20f", pi);
	printf("\nO valor real de pi eh \t\t%.20f", M_PI);
	printf("\nO erro do calculo foi de \t%.20f\n", (pi-M_PI));
}