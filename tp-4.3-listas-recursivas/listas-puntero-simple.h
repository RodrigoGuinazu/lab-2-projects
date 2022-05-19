#ifndef LISTAS-PUNTERO-SIMPLE_H_INCLUDED
#define LISTAS-PUNTERO-SIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int num;
    struct nodo* siguiente;
} nodo;

void borrarMenores(nodo** lista);
int primerElemento(nodo* lista);
nodo* eliminarElPrimero(nodo* lista);
nodo* inicLista();
void mostrarLista(nodo* lista);
nodo* crearNodo(int num);
nodo* agregarAlPpio(nodo* lista, nodo* nuevoNodo);
nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo);
nodo* eliminarDeLaLista(nodo* lista, int edad);
nodo* nodoABuscar(nodo* lista, int edad);
nodo* borrarListaCompleta(nodo* lista);
nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo);
nodo* cargarListaAlFinal(nodo* lista);
nodo* cargarListaAlPpio(nodo* lista);

// buscar el ultimo

#endif // LISTAS-PUNTERO-SIMPLE_H_INCLUDED
