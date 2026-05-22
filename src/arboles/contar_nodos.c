#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

int contarNodos(NodoArb *raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
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
    
    printf("Número de nodos: %d\n", contarNodos(arbol));
    return 0;
}
