#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *izq, *der;
} NodoArb;

int arbolesIdenticos(NodoArb *a, NodoArb *b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a->info != b->info) return 0;
    return arbolesIdenticos(a->izq, b->izq) && arbolesIdenticos(a->der, b->der);
}

NodoArb* crearNodo(int valor) {
    NodoArb *nuevo = (NodoArb*)malloc(sizeof(NodoArb));
    nuevo->info = valor;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

int main() {
    NodoArb *arbol1 = crearNodo(1);
    arbol1->izq = crearNodo(2);
    arbol1->der = crearNodo(3);
    
    NodoArb *arbol2 = crearNodo(1);
    arbol2->izq = crearNodo(2);
    arbol2->der = crearNodo(3);
    
    if (arbolesIdenticos(arbol1, arbol2)) {
        printf("Los árboles son idénticos\n");
    } else {
        printf("Los árboles NO son idénticos\n");
    }
    
    return 0;
}
