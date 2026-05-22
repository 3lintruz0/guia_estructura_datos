#include <stdio.h>

void digitosInversos(int n) {
    if (n == 0) return;
    printf("%d", n % 10);
    digitosInversos(n / 10);
}

int main() {
    printf("Dígitos inversos de 12345: ");
    digitosInversos(12345);
    printf("\n");
    return 0;
}
