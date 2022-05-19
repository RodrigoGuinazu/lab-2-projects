#ifndef PILAESTUDIANTE_H_INCLUDED
#define PILAESTUDIANTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ListaEstudiante.h"

#define Pila nodoEstudiante *

void inicPila(Pila * pilita);

void apilar (Pila * pilita, nodoEstudiante * nuevo);
void mostrar(Pila * pilita);


#endif // PILAESTUDIANTE_H_INCLUDED
