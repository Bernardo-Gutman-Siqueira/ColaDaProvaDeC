/*05. Escreve um programa que sorteio, aleatoriamente,
10 números e armazene estes em um vetor.
Em seguida, o usuário digita um número e seu programa em C deve 
acusar se o número digitado está no vetor ou não. Se estiver, 
diga a posição que está.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    srand(time(NULL));
    int vetor[MAX], i, num, posicao = -1;
    //Sorteia 100 números aleatórios e armazena no vetor.
    for(i = 0; i < MAX; i++) {
        vetor[i] = rand() % 100;
        //printf("%d ", vetor[i]);
    }
    //Solicita ao usuário para digitar um número.
    printf("\nDigite um numero ate 99: ");
    scanf("%d", &num);
    //Verifica se o número digitado está no vetor.
    for(i = 0; i < MAX; i++) {
        if(vetor[i] == num) {
            posicao = i;
            break;
        }
    }
    //Se o número estiver no vetor, imprime a posição.
    if(posicao != -1) {
        printf("O numero %d esta na posicao %d do vetor.\n", num, posicao);
    } else {
        printf("O numero %d nao foi encontrado no vetor.\n", num);
    }
    return 0;
}
