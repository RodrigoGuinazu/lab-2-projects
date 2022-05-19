#ifndef FUNCIONES-RECURSIVAS_H_INCLUDED
#define FUNCIONES-RECURSIVAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-puntero-simple.h"

void mostrarListaRecursiva(nodo* lista);
int sumarListaRecursiva(nodo* lista, int suma);
void mostrarPosicionPar(nodo* lista);
nodo* borrarNodoRecursivo(nodo* lista, int dato);
nodo* insertarEnListaCreciente(nodo* lista, nodo* aInsertar);
nodo* invertirLista(nodo* lista);
nodo* invertirListaAux(nodo* lista, nodo* anterior);

#endif // FUNCIONES-RECURSIVAS_H_INCLUDED
