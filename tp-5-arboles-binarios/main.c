#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arboles.h"

int main()
{
    nodoArbol* arbol = inicArbol();
    persona prueba, prueba2, prueba3;
    prueba = cargarPersona();
    prueba2 = cargarPersona();
    prueba3 = cargarPersona();
    arbol = insertar(arbol, prueba);
    arbol = insertar(arbol, prueba2);
    arbol = insertar(arbol, prueba3);
    printf("\n**********************************ARBOL*******************************************\n");
    preOrder(arbol);
    printf("\n**********************************************************************************\n");
    nodoS* lista = inicLista();
    lista = copiarALista(arbol, lista);
    mostrarLista(lista);
    nodoArbol* rta = buscarPorLegajo(arbol, 93);
    if(rta != NULL){
        printf("\nResultado de la busqueda: \n");
        mostrarUnaPersona(rta-> dato);
    }else{
        printf("\nEl legajo no se encuentra en el arbol\n");
    }

    nodoArbol* rta2 = buscarPorNombre(arbol, "Igual");
    if(rta2 != NULL){
        printf("\nResultado de la busqueda: \n");
        mostrarUnaPersona(rta2-> dato);
    }else{
        printf("\nEl nombre no se encuentra en el arbol\n");
    }

    int rta3 = alturaDelArbol(arbol);
    printf("\nLa altura del arbol es: %d\n", rta3);

    int rta4 = contarNodos(arbol);
    printf("\nLa cantidad de nodos es: %d\n", rta4);

    int rta5 = contarHojas(arbol);
    printf("\nLa cantidad de nodos Hoja es: %d\n", rta5);

    printf("\n**********************************ARBOL*******************************************\n");
    preOrder(arbol);
    printf("\n**********************************************************************************\n");

    printf("\nBorrando un nodo...\n");
    arbol = borrarNodoArbol(arbol, 99);
    printf("\n**********************************ARBOL*******************************************\n");
    preOrder(arbol);
    printf("\n**********************************************************************************\n");

    printf("\nBorrando el arbol...\n");
    arbol = borrarArbol(arbol);
    printf("\n**********************************ARBOL*******************************************\n");
    preOrder(arbol);
    printf("\n**********************************************************************************\n");

    return 0;
}
