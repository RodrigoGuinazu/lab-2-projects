#ifndef LISTAS-PUNTERO-SIMPLE_H_INCLUDED
#define LISTAS-PUNTERO-SIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char nombre[30];
    int edad;
} Persona;

typedef struct{
    Persona dato;
    struct nodo* siguiente;
} nodo;

nodo* inicLista();
void mostrarLista(nodo* lista);
Persona cargarPersona();
void mostrarPersona(Persona aux);
nodo* crearNodo(Persona nuevaPersona);
nodo* agregarAlPpio(nodo* lista, nodo* nuevoNodo);
nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo);
nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo);
nodo* eliminarDeLaLista(nodo* lista, int edad);
nodo* buscarElUltimo(nodo* lista);
nodo* nodoABuscar(nodo* lista, int edad);
nodo* borrarListaCompleta(nodo* lista);
nodo* cargarListaAlPpio(nodo* lista);
nodo* cargarListaAlFinal(nodo* lista);
nodo* cargarListaEnOrden(nodo* lista);

#endif // LISTAS-PUNTERO-SIMPLE_H_INCLUDED
