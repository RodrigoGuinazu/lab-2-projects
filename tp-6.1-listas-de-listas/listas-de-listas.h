#ifndef LISTAS-DE-LISTAS_H_INCLUDED
#define LISTAS-DE-LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
   int nota;
   int legajo;
   char nombreApe[30];
}stNotaAlumno;

typedef struct{
   int id;
   char nombre[30];
}stMateria;

typedef struct{
   stNotaAlumno alumno;
   stMateria materia;
}registroArchivo;

typedef struct _nodoNota{
   stNotaAlumno dato;
   struct _nodoNota *siguiente;
}nodoNota;

typedef struct _nodoCelda{
    stMateria materia;
    struct _nodoCelda* siguiente;
    nodoNota* lista;
}nodoCelda;

// LISTAS nodoNotas
nodoNota* inicListaNotas();
nodoNota* crearNodoNotas(stNotaAlumno alumno);
nodoNota* agregarAlFinalNotas(nodoNota* lista, nodoNota* nuevoNodo);
void mostrarListaNotas(nodoNota* lista);
void mostrarAlumno(stNotaAlumno alumno);

// LISTAS nodoCeldas
nodoCelda* inicListaCeldas();
nodoCelda* crearNodoCeldas(stMateria materia);
nodoCelda* agregarAlPpioCeldas(nodoCelda* lista, nodoCelda* nuevoNodo);
void mostrarListaCeldas(nodoCelda* lista);
void mostrarCelda(nodoCelda* celda);

// ARCHIVO A LDL
nodoCelda* pasarDeArchivoToLDL(char archivoAAbrir[], nodoCelda* ldl);

// LDL A ARCHIVO APROBADOS
void pasarDeLDLToArchivoDeAprobados(char archivoAAbrir[], nodoCelda* ldl);
void mostrarArchivo(char archivoAAbrir[]);

// LISTA DE LISTAS
void ingresarNotasAlumnos(nodoCelda* ldl);
stMateria cargarMateria();
stNotaAlumno cargarNotaAlumno();
nodoCelda* alta(nodoCelda* ldl, stMateria materia, stNotaAlumno alumno);
nodoCelda* buscarNodoCelda(nodoCelda* ldl, stMateria materia);


#endif // LISTAS-DE-LISTAS_H_INCLUDED
