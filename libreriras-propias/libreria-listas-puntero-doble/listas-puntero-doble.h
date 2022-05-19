#ifndef LISTAS-PUNTERO-DOBLE_H_INCLUDED
#define LISTAS-PUNTERO-DOBLE_H_INCLUDED
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

void inicLista(nodo** lista);
void mostrarLista(nodo* lista);
Persona cargarPersona();
void mostrarPersona(Persona aux);
void crearNodo(Persona nuevaPersona, nodo** nuevoNodo);
void agregarAlPpio(nodo* nuevoNodo, nodo** lista);
void agregarAlFinal(nodo* nuevoNodo, nodo** lista);
void insertarEnOrden(nodo** lista, nodo* nuevoNodo);
void eliminarDeLaLista(nodo** lista, int edad);
void buscarElUltimo(nodo** lista, nodo** ultimo);
void nodoABuscar(nodo** lista, int edad);
void borrarListaCompleta(nodo** lista);
void cargarListaAlPpio(nodo** lista);
void cargarListaAlFinal(nodo** lista);
void cargarListaEnOrden(nodo** lista);

#endif // LISTAS-PUNTERO-DOBLE_H_INCLUDED
