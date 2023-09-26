/*2) Faça um programa em C que receba o salário mensal e aplique a seguinte tabela do Imposto de Renda, apresentando o valor Bruto, o desconto e o valor líquido. Obs.: Não considere deduções


Base de cálculo			        Alíquota	Dedução
Até R$ 2.112,00			-		-
De R$ 2.112,01 até R$ 2.826,65	7,5%		R$ 158,40
De R$ 2.826,66 até R$ 3.751,05	15,0%		R$ 370,40
De R$ 3.751,06 até R$ 4.664,68	22,5%		R$ 651,73
Acima de R$ 4.664,68		    27,5%		R$ 884,96
*/

#include<stdio.h> //cabecalho padrao de entrada e saida
#include<stdlib.h> //cabecalho padrao de sistema
#include<math.h> //cabecalho matematico

int main(){ //metodo principal 
    float salarioBruto, salarioLiquido, IRPF; //declando variaveis reais
    printf("\nQual o salario Bruto? ");
    scanf("%f", &salarioBruto);
    
    //se(salarioBruto <= 2112.00) entao
    if(salarioBruto <= 2112.00){ //funcao se
        IRPF = 0;
    }else{ //senao
        if(salarioBruto > 2112.00 && salarioBruto < 2826.65){
        //se((salarioBruto > 2112.00) e (salarioBruto < 2826.65)) entao
            IRPF = salarioBruto * 0.075; //7,5%
        }else{ //senao
            if(salarioBruto > 2826.65 && salarioBruto < 3751.05){
                IRPF = salarioBruto * 0.15; //15%
            }else{ //senao
                if(salarioBruto > 3751.05 && salarioBruto < 4664.68){
                    IRPF = salarioBruto * 0.22; //22%
                }else{
                    IRPF = salarioBruto * 0.275; //27,5%
                }//fimse
            } //fimse
        }//fimse
    }//fimse 
    salarioLiquido = salarioBruto - IRPF; //calculando o salario liquido
    printf("\nSalario Bruto = R$ %.2f", salarioBruto);
    printf("\nIRPF = R$ %.2f", IRPF);
    printf("\nSalario Liquido = R$ %.2f", salarioLiquido);
  
    return 0;
}