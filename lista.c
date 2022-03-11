
#include "lista.h"

// Función para crear una lista
void crea(lista *l){
    (*l) = (lista)malloc(sizeof(struct l)); // Reservamos memoria para la estructura
    (*l)->inicio = (posicion)malloc(sizeof(struct celda)); // Reservamos memoria para el puntero inicio
    (*l)->fin = (*l)->inicio; // Apuntamos el puntero fin a inicio
    ((*l)->fin)->sig = NULL; // Apuntamos el puntero a siguiente de fin a NULL
    (*l)->longitud = 0; // Asignamos la longuitud de la lista a 0
}

// Función para destruir una lista
void destruye(lista *l){
    (*l)->fin = (*l)->inicio; // Apuntamos el puntero fin a inicio
    while ((*l)->fin != NULL){ // Mientras no lleguemos al final de la lista
		(*l)->fin = ((*l)->fin)->sig; // Apuntamos el puntero fin al siguiente elemento
		free((*l)->inicio); // Liberamos el elemento actual
		(*l)->inicio = (*l)->fin; // Apuntamos el puntero inicio al puntero fin que estaba en el siguiente elemento del que borramos
    }
    free(*l); // Liberamos la estructura de la lista
    *l = NULL; // Asignamos NULL a la estructura
}

// Función para devolver el puntero inicio de la lista
posicion primero(lista l){
    return (l->inicio);
}

// Función para devolver el puntero al siguiente elemento de la lista
posicion siguiente(lista l, posicion p){
    return (p->sig);
}

// Función qpara devolver el puntero fin de la lista
posicion fin(lista l){
    return (l->fin);
}

// Función para devolver el puntero al siguiente elemento de la lista
posicion anterior(lista l, posicion p){
    posicion q;

    q = l->inicio; // Asignamos el puntero inicio a un auxiliar

    while (q->sig != p){ // Mientras el siguiente del auxiliar no sea el elemento del que bucamos el anterior
		q = q->sig; // Apuntamos el auxiliar al siguiente elemento
    }
    return q;
}

// Función para devolver la existencia no de la lista
unsigned existe(lista l){
    if (l != NULL){ // Comprobamos si la lista no es NULL
		return 1; // Existe la lista
	}
    return 0; // No existe la lista
}

// Función para devolver si la lista está vacía o no
unsigned esvacia(lista l){
    if (l->longitud == 0){ // Comprobamos si la longitud de la lista es 0
		return 1; // La lista está vacía
	}
    return 0; // La lista no está vacía
}

// Función para recuperar el elemento de la lista en una posición concreta
void recupera(lista l, posicion p, tipoelem *e){
    *e = (p->sig)->elemento;
}

// Función para devolver la longitud de la lista
unsigned longitud(lista l){
    return (l->longitud);
}

// Función para insertar en la lista en una posición concreta
void inserta(lista *l, posicion p, tipoelem e){
    posicion q;
    q = p->sig; // Guardamos en un auxiliar el siguiente elemento

    p->sig = (posicion)malloc(sizeof(struct celda)); // Reservamos memoria para el puntero siguiente del nuevo elemento
    (p->sig)->elemento = e;
    (p->sig)->sig = q;
    if (q == NULL){ // Si el auxiliar es null es el ultimo de la lista
		(*l)->fin = p->sig; // Apuntamos fin al siguiente del elemento que acabamos de insertar
	}
    (*l)->longitud = (*l)->longitud + 1; // Actualizamos la longitud de la lista
}

// Función para eliminar un elemento de la lista en una posición concreta
void suprime(lista *l, posicion p){
    posicion q;

    q = p->sig; // Guardamos en un auxiliar el elemento que queremos eliminar
    p->sig = q->sig; // Asignamos como siguiente del elemento anterior al que eliminamos el siguiente del que eliminamos
    if (p->sig == NULL){ // Si el auxiliar es null es el ultimo de la lista
		(*l)->fin = p; // Apuntamos fin al elemento anterior al que acabamos de suprimir
	}
    free(q); // Liberamos memoria
    (*l)->longitud = (*l)->longitud - 1; // Actualizamos la longitud de la lista
}

// Función para modificar un elemento de la lista en una posición concreta
void modifica(lista *l, posicion p, tipoelem e){
    (p->sig)->elemento = e;
}