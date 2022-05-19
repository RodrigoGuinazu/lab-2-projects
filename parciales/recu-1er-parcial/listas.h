#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <conio.h>
#include <string.h>

typedef struct{
 int id;
 char nombreCanal[40];
 char rubro[30];
 int cantSuscriptores;
 int cantVistasSemestre;
}stYoutuber;

typedef struct _nodoS{
    stYoutuber dato;
    struct _nodoS* siguiente;
}nodoS;

typedef struct _nodoD{
    stYoutuber dato;
    struct _nodoD* anterior;
    struct _nodoD* siguiente;
}nodoD;

typedef struct{
    nodoD* inicio;
    nodoD* fin;
}Fila;

#endif // LISTAS_H_INCLUDED
