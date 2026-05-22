#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

Nodo* removerDuplicados(Nodo *lista) {
    if (lista == NULL) return NULL;
    
    if (lista->sig != NULL && lista->info == lista->sig->info) {
        Nodo *temp = lista->sig;
        lista->sig = removerDuplicados(temp->sig);
        free(temp);
        return lista;
    }
    lista->sig = removerDuplicados(lista->sig);
    return lista;
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
    insertar(&lista, 3);
    insertar(&lista, 3);
    insertar(&lista, 2);
    insertar(&lista, 2);
    insertar(&lista, 1);
    
    printf("Lista original: ");
    imprimir(lista);
    
    lista = removerDuplicados(lista);
    printf("Sin duplicados: ");
    imprimir(lista);
    
    return 0;
}
