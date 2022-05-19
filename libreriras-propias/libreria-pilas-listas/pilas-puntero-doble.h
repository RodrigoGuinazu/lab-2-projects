#ifndef PILAS-PUNTERO-DOBLE_H_INCLUDED
#define PILAS-PUNTERO-DOBLE_H_INCLUDED
#include "listas-puntero-simple.h"

#define Pila nodo*

void pasarALista(nodo** lista, Pila* dada);
void inicPila(Pila* dada);
void apilar(Pila* dada, int num);
void leer(Pila* dada);
int tope(Pila* dada);
int desapilar(Pila* dada);
int pilaVacia(Pila* dada);
void mostrar(Pila* dada);

#endif // PILAS-PUNTERO-DOBLE_H_INCLUDED
