#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

NodoArb* crearEspejo(NodoArb *raiz) {
    if (raiz == NULL) return NULL;
    
    NodoArb *espejo = (NodoArb*)malloc(sizeof(NodoArb));
    espejo->info = raiz->info;
    espejo->izq = crearEspejo(raiz->der);
    espejo->der = crearEspejo(raiz->izq);
    
    return espejo;
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
    
    NodoArb *espejo = crearEspejo(original);
    
    printf("Árbol original: ");
    inorden(original);
    printf("\n");
    
    printf("Árbol espejo: ");
    inorden(espejo);
    printf("\n");
    
    return 0;
}
