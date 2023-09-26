#include <stdio.h>

int main() {
    int i;

    // Exemplo de loop for
    printf("Exemplo de loop for:\n");
    // O loop for é usado quando sabemos o número exato de vezes que queremos iterar.
    // A variável 'i' é inicializada com 0.
    // A condição 'i < 5' é verificada antes de cada iteração. Se a condição for verdadeira, o loop continua; caso contrário, o loop termina.
    // 'i++' incrementa o valor de 'i' em 1 a cada iteração.
    for(i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // Exemplo de loop while
    printf("Exemplo de loop while:\n");
    // O loop while é usado quando queremos que o loop continue até que uma certa condição seja falsa.
    // A variável 'i' é redefinida para 0.
    // A condição 'i < 5' é verificada antes de cada iteração. Se a condição for verdadeira, o loop continua; caso contrário, o loop termina.
    // 'i++' incrementa o valor de 'i' em 1 a cada iteração.
    i = 0;
    while(i < 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n\n");

    // Exemplo de loop do-while
    printf("Exemplo de loop do-while:\n");
    // O loop do-while é semelhante ao loop while, mas a condição é verificada após a execução do bloco de código.
    // Isso significa que o bloco de código será executado pelo menos uma vez, independentemente da condição.
    // A variável 'i' é redefinida para 0.
    // 'i++' incrementa o valor de 'i' em 1 a cada iteração.
    i = 0;
    do {
        printf("%d ", i);
        i++;
    } while(i < 5);

    return 0;
}