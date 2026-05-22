#include <stdio.h>

int sumaDigitos(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumaDigitos(n / 10);
}

int main() {
    printf("Suma de dígitos de 123: %d\n", sumaDigitos(123));
    printf("Suma de dígitos de 456: %d\n", sumaDigitos(456));
    return 0;
}
