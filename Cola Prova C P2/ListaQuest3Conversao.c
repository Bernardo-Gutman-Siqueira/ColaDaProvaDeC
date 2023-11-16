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
    int numero, escolha;
	char repetir = 's';
    while(repetir == 's' || repetir == 'S') {
		limparTela();
		printf("Qual numero quer converter ?\n:");
        scanf(" %d", &numero);
		limparTela();
        printf("Converter numero %d para qual base ?\n1-Binario\n2-Octal\n3-Decimal\n4-Hexadecimal\n\n:", numero);
        scanf(" %d", &escolha);
		limparTela();
        switch(escolha) {
            case 1:
                printf("O numero %d em binario eh: ", numero);
                for(int i = 31; i >= 0; i--){
                    int k = numero >> i;
                    if(k & 1)
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n");
                break;
            case 2:
                printf("O numero %d em octal eh: %o\n", numero, numero);
                break;
            case 3:
                printf("O numero %d em decimal eh: %d\n", numero, numero);
                break;
            case 4:
                printf("O numero %d em hexadecimal eh: %X\n", numero, numero);
                break;
            default:
                printf("Escolha invalida!!!\n");
        }
        printf("\nDeseja repetir ? (s ou n)\n:");
        scanf(" %c",&repetir);
    }
    return 0;
}