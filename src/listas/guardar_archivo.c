#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

void guardarEnArchivo(Nodo *lista, const char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir archivo\n");
        return;
    }
    
    while (lista != NULL) {
        fprintf(f, "%d\n", lista->info);
        lista = lista->sig;
    }
    fclose(f);
    printf("Lista guardada en %s\n", archivo);
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
    
    guardarEnArchivo(lista, "lista.txt");
    return 0;
}
