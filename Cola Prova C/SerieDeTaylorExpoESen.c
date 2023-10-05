// Série de Taylor para exponencial:
// A série de Taylor para a função exponencial é dada por:
// e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! + ...
// Você pode calcular uma aproximação para e^x assim:

#include <math.h>

double x = 2.0; // Valor de x
int n = 10;     // Número de termos na série
double resultado = 1.0;

for (int i = 1; i < n; i++) {
    resultado += pow(x, i) / tgamma(i + 1);
}

printf("e^%lf ≈ %lf\n", x, resultado);

// Série de Taylor para seno:
// A série de Taylor para a função seno é dada por: sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
// Você pode calcular uma aproximação para sin(x) assim:

#include <math.h>

double x = 1.0; // Valor de x (em radianos)
int n = 10;     // Número de termos na série
double resultado = 0.0;
int sinal = 1;

for (int i = 0; i < n; i++) {
    resultado += sinal * pow(x, 2 * i + 1) / tgamma(2 * i + 2);
    sinal *= -1; // Alternar o sinal a cada termo
}

printf("sen(%lf) ≈ %lf\n", x, resultado);

// Série de Taylor para o logaritmo natural (ln):
// A série de Taylor para o logaritmo natural é dada por: 
// ln(x) = (x - 1) - (x - 1)^2/2 + (x - 1)^3/3 - (x - 1)^4/4 + ... 
// Você pode calcular uma aproximação para ln(x) assim:

#include <stdio.h>
#include <math.h>

double x = 2.0; // Valor de x (deve ser maior que 0)
int n = 10;     // Número de termos na série
double resultado = 0.0;
double termo = x - 1;

for (int i = 1; i <= n; i++) {
    resultado += (i % 2 == 1 ? 1 : -1) * termo / i;
    termo *= (x - 1);
}

printf("ln(%lf) ≈ %lf\n", x, resultado);

// Série de Taylor para a função cosseno hiperbólico:
// A série de Taylor para o cosseno hiperbólico é dada por: 
// cosh(x) = 1 + x^2/2! + x^4/4! + x^6/6! + ... 
// Você pode calcular uma aproximação para cosh(x) assim:

#include <stdio.h>
#include <math.h>

double x = 1.0; // Valor de x
int n = 10;     // Número de termos na série
double resultado = 1.0;
double termo = 1.0;

for (int i = 1; i <= n; i++) {
    termo *= (x * x) / ((2 * i) * (2 * i - 1));
    resultado += termo;
}

printf("cosh(%lf) ≈ %lf\n", x, resultado);


// Lembre-se de que esses são apenas exemplos e que a precisão das aproximações pode variar
//  dependendo do número de termos usados nas séries. 
//  Séries matemáticas podem ser usadas para calcular uma variedade de funções matemáticas 
//  e constantes com diferentes graus de precisão. 
//  É importante entender a matemática subjacente e experimentar com diferentes valores 
//  e números de termos para obter resultados mais precisos.