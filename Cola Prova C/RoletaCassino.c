#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limparTela() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    srand(time(NULL));
    limparTela();
    char resp, cor = 'j', dificuldade = 'b';
    int saldo = 9999, aposta, nn1, nnA, nCor;
    while(dificuldade != 'f' && dificuldade != 'F' && dificuldade != 'm' && dificuldade != 'M' && dificuldade!= 'd' && dificuldade != 'D') {
        printf("Simulador de roleta.\nNumeros pagam 35 para 1.\nPreto e Vermelho paga 1 para 1.\nO objetivo eh fazer 10000.\n\n");
        printf("Escolha uma dificuldade: Facil(f), Medio(m) ou Dificil(d)\n:");
        scanf(" %c", &dificuldade);
        limparTela();
        if(dificuldade== 'f' || dificuldade == 'F'){
            saldo = 4200;
        } else if(dificuldade == 'm' || dificuldade == 'M'){
            saldo = 2500;
        } else if(dificuldade == 'd' || dificuldade== 'D'){
            saldo = 1000;
        }
    }
    while(saldo > 0 && saldo < 10000) {
        while(resp != 'n' && resp != 'N' && resp != 'c' && resp != 'C'){
            printf("\nSeu saldo eh de %d.\n", saldo);
            printf("Como deseja apostar ?\n\nNumeros(n) ou Cores(c) Preto e Vermelho ?\n:");
            scanf(" %c", &resp);
            limparTela();
        }
        if(resp == 'n' || resp == 'N') {
            printf("Escolha um numero de 0 a 36\nEm qual numero deseja apostar ?\n:");
            scanf(" %d", &nn1);
            limparTela();
            printf("Saldo = %d\nQuanto deseja apostar no numero %d ?\n:", saldo, nn1);
            scanf(" %d", &aposta);
            limparTela();
            if(nn1 <= 36 && nn1 >= 0 && aposta <= saldo) {
                nnA = rand() % 37;
                printf("O numero da roleta foi %d.\n", nnA);

                if(nn1 == nnA){
                    aposta = aposta * 35;
                    printf("Voce ganhou %d reais.\n", aposta);
                    saldo = saldo + aposta;
                } else {
                    printf("Voce perdeu %d reais.\n", aposta);
                    saldo = saldo - aposta;
                }
            } else {
                printf("Numero ou saldo invalido.\n");
            }
            resp = 'j';
        } else if(resp == 'c' || resp == 'C'){
            while(cor != 'p' && cor != 'P' && cor != 'v' && cor != 'V'){
                printf("Deseja apostar no preto ou vermelho (p) ou (v) ?\n:");
                scanf(" %c", &cor);
                limparTela();
            }
            printf("Saldo = %d\n", saldo);
            printf("Quanto deseja apostar ?\n:");
            scanf(" %d", &aposta);
            limparTela();
            if(aposta <= saldo) {
                nCor = rand() % 37;
                if(nCor == 0) {
                    printf("Cor verde,voce perdeu %d.", aposta);
                    saldo = saldo - aposta;
                } else if(nCor > 0 && nCor < 19){
                    printf("Cor preto");

                    if(cor == 'p'){
                        printf(",voce ganhou %d.", aposta);
                        saldo += aposta;
                    } else if(cor == 'v'){
                        printf(",voce perdeu %d.", aposta);
                        saldo -= aposta;
                    }
                } else {
                    printf("Cor vermelho.");

                    if(cor == 'v'){
                        printf(",voce ganhou %d.", aposta);
                        saldo += aposta;
                    } else if(cor == 'p'){
                        printf(",voce perdeu %d.", aposta);
                        saldo -= aposta;
                    }
                }
            } else {
                printf("Saldo invalido.");
            }
            cor = 'j';
            resp = 'j';
        }
    }
    limparTela();
    if(saldo <= 0) {
        printf("\nFim de Jogo, Voce Faliu.");
    } else if(saldo >= 10000) {
        if(dificuldade == 'f' || dificuldade == 'F'){
            printf("\n\n\n\n\n\nParabens Voce Venceu no Facil.\nTente uma dificuldade maior da próxima vez.");
        } else if(dificuldade == 'm' || dificuldade == 'M'){
            printf("\n\n\n\n\n\nParabens Voce Venceu na Dificuldade Media.");
        } else if(dificuldade == 'd' || dificuldade == 'D'){
            printf("\n\n\n\n\n\nParabens Voce Venceu na Maior Dificuldade.");
        }
    }
    return 0;
}