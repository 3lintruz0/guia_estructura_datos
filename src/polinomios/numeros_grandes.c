#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int digito;
    struct nodo *sig;
} Nodo;

void insertarAlFinal(Nodo **lista, int digito) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->digito = digito;
    nuevo->sig = NULL;
    
    if (*lista == NULL) {
        *lista = nuevo;
        return;
    }
    
    Nodo *temp = *lista;
    while (temp->sig != NULL) temp = temp->sig;
    temp->sig = nuevo;
}

Nodo* sumarNumerosGrandes(Nodo *num1, Nodo *num2) {
    Nodo *resultado = NULL;
    int carry = 0;
    
    while (num1 != NULL || num2 != NULL || carry) {
        int suma = carry;
        if (num1 != NULL) {
            suma += num1->digito;
            num1 = num1->sig;
        }
        if (num2 != NULL) {
            suma += num2->digito;
            num2 = num2->sig;
        }
        insertarAlFinal(&resultado, suma % 10);
        carry = suma / 10;
    }
    
    return resultado;
}

int main() {
    Nodo *num1 = NULL, *num2 = NULL;
    
    insertarAlFinal(&num1, 9);
    insertarAlFinal(&num1, 9);
    
    insertarAlFinal(&num2, 1);
    
    Nodo *suma = sumarNumerosGrandes(num1, num2);
    printf("Suma de números grandes realizada\n");
    
    return 0;
}
