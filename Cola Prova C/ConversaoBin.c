#include<stdio.h>

int main() {
    int n, i = 0, bin[100];
    printf("Digite o numero que quer converter:\n");
    scanf("%d",&n);
    while(n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("O numero em binario e: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d",bin[j]);
    }
    return 0;
}
