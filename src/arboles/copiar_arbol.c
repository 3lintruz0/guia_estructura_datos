#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

NodoArb* copiarArbol(NodoArb *raiz) {
    if (raiz == NULL) return NULL;
    
    NodoArb *copia = (NodoArb*)malloc(sizeof(NodoArb));
    copia->info = raiz->info;
    copia->izq = copiarArbol(raiz->izq);
    copia->der = copiarArbol(raiz->der);
    
    return copia;
}

NodoArb* crearNodo(int valor) {
    NodoArb *nuevo = (NodoArb*)malloc(sizeof(NodoArb));
    nuevo->info = valor;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

void inorden(NodoArb *raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    printf("%d ", raiz->info);
    inorden(raiz->der);
}

int main() {
    NodoArb *original = crearNodo(1);
    original->izq = crearNodo(2);
    original->der = crearNodo(3);
    
    NodoArb *copia = copiarArbol(original);
    
    printf("Árbol original: ");
    inorden(original);
    printf("\n");
    
    printf("Árbol copiado: ");
    inorden(copia);
    printf("\n");
    
    return 0;
}
