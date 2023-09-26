// 1) Faça um programa em C que leia 2 números e apresente as seguintes operações com os dois números:
// a) soma
// b) subtração
// c) multiplicação
// d) divisão
// e) potência
// f) raiz quadrada de ambos
// g) raiz a índice b

#include<stdio.h> //cabecalho padrao de entrada e saida
#include<stdlib.h> //cabecalho padrao de sistema
#include<math.h> //cabecalho matematico

int main(){ //metodo principal 
    float n1, n2, resposta; //declaracao de variaveis reais
    printf("\nQual o valor do primeiro numero? "); //escreve na tela 
    scanf("%f", &n1); //lendo um real e colando na posicao de memoria n1
    printf("\nQual o valor do segundo numero? "); //escreve na tela 
    scanf("%f", &n2); //lendo um real e colando na posicao de memoria n2
    
    resposta = n1 + n2; //somando os valores
    printf("\n%.3f + %.3f = %.5f\n", n1, n2, resposta); //escrevendo valores
    
    resposta = n1 - n2; //subtraindo os valores
    printf("\n%.3f - %.3f = %.5f\n", n1, n2, resposta);
    
    resposta = n1 * n2; //multiplicando os valores
    printf("\n%.3f x %.3f = %.5f\n", n1, n2, resposta);
    
    resposta = n1 / n2; //dividindo os valores
    printf("\n%.3f / %.3f = %.5f\n", n1, n2, resposta);
    
    resposta = pow(n1, n2); //potencia de n1 elevado a n2 (n1^n2)
    printf("\n%.2f ^ %.2f = %.3f\n", n1, n2, resposta); 
    
    resposta = sqrt(n1); //raiz quadrada de n1
    printf("\nRaiz quadrada de %.2f = %.4f\n", n1, resposta);
    resposta = sqrt(n2); //raiz quadrada de n2
    printf("\nRaiz quadrada de %.2f = %.4f\n", n2, resposta);
    
    resposta = pow(n1, (float) 1.0/n2); //potencia de n1 elevado a n2 (n1^n2)
    printf("\nRaiz de %.2f indice %.2f = %.10f\n", n1, n2, resposta);
    
    return 0;
}