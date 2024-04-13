#include <stdio.h>

int main() {
    int i,j;
    for (i = 0;i < 10 ; i++) {
        for (j = 0; j< 10 ; j++) {
            if (i == j || i == 10-j-1) {
                printf("XX ");
            } else {
                printf("%d%d ", i, j);
            }
        }
        printf("\n");
    }
    return 0;
}
