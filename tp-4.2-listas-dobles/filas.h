#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-dobles.h"

typedef struct{
    nodoDoble* inicio;
    nodoDoble* fin;
}Fila;

void inicFila(Fila* dada);
void agregarAFila(Fila* dada, int num);
void leer(Fila* dada);
int extraer(Fila* dada);
void mostrarFila(Fila* dada);
int primero(Fila* dada);
int filaVacia(Fila* dada);

#endif // FILAS_H_INCLUDED
