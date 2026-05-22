#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

int altura(NodoArb *raiz) {
    if (raiz == NULL) return 0;
    int altIzq = altura(raiz->izq);
    int altDer = altura(raiz->der);
    return 1 + (altIzq > altDer ? altIzq : altDer);
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
    
    printf("Altura del árbol: %d\n", altura(arbol));
    return 0;
}
