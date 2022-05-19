#ifndef LDA_H_INCLUDED
#define LDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
   char animal[30];
   int cant;
   int habitat;
   int idEspecie;
   char especie[20];
}registroArchivo;

typedef struct{
    char nombreAnimal[30];
	int cantidad;
	int habitat;
}stAnimal;

typedef struct{
    char nombre[20];
    int id;
}stEspecie;

typedef struct{
   stAnimal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
}nodoArbol;

typedef struct _nodoCelda{
    stEspecie especie;
    nodoArbol* arbolDeAnimales;
    struct _nodoCelda* siguiente;
}nodoCelda;

// ARBOLES
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stAnimal dato);
nodoArbol* insertar(nodoArbol* arbol, stAnimal dato);
void mostrarUnAnimal(stAnimal dato);
void preOrder(nodoArbol* arbol);

// LISTAS nodoCelda
nodoCelda* inicListaCeldas();
nodoCelda* crearNodoCeldas(stEspecie especie);
nodoCelda* agregarAlPpioCeldas(nodoCelda* lista, nodoCelda* nuevoNodo);
void mostrarListaCeldas(nodoCelda* lista);
void mostrarCelda(nodoCelda* celda);

// PASAR DE ARCHIVO A LDA (LISTA DE ARBOLES)
nodoCelda* pasarDeArchivoToLDA(char archivoAAbrir[], nodoCelda* lda);
void mostrarArchivo(char archivoAAbrir[]);

// PASAR DE LDA A ARCHIVO POR ESPECIE
void pasarAArchivoPorEspecie(nodoCelda* lda);
void pasarDeLDAToArchivosPorEspecie(char archivoAAbrir[], nodoCelda* celda);
FILE* arbolAArchivo(nodoArbol* arbol, FILE* archivo, registroArchivo nuevoRegistro);

// LISTA DE ARBOLES (LDA)
void ingresarAnimales(nodoCelda* lda, int dim);
stAnimal cargarAnimal();
stEspecie cargarEspecie();
nodoCelda* alta(nodoCelda* lda, stAnimal nuevoAnimal, stEspecie nuevaEspecie);
nodoCelda* buscarNodoCelda(nodoCelda* lda, stEspecie nuevaEspecie);

#endif // LDA_H_INCLUDED
