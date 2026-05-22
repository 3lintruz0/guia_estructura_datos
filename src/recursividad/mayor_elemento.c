#include <stdio.h>

int mayorElemento(int arr[], int n) {
    if (n == 1) return arr[0];
    int max = mayorElemento(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}

int main() {
    int arr[] = {3, 7, 2, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mayor elemento: %d\n", mayorElemento(arr, n));
    return 0;
}
