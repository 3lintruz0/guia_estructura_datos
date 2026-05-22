#include <stdio.h>
#include <stdlib.h>

typedef struct termino {
    float coef;
    int exp;
    struct termino *sig;
} Termino;

Termino* crearTermino(float coef, int exp) {
    Termino *t = (Termino*)malloc(sizeof(Termino));
    t->coef = coef;
    t->exp = exp;
    t->sig = NULL;
    return t;
}

void insertarTermino(Termino **poly, float coef, int exp) {
    if (*poly == NULL) {
        *poly = crearTermino(coef, exp);
        return;
    }
    
    if ((*poly)->exp == exp) {
        (*poly)->coef += coef;
        return;
    }
    insertarTermino(&(*poly)->sig, coef, exp);
}

Termino* sumarPolinomios(Termino *p1, Termino *p2) {
    Termino *resultado = NULL;
    
    while (p1 != NULL) {
        insertarTermino(&resultado, p1->coef, p1->exp);
        p1 = p1->sig;
    }
    
    while (p2 != NULL) {
        insertarTermino(&resultado, p2->coef, p2->exp);
        p2 = p2->sig;
    }
    
    return resultado;
}

void imprimirPolinomio(Termino *poly) {
    while (poly != NULL) {
        printf("%.2fx^%d + ", poly->coef, poly->exp);
        poly = poly->sig;
    }
    printf("0\n");
}

int main() {
    Termino *p1 = NULL, *p2 = NULL;
    
    insertarTermino(&p1, 2, 2);
    insertarTermino(&p1, 3, 1);
    insertarTermino(&p1, 1, 0);
    
    insertarTermino(&p2, 1, 2);
    insertarTermino(&p2, 4, 1);
    insertarTermino(&p2, 2, 0);
    
    printf("Polinomio 1: ");
    imprimirPolinomio(p1);
    
    printf("Polinomio 2: ");
    imprimirPolinomio(p2);
    
    Termino *suma = sumarPolinomios(p1, p2);
    printf("Suma: ");
    imprimirPolinomio(suma);
    
    return 0;
}
