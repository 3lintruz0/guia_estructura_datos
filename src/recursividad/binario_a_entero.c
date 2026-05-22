#include <stdio.h>

int binarioAEntero(int binario) {
    if (binario == 0) return 0;
    return (binario % 10) + 2 * binarioAEntero(binario / 10);
}

int main() {
    printf("1010 en binario es: %d\n", binarioAEntero(1010));
    printf("1111 en binario es: %d\n", binarioAEntero(1111));
    return 0;
}
