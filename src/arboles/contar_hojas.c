#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

int contarHojas(NodoArb *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izq == NULL && raiz->der == NULL) return 1;
    return contarHojas(raiz->izq) + contarHojas(raiz->der);
}

NodoArb* crearNodo(int valor) {
    NodoArb *nuevo = (NodoArb*)malloc(sizeof(NodoArb));
    nuevo->info = valor;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

int main() {
    NodoArb *arbol = crearNodo(1);
    arbol->izq = crearNodo(2);
    arbol->der = crearNodo(3);
    arbol->izq->izq = crearNodo(4);
    arbol->izq->der = crearNodo(5);
    
    printf("Número de hojas: %d\n", contarHojas(arbol));
    return 0;
}
