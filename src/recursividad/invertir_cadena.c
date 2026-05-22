#include <stdio.h>
#include <string.h>

void invertirRecursivo(char *cadena, int inicio, int fin) {
    if (inicio >= fin) return;
    char temp = cadena[inicio];
    cadena[inicio] = cadena[fin];
    cadena[fin] = temp;
    invertirRecursivo(cadena, inicio + 1, fin - 1);
}

void invertirIterativo(char *cadena) {
    int n = strlen(cadena);
    for (int i = 0; i < n / 2; i++) {
        char temp = cadena[i];
        cadena[i] = cadena[n - 1 - i];
        cadena[n - 1 - i] = temp;
    }
}

int main() {
    char cadena1[] = "Hola";
    char cadena2[] = "Mundo";
    
    invertirRecursivo(cadena1, 0, strlen(cadena1) - 1);
    printf("Inverso recursivo: %s\n", cadena1);
    
    invertirIterativo(cadena2);
    printf("Inverso iterativo: %s\n", cadena2);
    
    return 0;
}
