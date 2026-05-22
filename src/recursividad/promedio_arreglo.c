#include <stdio.h>

int sumaArreglo(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumaArreglo(arr, n - 1);
}

float promedioArreglo(int arr[], int n) {
    return (float)sumaArreglo(arr, n) / n;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Promedio: %.2f\n", promedioArreglo(arr, n));
    return 0;
}
