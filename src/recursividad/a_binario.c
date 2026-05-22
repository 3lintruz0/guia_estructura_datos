#include <stdio.h>

void aBinario(int n) {
    if (n > 1) aBinario(n / 2);
    printf("%d", n % 2);
}

int main() {
    printf("10 en binario: ");
    aBinario(10);
    printf("\n");
    
    printf("255 en binario: ");
    aBinario(255);
    printf("\n");
    
    return 0;
}
