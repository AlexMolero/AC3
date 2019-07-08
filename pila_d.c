#include "pila_d.h"

Pila PILA_crea() {
	Pila p;

	p = NULL;
	return p;
}

void PILA_push(Pila *p, char name[MAX]) {
	Nodo *aux;
	aux = (Nodo*)malloc(sizeof(Nodo));
	if (aux == NULL) {
		printf("\nError al hacer push...\n");
	} else {

        strcpy(aux->name,name);
        aux->sig = *p;
		*p = aux;
	}
}
int PILA_count(Pila p){

    int cont=0;
    while(p != NULL){
        cont++;
        p = p->sig;
    }
    return cont;
}
void PILA_centrifugar(Pila *p){
    /**
     * Creamos una pila auxiliar, vamos recorriendo la pila a posiciones aleatorias y realizamos el push a la pila aux, una vez el push eliminamos esa pos de la pila original
     * hasta que la pila original se queda vacia, copiamos la pila aux en la original y hacemos un free de la pila aux para liberar memoria.
    **/
    int length = sizeof(*p);
    int length_nodo = sizeof(Nodo);
    printf("Length: %d , Nodo: %d \n", length, length_nodo);

    /*Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    aux = *p;
    char *arr;
    int cont=0;
    while(*p != NULL){
        //printf("entra");
        arr = (char*)malloc(sizeof(char));
        strcpy( &arr[cont], (*p)->name );
        cont++;
        (*p) = (*p)->sig;
    }
    (*p) = aux;*/
}


void PILA_separar(Pila *p, Pila *pila_separada[]){
    Pila white = PILA_crea();
    Pila color = PILA_crea();
    while(*p != NULL){
        char chr[MAX]  = "White";
        int  result    = strncmp(chr, (*p)->name, 5);
            if(result==0){
                PILA_push(&white,(*p)->name);
            }else{
                PILA_push(&color,(*p)->name);
            }
        (*p) = (*p)->sig;
    }
    pila_separada[0] = &white;
    pila_separada[1] = &color;

}
void PILA_pop(Pila *p) {
	Nodo *aux;

	if (*p == NULL) {
		printf("\nError al hacer pop, la pila està vacía.\n");
	} else {
		aux = *p;
		*p = (*p)->sig;
		free(aux);
	}
}
char PILA_top(Pila p) {
    char name[MAX];
	if (p==NULL) {
		printf("\nError al hacer top, la pila está vacía.\n");
	}else{
        strcpy(name, p->name);
	}
	return name[MAX];
}

int PILA_vacia(Pila p) {
	return p == NULL;
}

void PILA_destruye(Pila *p) {
	Nodo *aux;
	while (*p != NULL) {
		aux = *p;
		*p = (*p)->sig;
		free(aux);
	}

}

