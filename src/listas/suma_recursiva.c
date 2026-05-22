#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

int sumaRecursiva(Nodo *lista) {
    if (lista == NULL) return 0;
    return lista->info + sumaRecursiva(lista->sig);
}

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
}

int main() {
    Nodo *lista = NULL;
    insertar(&lista, 5);
    insertar(&lista, 4);
    insertar(&lista, 3);
    insertar(&lista, 2);
    insertar(&lista, 1);
    
    printf("Suma de la lista: %d\n", sumaRecursiva(lista));
    return 0;
}
