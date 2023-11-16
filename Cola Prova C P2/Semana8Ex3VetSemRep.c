#include<stdio.h> // Inclui o arquivo de cabeçalho para funções de entrada e saída
#include<stdlib.h> // Inclui o arquivo de cabeçalho para funções gerais
#include<math.h> // Inclui o arquivo de cabeçalho para funções matemáticas
#include<time.h> // Inclui o arquivo de cabeçalho para funções de tempo
//3) Modifique o exercício para gerar um vetor sem repetição.
int main(){
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    int i, j, n, aux; // Declaração de variáveis
    printf("\nQuantos numeros no vetor? "); // Solicita ao usuário o tamanho do vetor
    scanf("%d", &n); // Lê o tamanho do vetor
    int vet[n]; // Declaração de vetor de tamanho n
    // Preenche o vetor com números aleatórios sem repetição
    for(i=0; i<n; i++){
        vet[i] = rand()%n; // Gera um número aleatório
        // Verifica se o número já existe no vetor
        for(j=i-1; j>=0; j--){
            if(vet[i] == vet[j]){ // Se o número já existe no vetor
                i--; // Decrementa i e sorteia a posição novamente
            }
        }
    }
    // Imprime os valores do vetor
    printf("\nOs valores do vetor sao:\n");
    for(i=0; i<n; i++){
        printf("%d\n", vet[i]);
    }
    // Ordena o vetor em ordem crescente
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(vet[i] > vet[j]){ // Se os números estão trocados
                aux = vet[i]; // Troca os números de lugar
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    // Imprime os valores do vetor ordenado
    printf("\nOs valores do vetor ordenado sao:\n");
    for(i=0; i<n; i++){
        printf("%d\n", vet[i]);
    }
    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
