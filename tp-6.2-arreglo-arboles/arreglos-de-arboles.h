#ifndef ARREGLOS-DE-ARBOLES_H_INCLUDED
#define ARREGLOS-DE-ARBOLES_H_INCLUDED
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
// 1 - selva, 2- savana, 3-bosque, 4-mar
}stAnimal;

typedef struct{
   stAnimal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
}nodoArbol;

typedef struct{
    char nombre[20];
    int id;
}stEspecie;

typedef struct{
    stEspecie especie;
    // "Mamiferos", "Aves"
    // "Reptiles", "Peces",”Anfibios”
   nodoArbol * arbolDeAnimales;
}celdaEspecie;

// FUNCIONES DE ARBOLES
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stAnimal dato);
nodoArbol* insertar(nodoArbol* arbol, stAnimal dato);
void mostrarUnAnimal(stAnimal dato);
void preOrder(nodoArbol* arbol);

// PASAR DE ARCHIVO A ADA(ARREGLO DE ARBOLES)
int pasarDeArchivoToADA(char archivoAAbrir[], celdaEspecie array[], int validos);
void mostrarArchivo(char archivoAAbrir[]);

// PASAR DE ADA A ARCHIVO
void pasarAArchivoPorEspecie(celdaEspecie array[], int validos);
void pasarDeADAToArchivosPorEspecie(char archivoAAbrir[], celdaEspecie array[], int pos);
FILE* arbolAArchivo(nodoArbol* arbol, FILE* archivo, registroArchivo nuevoRegistro);

// ARRAY DE ARBOLES
int ingresarAnimales(celdaEspecie array[], int dim, int validos);
stAnimal cargarAnimal();
stEspecie cargarEspecie();
int alta(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos);
int buscarPosAnimal(celdaEspecie array[], stEspecie nuevaEspecie, int validos);
int agregarCelda(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos);
void mostrarArrayDeArboles(celdaEspecie array[], int validos);

#endif // ARREGLOS-DE-ARBOLES_H_INCLUDED
