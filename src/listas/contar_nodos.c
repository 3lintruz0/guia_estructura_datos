#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

int contarNodosRecursivo(Nodo *lista) {
    if (lista == NULL) return 0;
    return 1 + contarNodosRecursivo(lista->sig);
}

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
}

int main() {
    Nodo *lista = NULL;
    insertar(&lista, 3);
    insertar(&lista, 2);
    insertar(&lista, 1);
    
    printf("Número de nodos: %d\n", contarNodosRecursivo(lista));
    return 0;
}
