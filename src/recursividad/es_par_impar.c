#include <stdio.h>

int esPar(int n);
int esImpar(int n);

int esPar(int n) {
    if (n == 0) return 1;
    return esImpar(n - 1);
}

int esImpar(int n) {
    if (n == 0) return 0;
    return esPar(n - 1);
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d es %s\n", i, esPar(i) ? "PAR" : "IMPAR");
    }
    return 0;
}
