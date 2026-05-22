#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

Nodo* copiaSuperficial(Nodo *original) {
    if (original == NULL) return NULL;
    Nodo *copia = (Nodo*)malloc(sizeof(Nodo));
    copia->info = original->info;
    copia->sig = copiaSuperficial(original->sig);
    return copia;
}

Nodo* copiaProfunda(Nodo *original) {
    if (original == NULL) return NULL;
    Nodo *copia = (Nodo*)malloc(sizeof(Nodo));
    copia->info = original->info;
    copia->sig = copiaProfunda(original->sig);
    return copia;
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
    Nodo *original = NULL;
    insertar(&original, 3);
    insertar(&original, 2);
    insertar(&original, 1);
    
    printf("Lista original: ");
    imprimir(original);
    
    Nodo *copia = copiaSuperficial(original);
    printf("Copia superficial: ");
    imprimir(copia);
    
    Nodo *copiap = copiaProfunda(original);
    printf("Copia profunda: ");
    imprimir(copiap);
    
    return 0;
}
