#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[20];
    int edad;
    char genero;
}stPersona;

typedef struct{
    stPersona dato;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stPersona persona);
nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo);
nodo* pasarALista(char archivo[], nodo* lista);
void muestraUnaPersona(stPersona c);
void mostrarListaRecursiva(nodo* lista);
int sumarEdades(nodo* lista);
stPersona buscarMenor(nodo* lista, stPersona menor);
void copiarEnArchivo(nodo* lista, char letra, char archivo[]);
void archivoMostrar(char nombreArchivo[]);
int contarMayores(nodo* lista, int edad);
int cantPersonas(nodo* lista);
float porcentaje(nodo* lista, int edad);

#endif // LISTA_H_INCLUDED
