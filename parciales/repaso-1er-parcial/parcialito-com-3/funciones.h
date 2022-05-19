#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int num;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo();
void mostrarNodo(nodo* aux);
nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo);
nodo* cargarVariosAlFinal(nodo* lista, int cant);
void mostrarLista(nodo* lista);
void mostrarListaAlReves(nodo* lista);
int validos(nodo* lista);
nodo* borrarPosicion(nodo* lista, int posicion);
nodo* eliminarMayores(nodo* lista, int numero);

#endif // FUNCIONES_H_INCLUDED
