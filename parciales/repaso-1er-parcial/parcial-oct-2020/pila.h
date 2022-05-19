#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lista.h"
#define Pila nodo*

void inicPila(Pila* dada);
void apilar(Pila* dada, stPersona aux);
void mostrarPila(Pila* dada);
void pasarAPila(Pila* dada, nodo* lista);

#endif // PILA_H_INCLUDED
