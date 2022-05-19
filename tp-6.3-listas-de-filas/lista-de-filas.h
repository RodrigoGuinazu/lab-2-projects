#ifndef LISTA-DE-FILAS_H_INCLUDED
#define LISTA-DE-FILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "filas.h"
#include "listas-dobles.h"

typedef struct{
   char animal[30];
   int cant;
   int habitat;
   int idEspecie;
   char especie[20];
}registroArchivo;

typedef struct{
    char nombre[20];
    int id;
}stEspecie;

typedef struct _nodoCelda{
    stEspecie especie;
    Fila dada;
    struct _nodoCelda* siguiente;
}nodoCelda;

// PASAR DE ARCHIVO A LDF(LISTA DE FILAS)
nodoCelda* pasarDeArchivoToLDF(char archivoAAbrir[], nodoCelda* ldf);

// LISTA DE FILAS
nodoCelda* alta(nodoCelda* ldf, stAnimal nuevoAnimal, stEspecie nuevaEspecie);
nodoCelda* buscarNodoCelda(nodoCelda* ldf, stEspecie nuevaEspecie);
nodoCelda* inicListaCeldas();
nodoCelda* crearNodoCeldas(stEspecie especie);
nodoCelda* agregarAlPpioCeldas(nodoCelda* lista, nodoCelda* nuevoNodo);
void mostrarListaCeldas(nodoCelda* lista);
void mostrarCelda(nodoCelda* celda);

#endif // LISTA-DE-FILAS_H_INCLUDED
