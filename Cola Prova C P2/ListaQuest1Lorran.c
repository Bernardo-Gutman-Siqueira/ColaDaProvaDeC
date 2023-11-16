#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
//Divido o cabeçado para funcionar o comando sleep e clear mesmo em windows ou linux
#ifdef _WIN32
#include <windows.h>
    #define tempoEspera(temp) Sleep((temp) * 1000);
    #define limparTela() system("cls");
#else
#include <unistd.h>
    #define tempoEspera(temp) sleep(temp);
    #define limparTela() system("clear");
#endif

#define MAX_PALAVRAS 100  //Máximo de palavras
#define MAX_CARACTERES 50 //Máximo de caracteres por palavra
#define MAX_MATRIZ 2*MAX_CARACTERES //Máximo tmanho da matriz, dobro do máximo de caracteres

//Variáveis Globais
int tamanhoManual = 0; // 0 para automático, 1 para manual
int tentativaPosicaoMenu = 0;
int modoDesenvolvedor = 0; // 0 para desativado, 1 para ativado
int mensagemConflito = 0;
char palavrasRestantes[MAX_PALAVRAS][MAX_CARACTERES];
int totalPalavrasRestantes;

int exibirMenu();
void configurarMatriz(char palavras[][MAX_CARACTERES], int *qtdPalavras, int *tamanhoMatriz, int *tentativaPosicao);
void gerenciadorMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], char matrizPos[MAX_MATRIZ][MAX_MATRIZ], char palavras[][MAX_CARACTERES], int qtdPalavras, int *tamanhoMatriz, int *tentativasTotal, int tentativaPosicao);
void removerPalavraRestante(char* palavra);
void posicaoPalavrasMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], char matrizPos[MAX_MATRIZ][MAX_MATRIZ], int tamanho);
void preencherMatrizAleatoria(char matriz[MAX_MATRIZ][MAX_MATRIZ], int tamanho);
void imprimirMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], int tamanho);
int posicaoOcupada(char matriz[MAX_MATRIZ][MAX_MATRIZ], char palavra[MAX_CARACTERES], int linha, int coluna, int comprimento, int direcao);
void limparMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], int tamanho);
void adicionarPalavra(char matriz[MAX_MATRIZ][MAX_MATRIZ], char matrizPos[MAX_MATRIZ][MAX_MATRIZ], char palavra[MAX_CARACTERES], char palavras[][MAX_CARACTERES], int qtdPalavras, int *tamanho, int *tentativasTotal, int tentativaPosicao);

int main()
{
    int qtdPalavras;
    int tamanhoMatriz;
    int tentativaPosicao;
    char palavras[MAX_PALAVRAS][MAX_CARACTERES];
    int tentativasTotal = 0;
    int opcao;

    srand(time(NULL)); //Inicializo o gerador de números aleatórios para converter para letra depois
    limparTela();
    do { //Menu de opções, só para usar manual ou automático no tamanho da matriz
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                limparTela();
                configurarMatriz(palavras, &qtdPalavras, &tamanhoMatriz, &tentativaPosicao);
                break;
            case 2:
                tamanhoManual = (tamanhoManual == 0) ? 1 : 0; //De 0 para 1 vice versa
                printf("\n\nTamanho da matriz definida como %s.\n", (tamanhoManual ? "Manual" : "Automatico"));
                tempoEspera(1);
                limparTela();
                break;
            case 3:
                tentativaPosicaoMenu = (tentativaPosicaoMenu == 0) ? 1 : 0; //De 0 para 1 vice versa
                printf("\n\nTentativas de posicao definida para %s.\n", (modoDesenvolvedor ? "Manual" : "Padrao"));
                tempoEspera(1);
                limparTela();
                break;
            case 4:
                modoDesenvolvedor = (modoDesenvolvedor == 0) ? 1 : 0; //De 0 para 1 vice versa
                printf("\n\nModo desenvolvedor %s.\n", (modoDesenvolvedor ? "ativado" : "desativado"));
                tempoEspera(1);
                limparTela();
                break;
            case 5:
                mensagemConflito = (mensagemConflito == 0) ? 1 : 0; //De 0 para 1 vice versa
                printf("\n\nMensagens de conflito %s.\n", (mensagemConflito ? "ativadas" : "desativadas"));
                tempoEspera(1);
                limparTela();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida. Selecione novamente.\n");
                tempoEspera(1);
                limparTela();
        }

    } while (opcao != 1);

    char matriz[MAX_MATRIZ][MAX_MATRIZ]; //Crio a matriz tamanho máximo definido
    char matrizPos[MAX_MATRIZ][MAX_MATRIZ];

    //Envio todas as variáveis para o loop de tentativa de geração de matriz
    gerenciadorMatriz(matriz, matrizPos, palavras, qtdPalavras, &tamanhoMatriz, &tentativasTotal, tentativaPosicao);

    //Preencho as posições vazias com letras aleatórias
    preencherMatrizAleatoria(matriz, tamanhoMatriz);

    //Imprimo o número total de tentativas para gerar a matriz e o tmanho final dela
    modoDesenvolvedor ? printf("Numero total de tantativas de posicionar palavras: %d\n", tentativasTotal) : 0;
    modoDesenvolvedor ? printf("Tamanho final da matriz gerada: %d\n", tamanhoMatriz) : 0;

    //Imprimo as palavras antes da matriz, pois eu apago o terminal antes
    printf("\nPalavras a serem encontradas:\n");
    for (int i=0; i<qtdPalavras; i++)
    {
        printf("%d. %s\n", i + 1, palavras[i]);
    }

    //Imprimo a matriz (Caça-palavras) resultante
    printf("\nCaca palavras gerado:\n\n");
    imprimirMatriz(matriz, tamanhoMatriz);

    if (modoDesenvolvedor)
    {
        printf("\nPosicao das palavras na matriz:\n\n");
        imprimirMatriz(matrizPos, tamanhoMatriz);
    }

    return 0; //Código por Lorran 12310802 // ver 3
}

