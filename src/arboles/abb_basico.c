#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

NodoArb* insertar(NodoArb *raiz, int valor) {
    if (raiz == NULL) {
        NodoArb *nuevo = (NodoArb*)malloc(sizeof(NodoArb));
        nuevo->info = valor;
        nuevo->izq = nuevo->der = NULL;
        return nuevo;
    }
    
    if (valor < raiz->info) {
        raiz->izq = insertar(raiz->izq, valor);
    } else if (valor > raiz->info) {
        raiz->der = insertar(raiz->der, valor);
    }
    return raiz;
}

void inorden(NodoArb *raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    printf("%d ", raiz->info);
    inorden(raiz->der);
}

int main() {
    NodoArb *arbol = NULL;
    arbol = insertar(arbol, 7);
    arbol = insertar(arbol, 1);
    arbol = insertar(arbol, 3);
    arbol = insertar(arbol, 4);
    arbol = insertar(arbol, 5);
    arbol = insertar(arbol, 8);
    arbol = insertar(arbol, 9);
    arbol = insertar(arbol, 10);
    arbol = insertar(arbol, 15);
    
    printf("Inorden del ABB: ");
    inorden(arbol);
    printf("\n");
    
    return 0;
}
