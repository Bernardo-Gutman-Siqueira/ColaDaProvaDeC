#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho, opcao, i;
    int *vetor;

    /* Solicita ao usuário o tamanho do vetor */
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    /* Aloca memória para o vetor */
    vetor = (int *)malloc(tamanho * sizeof(int));

    /* Solicita ao usuário onde os zeros devem ser colocados */
    printf("Digite 1 para colocar os zeros na primeira metade ou 2 para a segunda metade: ");
    scanf("%d", &opcao);

    /* Inicializa o gerador de números aleatórios */
    srand(time(NULL));

    if (opcao == 1) {
        /* Preenche a primeira metade do vetor com zeros */
        for (i = 0; i < tamanho / 2; i++) {
            vetor[i] = 0;
        }

        /* Preenche a segunda metade do vetor com números aleatórios */
        for (i = tamanho / 2; i < tamanho; i++) {
            vetor[i] = rand() % 100;  /* Gera um número aleatório entre 0 e 99 */
        }
    } else {
        /* Preenche a primeira metade do vetor com números aleatórios */
        for (i = 0; i < tamanho / 2; i++) {
            vetor[i] = rand() % 100;  /* Gera um número aleatório entre 0 e 99 */
        }

        /* Preenche a segunda metade do vetor com zeros */
        for (i = tamanho / 2; i < tamanho; i++) {
            vetor[i] = 0;
        }
    }

    /* Imprime o vetor */
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    /* Libera a memória alocada para o vetor */
    free(vetor);

    return 0;
}