int exibirMenu()
{
    int escolha;

    printf("\nBem vindo ao caca palavras do Lorran. versao atual: 3.0\n\nMenu: (Selecione pelo numero abaixo)\n\n");
    printf("1 - Gerar caca palavras\n");
    printf("2 - Tamanho da matriz: %s\n", (tamanhoManual ? "SELECIONAR" : "AUTOMATICO"));
    printf("3 - Tentativas de posicionas palavras: %s (AVISO: Pode voltar para padrao depois)\n", (tentativaPosicaoMenu ? "SELECIONAR" : "PADRAO 5"));
    printf("4 - Modo desenvolvedor (Debug): %s (AVISO: Mostra mensagens uteis no desenvolvimento)\n", (modoDesenvolvedor ? "ATIVO" : "INATIVO"));
    printf("5 - Mensagens de conflito (Debug): %s (AVISO: Pode ter muito mensagem de aviso na tela)\n", (mensagemConflito ? "HABILITADA" : "DESABILITADA"));
    printf("0 - Sair\n");
    printf("\nOpcao SELECIONAR mostra que poderar alterar depois\n");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &escolha);

    getchar(); //Consumir o caractere de nova linha pendente

    return escolha;
}

void configurarMatriz(char palavras[][MAX_CARACTERES], int *qtdPalavras, int *tamanhoMatriz, int *tentativaPosicao)
{
    int maiorPalavra = 0;

    do { //Verifico se o usuário selecionou mais de 4 palavras, caso não tenha que selecione novamente
        printf("\nQuantas palavras voce quer no caca palavras (Minimo 4 palavras e Maximo de 100)\n:");
        char buffer[100]; // Considerando uma grande quantidade de palavras defino o buffer como 100
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", qtdPalavras);

        if(*qtdPalavras < 4 || *qtdPalavras > 100)
        {
            printf("\n\nNo minimo 4 palavras e maximo de 100. Por favor selecione novamente\n");
        }
    } while (*qtdPalavras < 4 || *qtdPalavras > 100);

    limparTela(); //Limpo a tela

    fflush(stdin);

    printf("Digite as %d palavras (Maximo de 50 caracteres)\n\n", *qtdPalavras);
    for (int i=0; i<*qtdPalavras; i++)
    {
        printf("Palavra %d: ", i + 1);
        fgets(palavras[i], MAX_CARACTERES, stdin);
        palavras[i][strcspn(palavras[i], "\n")] = '\0'; //Remove o caractere de nova linha

        if (strlen(palavras[i]) > strlen(palavras[maiorPalavra])) //Vejo qual é a maior palavra para decidir o tamanho da matriz automaticamente
        {
            maiorPalavra = i;
        }
    }

    if (tamanhoManual)
    {
        //Se o tamanho for manual, pergunte ao usuário
        do {
            printf("\nDigite o tamanho desejado para a matriz (Minimo de %d e Maximo 100)\nAVISO:Tamanhos muito pequenos fara com que o codigo aumente a matriz\n:", strlen(palavras[maiorPalavra]));
            scanf("%d", tamanhoMatriz);

            if (*tamanhoMatriz < strlen(palavras[maiorPalavra]) || *tamanhoMatriz > 100)
            {
                printf("\n\nTamanho diferente do solicitado podendo causar erros, selecione novamente.\n");                
            }
        } while (*tamanhoMatriz < strlen(palavras[maiorPalavra]) || *tamanhoMatriz > 100);
    } else {
        //Determino a tamanho da matriz pela maior palavra (Definida como o dobro)
        *tamanhoMatriz = 2 * strlen(palavras[maiorPalavra]);
    }

    if (tentativaPosicaoMenu)
    {
        //Se o tamanho for manual, pergunte ao usuário
        do {
            printf("\nTentativas posicao sao quantas tentativas os codigo vai tentar posicionar uma palavras aleatoriamente na matriz.\nSe depois de n tentativas o codigo nao conseguir eh considera como obstruido e aumentara a matriz posicionando as palavras novamente desde o comeco");
            printf("\n\nDigite quantas vezes o codigo tentara posicionar uma palavra (Minimo de 1 e Maximo 100)(Padrao de 5)\nAVISO:Tentativas pequenas farao com que gere uma matriz enorme\n:", strlen(palavras[maiorPalavra]));
            scanf("%d", tentativaPosicao);

            if (*tentativaPosicao < 1 || *tentativaPosicao > 100)
            {
                printf("\n\nTentativas diferentes do solicitado podendo causar erros, selecione novamente.\n");                
            }
        } while (*tentativaPosicao < 1 || *tentativaPosicao > 100);
    } else {
        //Determino o numero de tentativas padrao de 5
        *tentativaPosicao = 5;
    }

    limparTela();
    modoDesenvolvedor ? printf("\nTamanho inicial da matriz gerada: %d\n", *tamanhoMatriz) : 0;
    modoDesenvolvedor ? printf("\nTentativas de posicao: %d\n", *tentativaPosicao) : 0;
}

void gerenciadorMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], char matrizPos[MAX_MATRIZ][MAX_MATRIZ], char palavras[][MAX_CARACTERES], int qtdPalavras, int *tamanhoMatriz, int *tentativasTotal, int tentativaPosicao)
{
    //Copie as palavras iniciais para a lista de palavras restantes
    totalPalavrasRestantes = qtdPalavras;
    for (int i = 0; i < qtdPalavras; i++)
    {
        strcpy(palavrasRestantes[i], palavras[i]);
    }

    //Inicializo a matriz com espaços em branco (Ajuda em saber onde já tem palavra)
    limparMatriz(matriz, *tamanhoMatriz);

    //Adiciono as palavras à matriz
    for (int i = 0; i < qtdPalavras; i++)
    {
        adicionarPalavra(matriz, matrizPos, palavras[i], palavras, qtdPalavras, tamanhoMatriz, tentativasTotal, tentativaPosicao);
    }

    //Crio uma matriz separada para ver a posição das palavras
    if (modoDesenvolvedor)
    {
        posicaoPalavrasMatriz(matriz, matrizPos, *tamanhoMatriz);
    }
}

void removerPalavraRestante(char* palavra)
{
    for (int i = 0; i < totalPalavrasRestantes; i++)
    {
        if (strcmp(palavrasRestantes[i], palavra) == 0)
        {
            //Palavra encontrada, mova as palavras restantes para preencher o espaço
            for (int j = i; j < totalPalavrasRestantes - 1; j++)
            {
                strcpy(palavrasRestantes[j], palavrasRestantes[j + 1]);
            }
            totalPalavrasRestantes--; //Atualize o tamanho da lista
            break;
        }
    }
}

void posicaoPalavrasMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], char matrizPos[MAX_MATRIZ][MAX_MATRIZ], int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        for (int j=0; j<tamanho; j++)
        {
            if (islower(matriz[i][j])) // Verifica se é minúscula
            {
                matrizPos[i][j] = toupper(matriz[i][j]); // Converte para maiúscula
            }
            else
            {
                matrizPos[i][j] = matriz[i][j]; // Mantém caracteres que não são letras inalterados
            }
        }
    }
}

void preencherMatrizAleatoria(char matriz[MAX_MATRIZ][MAX_MATRIZ], int tamanho)
{
    int aleat = 26; //Número de letras no alfabeto, não utiizo caracteres especiais

    for (int i=0; i<tamanho; i++)
    {
        for (int j=0; j<tamanho; j++)
        {
            if (matriz[i][j] == ' ') //Verifico onde não tem nada
            {
                matriz[i][j] = 'A' + rand()%aleat; //Então preencho com letras aleatórias
            } else if (islower(matriz[i][j])) // Verifica se é minúscula
            {
                matriz[i][j] = toupper(matriz[i][j]); // Converte para maiúscula
            }
            else
            {
                matriz[i][j] = matriz[i][j]; // Mantém caracteres que não são letras inalterados
            }
        }
    }
}

void imprimirMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        for (int j=0; j<tamanho; j++)
        {
            printf("%c ", matriz[i][j]); //Imprimi a matriz, meio óbvio
        }
        printf("\n");
    }
}

int posicaoOcupada(char matriz[MAX_MATRIZ][MAX_MATRIZ], char palavra[MAX_CARACTERES], int linha, int coluna, int comprimento, int direcao)
{
    if (direcao == 0) //Horizontal
    {
        for (int j=0; j<comprimento; j++)
        {
            //Verifico se a posição contém uma letra diferente da que tem na palavra que será inserida ou já contém outra palavra
            if (matriz[linha][coluna + j] != palavra[j] && matriz[linha][coluna + j] != ' ')
            {
                mensagemConflito ? printf("Conflito na posicao [%d][%d] com a palavra \"%s\"\n", linha, coluna + j, palavra) : 0;
                return 1; //Posição ocupada
            }
        }
    } else { //Vertical
        for (int i=0; i<comprimento; i++)
        {
            //Verifico se a posição contém uma letra diferente da que tem na palavra que será inserida ou já contém outra palavra
            if (matriz[linha + i][coluna] != palavra[i] && matriz[linha + i][coluna] != ' ')
            {
                mensagemConflito ? printf("Conflito na posicao [%d][%d] com a palavra \"%s\"\n", linha + i, coluna, palavra) : 0;
                return 1; //Posição ocupada
            }
        }
    }
    return 0; //Posição livre
}

void limparMatriz(char matriz[MAX_MATRIZ][MAX_MATRIZ], int tamanho)
{
    for (int i=0; i<tamanho; i++) 
    {
        for (int j=0; j<tamanho; j++) 
        {
            matriz[i][j] = ' '; //Preenche os espaços da matriz com nada
        }
    }
}

void adicionarPalavra(char matriz[MAX_MATRIZ][MAX_MATRIZ], char matrizPos[MAX_MATRIZ][MAX_MATRIZ], char palavra1[MAX_CARACTERES], char palavras[][MAX_CARACTERES], int qtdPalavras, int *tamanho, int *tentativasTotal, int tentativaPosicao)
{
    if (totalPalavrasRestantes == 0)
    {
        return; //Nenhuma palavra restante para adicionar
    }

    int index = rand() % totalPalavrasRestantes;
    char palavra[MAX_CARACTERES];
    strcpy(palavra, palavrasRestantes[index]);

    int comprimento = strlen(palavra); //Pego o tamanho da palavra
    int direcao, linha, coluna; //Se está na vertical ou horizontal
    int tentativas = 0; //Tem um número limitado de tentativas

    //Tenta adicionar a palavra até encontrar uma posição válida, caso não ache considero a matriz como impossível de ser gerada e tento novamente
    while (tentativas < tentativaPosicao)
    {
        tentativas++;

        //Escolhe uma direção aleatória (0 para horizontal, 1 para vertical)
        direcao = rand()%2;

        //Escolhe uma posição aleatória
        linha = rand() % (*tamanho - (direcao == 1 ? comprimento - 1 : 0));
        coluna = rand() % (*tamanho - (direcao == 0 ? comprimento - 1 : 0));

        //Se a posição está livre, adiciona a palavra e marca como ocupada na matriz
        if (!posicaoOcupada(matriz, palavra, linha, coluna, comprimento, direcao))
        {
            //Adiciona a palavra à matriz na posição escolhida
            if (direcao == 0) //Horizontal
            {
                for (int j=0; j<comprimento; j++)
                {
                    matriz[linha][coluna + j] = palavra[j];
                }
            } else { //Vertical
                for (int i=0; i<comprimento; i++)
                {
                    matriz[linha + i][coluna] = palavra[i];
                }
            }
            removerPalavraRestante(palavra);
            *tentativasTotal += tentativas; //Adiciono o total de tentativas (Debug)
            return; //A palavra foi adicionada com sucesso, saindo da função
        }
    }
    if (*tamanho < MAX_MATRIZ - 1)
    {
        modoDesenvolvedor ? printf("Nao foi possivel posicionar a palavra \"%s\". Aumentando o tamanho da matriz em 1 unidade e gerando matriz novamente.\n", palavra) : 0;
        *tamanho += 1;
        gerenciadorMatriz(matriz, matrizPos, palavras, qtdPalavras, tamanho, tentativasTotal, tentativaPosicao);
    }
    else
    {
        printf("Nao foi possivel posicionar a palavra \"%s\" mesmo apos aumento do tamanho da matriz. Encerrando o programa....\n", palavra);
        exit(1); //Encerra o programa, pois não é possível gerar o caça-palavras com as palavras fornecidas
    }
    //Código por Lorran 12310802 // Caça palavras ver. 3.0
}