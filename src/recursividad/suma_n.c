#include <stdio.h>

int sumaN(int n) {
    if (n == 0) return 0;
    return n + sumaN(n - 1);
}

int main() {
    printf("Suma de 1 a 10: %d\n", sumaN(10));
    printf("Suma de 1 a 100: %d\n", sumaN(100));
    return 0;
}
