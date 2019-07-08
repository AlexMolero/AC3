#include <stdio.h>
#include "pila_d.h"

int main() {
    Pila p;
    p = PILA_crea();

    PILA_push(&p,"Red Belt");
    PILA_push(&p,"White Pants");
    PILA_push(&p,"Green Tie");
    PILA_push(&p,"Blue Socks");
    PILA_push(&p,"White T-Shirt");

    PILA_centrifugar(&p);
    printf("Contador: %d \n", PILA_count(p));
    Pila *pila_separada[2];

    PILA_separar(&p, pila_separada);
    for(int i=0;i<2;i++){
        Pila *z;
        z  = pila_separada[i];
        while(*z != NULL){
            printf("Nombre: %s \n", (*z)->name);
            (*z) = (*z)->sig;
        }
    }

}