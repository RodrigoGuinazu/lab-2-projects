#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lista-doble.h"

typedef struct{
    nodoDoble* inicio;
    nodoDoble* fin;
}Fila;

int listaVacia(nodoDoble* lista);
void agregarAFila(Fila* dada, stAnimal animal);
void mostrarFila(Fila* dada);
int filaVacia(Fila* dada);


#endif // FILA_H_INCLUDED
