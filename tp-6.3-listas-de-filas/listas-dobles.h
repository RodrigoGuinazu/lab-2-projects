#ifndef LISTAS-DOBLES_H_INCLUDED
#define LISTAS-DOBLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char nombreAnimal[30];
	int cantidad;
	int habitat;
}stAnimal;

typedef struct{
    stAnimal dato;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

nodoDoble* inicLista();
nodoDoble* crearNodo(stAnimal animal);
void mostrarLista(nodoDoble* lista);
nodoDoble* agregarAlFinal(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* buscarElUltimo(nodoDoble* lista);
int listaVacia(nodoDoble* lista);


#endif // LISTAS-DOBLES_H_INCLUDED
