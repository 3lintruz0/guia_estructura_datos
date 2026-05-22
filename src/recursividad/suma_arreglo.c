#include <stdio.h>

int sumaArreglo(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumaArreglo(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Suma del arreglo: %d\n", sumaArreglo(arr, n));
    return 0;
}
