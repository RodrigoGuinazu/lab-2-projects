#ifndef ARREGLO-FILAS_H_INCLUDED
#define ARREGLO-FILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "fila.h"

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

typedef struct{
    stEspecie especie;
    Fila dada;
}celdaEspecie;

// PASAR DE ARCHIVO A ADF(ARREGLO DE FILAS)
int pasarDeArchivoToADF(char archivoAAbrir[], celdaEspecie array[], int validos);

// PASAR DE ADF A ARCHIVO
void pasarAArchivoPorEspecie(celdaEspecie array[], int validos);
void pasarDeADAToArchivosPorEspecie(char archivoAAbrir[], celdaEspecie array[], int pos);
void mostrarArchivo(char archivoAAbrir[]);

// ARRAY DE FILAS
int alta(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos);
int buscarPosAnimal(celdaEspecie array[], stEspecie nuevaEspecie, int validos);
int agregarCelda(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos);
void mostrarArrayDeArboles(celdaEspecie array[], int validos);

#endif // ARREGLO-DE-FILAS_H_INCLUDED
