#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

int sonIdenticas(Nodo *a, Nodo *b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a->info != b->info) return 0;
    return sonIdenticas(a->sig, b->sig);
}

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
}

int main() {
    Nodo *lista1 = NULL, *lista2 = NULL;
    insertar(&lista1, 3);
    insertar(&lista1, 2);
    insertar(&lista1, 1);
    
    insertar(&lista2, 3);
    insertar(&lista2, 2);
    insertar(&lista2, 1);
    
    if (sonIdenticas(lista1, lista2)) {
        printf("Las listas son idénticas\n");
    } else {
        printf("Las listas NO son idénticas\n");
    }
    return 0;
}
