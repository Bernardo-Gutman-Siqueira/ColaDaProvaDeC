// Entender séries matemáticas e como usá-las em loops for é um tópico importante ao programar 
// em C. Aqui estão alguns exemplos de séries matemáticas que podem ser relevantes 
// para a sua prova, juntamente com exemplos de como você pode implementá-las usando um 
// loop for em C:

// Soma dos primeiros N números naturais:
// A série é 1 + 2 + 3 + ... + N. Você pode calculá-la assim:

int n = 10; // ou qualquer outro valor de N
int soma = 0;

for (int i = 1; i <= n; i++) {
    soma += i;
}

printf("A soma dos primeiros %d números naturais é: %d\n", n, soma);

// Soma dos primeiros N números pares:
// A série é 2 + 4 + 6 + ... + 2N. Use um loop for para calcular isso:


int n = 10; // ou qualquer outro valor de N
int soma = 0;

for (int i = 1; i <= n; i++) {
    soma += 2 * i;
}

printf("A soma dos primeiros %d números pares é: %d\n", n, soma);


// Soma dos termos de uma progressão aritmética:
// Se você tiver os primeiros termos de uma progressão aritmética 
// (a1, a2, a3, ...) e a razão (r), você pode calcular a soma dos 
// N primeiros termos assim:

int a1 = 1;  // O primeiro termo
int r = 2;   // A razão da progressão
int n = 5;   // O número de termos para somar

int soma = 0;
for (int i = 0; i < n; i++) {
    soma += a1 + i * r;
}

printf("A soma dos primeiros %d termos da progressão é: %d\n", n, soma);

// Soma dos termos de uma série geométrica:
// Se você tiver o primeiro termo (a) e a razão (r) de uma série geométrica,
// você pode calcular a soma dos N primeiros termos assim:

int a = 1;   // O primeiro termo
int r = 2;   // A razão da série geométrica
int n = 5;   // O número de termos para somar

int soma = 0;
for (int i = 0; i < n; i++) {
    soma += a * pow(r, i);
}

printf("A soma dos primeiros %d termos da série geométrica é: %d\n", n, soma);