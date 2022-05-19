#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char apellido [20];
    char dni[10];
    int edad;
    char genero;
    int cantMateriasAprobadas;
    float promedioSinAplazos;
    float promedioConAplazos;
}stPersona;

typedef struct{
    stPersona dato;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stPersona persona);
nodo* agregarFinalRecursivo(nodo* lista, nodo* nuevoNodo);
nodo* archivoALista(char archivo[], nodo* lista);
void mostrarUnaPersona(stPersona aux);
void mostrarLista(nodo* lista);
int cantEstudiantes(nodo* lista);
int conAplazos(nodo* lista, float aplazo);
float porcentaje(nodo* lista, float valor);
int mayorPromedio(nodo* lista);
stPersona eliminarPorLegajo(nodo** lista, int legajo);
int pasarTop10(nodo* lista, stPersona Array[], int dim);
void mostrarArray(stPersona Array[], int validos, int i);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);

#endif // LISTA_H_INCLUDED
