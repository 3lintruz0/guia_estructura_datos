#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

float promedioLista(Nodo *lista) {
    if (lista == NULL) return 0;
    
    int suma = 0, count = 0;
    Nodo *temp = lista;
    
    while (temp != NULL) {
        suma += temp->info;
        count++;
        temp = temp->sig;
    }
    
    return (float)suma / count;
}

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
}

int main() {
    Nodo *lista = NULL;
    insertar(&lista, 10);
    insertar(&lista, 20);
    insertar(&lista, 30);
    insertar(&lista, 40);
    
    printf("Promedio: %.2f\n", promedioLista(lista));
    return 0;
}
