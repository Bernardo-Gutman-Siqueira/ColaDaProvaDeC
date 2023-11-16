#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>//Inclua esta biblioteca para usar boolean(true or false).
//Define o tamanho da matriz ex:(10x10) e o número de palavras.
#define TAMANHO_MATRIZ 10
#define NUMERO_PALAVRAS 5
//Inicializa o vetor de palavras.
char* palavras[NUMERO_PALAVRAS] = {"mansao", "afluente", "europa", "galaxia", "semente"};
//Inicializa a matriz.
char grade[TAMANHO_MATRIZ][TAMANHO_MATRIZ];
//Limpar o console.
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
/*  Função para embaralhar as palavras.
    Isso garante que a ordem das palavras seja aleatória.*/
void embaralharPalavras() {
    srand(time(NULL));
    for (int i = NUMERO_PALAVRAS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char* temp = palavras[i];
        palavras[i] = palavras[j];
        palavras[j] = temp;
    }
}
/*  Função para inicializar a matriz com espaços vazios.
    Isso prepara a matriz para a colocação de palavras.*/
void inicializarMatriz() {
    for (int i = 0; i < TAMANHO_MATRIZ; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ; j++) {
            grade[i][j] = ' ';
        }
    }
}
/*  Função para imprimir a matriz.
    Isso é usado para visualizar a matriz após as palavras serem
    colocadas e os espaços vazios preenchidos.*/
void imprimirMatriz() {
    for (int i = 0; i < TAMANHO_MATRIZ; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ; j++) {
            printf("%c ", grade[i][j]);
        }
        printf("\n");
    }
}
/*  Função para colocar as palavras na matriz em posições aleatórias.
    Isso garante que cada execução do programa resulte em uma matriz diferente.*/
void colocarPalavras() {
    srand(time(NULL));
    for (int w = 0; w < NUMERO_PALAVRAS; w++) {
        int comprimento = strlen(palavras[w]);
        bool direcao = rand() % 2;
        int linhaInicial, colunaInicial;
        bool podeColocar = false;
        /*  Verifica se a palavra pode ser colocada na posição selecionada.
            Se a posição já contiver uma letra, outra posição será selecionada.
            Isso resolve o bug das palavras com 1 letra trocada.*/
        while (!podeColocar) {
            if (!direcao) {//Horizontal.
                linhaInicial = rand() % TAMANHO_MATRIZ;
                colunaInicial = rand() % (TAMANHO_MATRIZ - comprimento + 1);
                podeColocar = true;
                for (int i = 0; i < comprimento; i++) {
                    if (grade[linhaInicial][colunaInicial + i] != ' ') {
                        podeColocar = false;
                        break;
                    }
                }
            } else {//Vertical.
                linhaInicial = rand() % (TAMANHO_MATRIZ - comprimento + 1);
                colunaInicial = rand() % TAMANHO_MATRIZ;
                podeColocar = true;
                for (int i = 0; i < comprimento; i++) {
                    if (grade[linhaInicial + i][colunaInicial] != ' ') {
                        podeColocar = false;
                        break;
                    }
                }
            }
        }
        //Coloca a palavra na matriz.
        if (!direcao) {//Horizontal.
            for (int i = 0; i < comprimento; i++) {
                grade[linhaInicial][colunaInicial + i] = palavras[w][i];
            }
        } else {//Vertical.
            for (int i = 0; i < comprimento; i++) {
                grade[linhaInicial + i][colunaInicial] = palavras[w][i];
            }
        }
    }
}
/*  Função para preencher os espaços vazios da matriz com letras aleatórias.
    Isso é feito após todas as palavras serem colocadas na matriz.*/
void preencherMatriz() {
    for (int i = 0; i < TAMANHO_MATRIZ; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ; j++) {
            if (grade[i][j] == ' ') {
                grade[i][j] = 'a' + rand() % 26;
            }
        }
    }
}
//Função principal.
int main() {
    char repetir = 's';
    while(repetir == 's' || repetir == 'S') {
    limparTela();
    embaralharPalavras();
    inicializarMatriz();
    colocarPalavras();
    preencherMatriz();
    printf("Encontre 5 palavras:\n\n");
    imprimirMatriz();
    printf("\nEmbaralhar ? (s ou n)\n:");
    scanf(" %c", &repetir);
    int c;//Limpa o buffer de entrada.
    while ((c = getchar()) != '\n' && c != EOF); }
    return 0;
}