#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct nodo{
stPersona dato;
struct nodo* siguiente;
} nodo;

nodo* crearNodo (stPersona dato);
nodo * inicLista ();
nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo);
nodo* archivoToList (char archivo[], nodo* lista);
void mostrarLista(nodo* lista);


#endif // LISTA_H_INCLUDED
