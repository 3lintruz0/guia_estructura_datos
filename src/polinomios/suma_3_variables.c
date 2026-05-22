#include <stdio.h>
#include <stdlib.h>

typedef struct termino {
    float coef;
    int exp_x, exp_y, exp_z;
    struct termino *sig;
} Termino;

Termino* crearTermino(float coef, int ex, int ey, int ez) {
    Termino *t = (Termino*)malloc(sizeof(Termino));
    t->coef = coef;
    t->exp_x = ex;
    t->exp_y = ey;
    t->exp_z = ez;
    t->sig = NULL;
    return t;
}

void insertarTermino(Termino **poly, float coef, int ex, int ey, int ez) {
    Termino *nuevo = crearTermino(coef, ex, ey, ez);
    if (*poly == NULL) {
        *poly = nuevo;
        return;
    }
    Termino *temp = *poly;
    while (temp->sig != NULL) temp = temp->sig;
    temp->sig = nuevo;
}

Termino* sumarPolinomios3v(Termino *p1, Termino *p2) {
    Termino *resultado = NULL;
    
    while (p1 != NULL) {
        insertarTermino(&resultado, p1->coef, p1->exp_x, p1->exp_y, p1->exp_z);
        p1 = p1->sig;
    }
    
    while (p2 != NULL) {
        insertarTermino(&resultado, p2->coef, p2->exp_x, p2->exp_y, p2->exp_z);
        p2 = p2->sig;
    }
    
    return resultado;
}

int main() {
    Termino *p1 = NULL, *p2 = NULL;
    
    insertarTermino(&p1, 2, 2, 1, 0);
    insertarTermino(&p1, 3, 1, 1, 1);
    
    insertarTermino(&p2, 1, 2, 1, 0);
    insertarTermino(&p2, 4, 1, 1, 1);
    
    Termino *suma = sumarPolinomios3v(p1, p2);
    printf("Suma de polinomios en 3 variables realizada\n");
    
    return 0;
}
