#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *sig;
} Nodo;

typedef struct {
    Nodo *tope;
} Pila;

Pila* crearPila() {
    Pila *p = (Pila*)malloc(sizeof(Pila));
    p->tope = NULL;
    return p;
}

void push(Pila *p, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = valor;
    nuevo->sig = p->tope;
    p->tope = nuevo;
}

int pop(Pila *p) {
    if (p->tope == NULL) return -1;
    Nodo *temp = p->tope;
    int valor = temp->info;
    p->tope = temp->sig;
    free(temp);
    return valor;
}

int estaVacia(Pila *p) {
    return p->tope == NULL;
}

void reemplazarEnPila(Pila *p, int viejo, int nuevo) {
    Pila *temp = crearPila();
    while (!estaVacia(p)) {
        int valor = pop(p);
        push(temp, valor);
    }
    while (!estaVacia(temp)) {
        int valor = pop(temp);
        if (valor == viejo) {
            push(p, nuevo);
        } else {
            push(p, valor);
        }
    }
    free(temp);
}

int main() {
    Pila *pila = crearPila();
    push(pila, 5);
    push(pila, 3);
    push(pila, 3);
    push(pila, 7);
    reemplazarEnPila(pila, 3, 99);
    printf("Pila después de reemplazar: ");
    while (!estaVacia(pila)) {
        printf("%d ", pop(pila));
    }
    printf("\n");
    return 0;
}
