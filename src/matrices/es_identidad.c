#include <stdio.h>
#include <stdlib.h>

int esMatrizIdentidad(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (matriz[i][j] != 1) return 0;
            } else {
                if (matriz[i][j] != 0) return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n = 3;
    int **matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }
    
    matriz[0][0] = 1; matriz[0][1] = 0; matriz[0][2] = 0;
    matriz[1][0] = 0; matriz[1][1] = 1; matriz[1][2] = 0;
    matriz[2][0] = 0; matriz[2][1] = 0; matriz[2][2] = 1;
    
    if (esMatrizIdentidad(matriz, n)) {
        printf("Es matriz identidad\n");
    } else {
        printf("No es matriz identidad\n");
    }
    
    return 0;
}
