#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdlib.h>
#include "blade.h"

typedef struct nodo{
    int nro;
    Blade blade;
    struct nodo* sig;
}nodo;

typedef struct fila{
    nodo * inicio;
    nodo * fin;
}Fila;

void inicFila(Fila*);
int filaVacia(Fila);
void agregarFila(Fila*, Blade);
Blade extraerFila(Fila*);
Blade frente(Fila);

#endif // FILA_H_INCLUDED
