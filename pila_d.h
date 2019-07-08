#ifndef _PILA_D_H_
#define _PILA_D_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
typedef struct N {
	char name[MAX];
	int cont;
	struct N *sig;
}Nodo;

typedef Nodo *Pila;



Pila PILA_crea();
void PILA_push(Pila *p, char name[MAX]);
void PILA_separar(Pila *p, Pila *pila_separada[]);
void PILA_centrifugar(Pila *p);
void PILA_centri(Pila *p);
void PILA_pop(Pila *p);
char PILA_top(Pila p);
int PILA_vacia(Pila p);
void PILA_destruye(Pila *p);
int PILA_count(Pila p);

#endif
