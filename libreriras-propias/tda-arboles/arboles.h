#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// los arboles pueden irse analizando como subarboles a medida que bajamos por los nodos.
// los arboles cuentan con niveles, empieza desde el nivel 0 con el nodo raiz.

/// TIPOS DE NODOS
// nodo raiz => es el primer nodo del arbol, y a partir de este le siguen los hijos, nietos, etc..
// nodo rama => aquellos nodos que tienen padre e hijos
// nodo hoja => aquellos nodos que se encuentran al final del arbol y estan apuntando a NULL

typedef struct{
    int dato;
    struct nodoArbol* izq; // a la izquierda van los datos menores al padre
    struct nodoArbol* der; // a la derecha van los datos mayores al padre
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(int dato);
nodoArbol* insertar(nodoArbol* arbol, int dato);
nodoArbol* buscarNodo(nodoArbol* arbol, int dato);
void mostrarNodo(nodoArbol* nodo);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);

#endif // ARBOLES_H_INCLUDED
