#ifndef ARREGLOS-DE-LISTAS_H_INCLUDED
#define ARREGLOS-DE-LISTAS_H_INCLUDED
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

typedef struct _nodo{
   stNotaAlumno dato;
   struct _nodo *siguiente;
}nodo;

typedef struct{
    stMateria materia;
    nodo* lista;
}stCelda;

// LISTAS
nodo* inicLista();
nodo* crearNodo(stNotaAlumno alumno);
nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo);
void mostrarLista(nodo* lista);
void mostrarAlumno(stNotaAlumno alumno);

// ARCHIVO A ADL
int pasarDeArchivoToADL(char archivoAAbrir[], stCelda array[], int validos);

// ADL A ARCHIVO APROBADOS
void pasarDeADLToArchivoDeAprobados(char archivoAAbrir[], stCelda array[], int validos);
void mostrarArchivo(char registroArchivo[]);

// ARRAY DE LISTAS
int ingresarNotasAlumnos(stCelda array[], int dim, int validos);
stMateria cargarMateria();
stNotaAlumno cargarNotaAlumno();
int alta(stCelda array[], stMateria materia, stNotaAlumno alumno, int validos);
int buscarPosMateria(stCelda array[], stMateria materia, int validos);
int agregarCelda(stCelda array[], stMateria materia, int validos);
void mostrarArrayDeListas(stCelda array[], int validos);

// ARCHIVO DE REGISTROS
void cargarArchivo(char registroArchivo[]);
stMateria nuevaMateria();
stNotaAlumno nuevoAlumno();

#endif // ARREGLOS-DE-LISTAS_H_INCLUDED
