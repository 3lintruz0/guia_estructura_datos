#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

int maximoLista(Nodo *lista) {
    int max = INT_MIN;
    while (lista != NULL) {
        if (lista->info > max) max = lista->info;
        lista = lista->sig;
    }
    return max;
}

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
}

int main() {
    Nodo *lista = NULL;
    insertar(&lista, 10);
    insertar(&lista, 50);
    insertar(&lista, 30);
    insertar(&lista, 20);
    
    printf("Máximo: %d\n", maximoLista(lista));
    return 0;
}
