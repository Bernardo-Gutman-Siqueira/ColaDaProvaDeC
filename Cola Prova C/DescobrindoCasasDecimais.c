//Faça um programa que descubra as casas decimais de Float e Double.
#include <stdio.h>

int main() {
    float f = 1;
    double d = 1;
    int casasDecimaisF = 0,casasDecimaisD = 0;
    while ( f > 0) {
        f /= 10.0;
        casasDecimaisF++;
    }
    while ( d > 0) {
        d /= 10.0;
        casasDecimaisD++;
    }
    printf("Float sao %d casas decimais e Double sao %d casas.",casasDecimaisF,casasDecimaisD);
    return 0;
}