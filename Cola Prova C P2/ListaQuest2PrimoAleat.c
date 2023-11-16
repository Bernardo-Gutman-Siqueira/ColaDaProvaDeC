#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//Import do boolean.
#include <time.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
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
        printf("Erro ao alocar memoria.\n");
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < n; ) {
        int numero = rand() % 1000 + 1;//Gera aleat entre 1 e 100.
        if (ehPrimo(numero)) {
            bool repetido = false;
            for (int j = 0; j < i; j++) {
                if (vetor[j] == numero) {
                    repetido = true;
                    break;
                }
            }
            if (!repetido) {
                vetor[i] = numero;
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
    limparTela();
    int n;
    printf("Digite o tamanho do vetor.\n:");
    scanf(" %d", &n);
    gerarVetorPrimos(n);
    return 0;
}