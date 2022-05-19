#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
     int legajo;
     char nombre[20];
     int edad;
}persona;

typedef struct nodoArbol{
     persona dato;
     struct nodoArbol* izq;
     struct nodoArbol* der;
}nodoArbol;

typedef struct nodoS{
     persona dato;
     struct nodoS* siguiente;
}nodoS;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(persona dato);
nodoArbol* insertar(nodoArbol* arbol, persona dato);
nodoArbol* buscarNodo(nodoArbol* arbol, persona dato);
persona cargarPersona();
void mostrarUnaPersona(persona dato);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);
nodoS* inicLista();
nodoS* crearNodo(persona dato);
nodoS* insertarEnListaAlFinal(nodoS* lista, nodoS* nuevoNodo);
nodoS* copiarALista(nodoArbol* arbol, nodoS* lista);
void mostrarLista(nodoS* lista);
nodoArbol* buscarPorLegajo(nodoArbol* arbol, int legajo);
nodoArbol* buscarPorNombre(nodoArbol* arbol, char nombre[]);
int esHoja(nodoArbol* arbol);
int mayor(int izq, int der);
int alturaDelArbol(nodoArbol* arbol);
int contarNodos(nodoArbol* arbol);
int contarHojas(nodoArbol* arbol);
nodoArbol* borrarArbol(nodoArbol* arbol);
nodoArbol* borrarNodoArbol(nodoArbol* arbol, int legajo);
nodoArbol* nodoMasIzq(nodoArbol* arbol);
nodoArbol* nodoMasDer(nodoArbol* arbol);

#endif // ARBOLES_H_INCLUDED
