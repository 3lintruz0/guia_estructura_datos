#include <stdio.h>

int mcdRecursivo(int m, int n) {
    if (n == 0) return m;
    return mcdRecursivo(n, m % n);
}

int mcdIterativo(int m, int n) {
    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

int main() {
    printf("MCD(48, 18) recursivo: %d\n", mcdRecursivo(48, 18));
    printf("MCD(48, 18) iterativo: %d\n", mcdIterativo(48, 18));
    printf("MCD(100, 50) recursivo: %d\n", mcdRecursivo(100, 50));
    return 0;
}
