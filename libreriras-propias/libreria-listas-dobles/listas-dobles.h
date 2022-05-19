#ifndef LISTAS-DOBLES_H_INCLUDED
#define LISTAS-DOBLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int num;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

nodoDoble* inicLista();
void mostrarNodo(nodoDoble* aux);
void mostrarLista(nodoDoble* lista);
nodoDoble* crearNodo(int dato);
nodoDoble* agregarAlPpio(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* agregarAlPpioCorta(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* agregarAlFinal(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* insertarEnOrden(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* borrarNodo(nodoDoble* lista, int num);
nodoDoble* buscarElUltimo(nodoDoble* lista);
nodoDoble* nodoABuscar(nodoDoble* lista, int num);
int retornarPrimerNumero(nodoDoble* lista);
nodoDoble* borrarPrimerNodo(nodoDoble* lista);
nodoDoble* borrarListaCompleta(nodoDoble* lista);
nodoDoble* cargarListaAlPpio(nodoDoble* lista);
nodoDoble* cargarListaAlFinal(nodoDoble* lista);
nodoDoble* cargarListaEnOrden(nodoDoble* lista);

#endif // LISTAS-DOBLES_H_INCLUDED
