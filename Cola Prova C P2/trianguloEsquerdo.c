#include <stdio.h>

int main() {
    int i, j;
    int vetor[144];
    int count = 0;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            if (!(i == j || i == 12-j-1 || j >= i || (i >= 12-j && i <= 12-j+9))) {
                printf("%02d ", i*10 + j);
                vetor[count] = i*10 + j;
                count++;
            } else {
                printf("XX ");
            }
        }
        printf("\n");
    }
    printf("Elementos do vetor: ");
    for (i = 0; i < count; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
