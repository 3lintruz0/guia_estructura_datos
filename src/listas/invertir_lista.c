#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

Nodo* invertirLista(Nodo *lista) {
    if (lista == NULL || lista->sig == NULL) return lista;
    
    Nodo *nueva_cabeza = invertirLista(lista->sig);
    lista->sig->sig = lista;
    lista->sig = NULL;
    return nueva_cabeza;
}

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
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
    insertar(&lista, 5);
    insertar(&lista, 4);
    insertar(&lista, 3);
    insertar(&lista, 2);
    insertar(&lista, 1);
    
    printf("Lista original: ");
    imprimir(lista);
    
    lista = invertirLista(lista);
    printf("Lista invertida: ");
    imprimir(lista);
    
    return 0;
}
