#ifndef LISTAS-4_1_H_INCLUDED
#define LISTAS-4_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int num;
    struct nodo* siguiente;
} nodo;

void invertirLista(nodo** lista);
nodo* ultimoNodo(nodo* lista, nodo* ultimo);
nodo* intercalarListas(nodo* lista1, nodo* lista2, nodo* listaFinal);
nodo* agregarAlFinal(nodo* nuevoNodo, nodo* lista);
void cargarListaEnOrden(nodo** lista);
void cargarListaAlPpio(nodo** lista);
int nodoABuscar(nodo** lista, int num);
void pasarArchivoAListaOrdenado(FILE * archivo, nodo** lista);
void insertarEnOrden(nodo** lista, nodo* nuevoNodo);
void pasarArchivoALista(FILE * archivo, nodo** lista);
void mostrarLista(nodo* lista);
void inicLista(nodo** lista);
void agregarAlPpio(nodo* nuevoNodo, nodo** lista);
void crearNodo(int numero, nodo** nuevoNodo);
FILE * abrirArchivo(char archivoNumeros[]);
void cerrarArchivo(FILE * archivo);

// buscar el ultimo nodo

#endif // LISTAS-4_1_H_INCLUDED
