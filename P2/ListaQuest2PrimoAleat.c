#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//Função para verificar se um número é primo.
bool ehPrimo(int num) {
    if (num <= 1) return false;
    if (num % 2 == 0 && num > 2) return false;
    for(int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}
//Função para gerar um vetor de números primos aleatórios.
void gerarVetorPrimos(int n) {
    int* vetor = malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < n; ) {
        int num = rand() % 100 + 1;//Gera um número aleatório entre 1 e 100.
        if (ehPrimo(num)) {
            bool repetido = false;
            for (int j = 0; j < i; j++) {
                if (vetor[j] == num) {
                    repetido = true;
                    break;
                }
            }
            if (!repetido) {
                vetor[i] = num;
                i++;
            }
        }
    }
    //Imprime o vetor.
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    gerarVetorPrimos(n);
    return 0;
}