#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

void insertarEnOrden(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    
    if (*lista == NULL || (*lista)->info >= valor) {
        nuevo->sig = *lista;
        *lista = nuevo;
        return;
    }
    
    Nodo *actual = *lista;
    while (actual->sig != NULL && actual->sig->info < valor) {
        actual = actual->sig;
    }
    nuevo->sig = actual->sig;
    actual->sig = nuevo;
}

void imprimir(Nodo *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->info);
        lista = lista->sig;
    }
    printf("NULL\n");
}

int main() {
    Nodo *lista = NULL;
    insertarEnOrden(&lista, 5);
    insertarEnOrden(&lista, 2);
    insertarEnOrden(&lista, 8);
    insertarEnOrden(&lista, 1);
    insertarEnOrden(&lista, 9);
    
    printf("Lista ordenada: ");
    imprimir(lista);
    
    return 0;
}
