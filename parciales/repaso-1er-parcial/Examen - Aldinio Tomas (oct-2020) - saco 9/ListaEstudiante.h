#ifndef LISTAESTUDIANTE_H_INCLUDED
#define LISTAESTUDIANTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido [20];
    char dni[10];
    int edad;
    char genero;
    int cantMateriasAprobadas; /// indica el total de materias aprobadas del estudiante en la carrera (max 20)
    float promedioSinAplazos; /// indica el promedio de estudiante, sin tener en cuenta aplazos
    float promedioConAplazos; /// indica el promedio de estudiante, teniendo en cuenta aplazos
} estudiante;

typedef struct _nodo
{
    estudiante dato;
    struct _nodo* siguiente;
} nodoEstudiante;

///ejercicio 1
nodoEstudiante * inicListaEstudiante ();

nodoEstudiante * agregarFinalRecursivo (nodoEstudiante * lista, nodoEstudiante * nuevo);

///ejercicio 2
void mostrarNodo(nodoEstudiante * lista);
void recorrerYMostrarRecur(nodoEstudiante * lista);


///ejercicio 3
///a
int contarEstudiantes(nodoEstudiante * lista);
///b
int contarAplazosEstudiantes(nodoEstudiante * lista, int valor);


/// Ejercicio 4
///a
int legajoMayorPromedio (nodoEstudiante * lista);
///b
nodoEstudiante * eliminarNodo(nodoEstudiante ** lista, int legajo);
///c
void cargarArrayEstudiantes(nodoEstudiante * lista, estudiante arreglo[], int dimension);


/// ejercicio 5
void mostrarArregloEstudiantes( estudiante arreglo[],int indice, int dimension);


///ejercicio 6
nodoEstudiante * agregarPpio(nodoEstudiante * lista, nodoEstudiante * nuevo);






#endif // LISTAESTUDIANTE_H_INCLUDED
