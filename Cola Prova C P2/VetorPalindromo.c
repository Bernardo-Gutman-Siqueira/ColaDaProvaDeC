/*criar um programa que checa se o número é palíndromo
Número palíndromo é aquele que, se lido de trás para frente e de frete para trás,
é o mesmo. Exemplos: 2112, 666, 2442 etc*/

#include <stdio.h>

int ehPalindromo(int num) {
    int reverso = 0, temp, resto;
    temp = num;
    //Reverte o número.
    while(temp != 0) {
        resto = temp % 10;
        reverso = reverso * 10 + resto;
        temp /= 10;
    }
    //Verifica se o número é palíndromo.
    if(reverso == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(ehPalindromo(num)) {
        printf("%d eh um numero palindromo.\n", num);
    } else {
        printf("%d nao eh um numero palindromo.\n", num);
    }
    return 0;
}