#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-4.1.h"

/*
1.	Hacer un programa que lea de un archivo datos y los inserte en una lista.
2.	Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.
3.	Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.
4.	Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos.
6.	Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)
*/

int main()
{
    FILE * archivo = abrirArchivo("archivoNumeros.dat");

    printf("\nEJERCICIO 1\n");
    nodo* lista;
    inicLista(&lista);
    pasarArchivoALista(archivo, &lista);
    mostrarLista(lista);

    FILE * archivo2 = abrirArchivo("archivoNumeros.dat"); // abrir cada vez que lo cierre

    printf("\nEJERCICIO 2\n");
    nodo* listaOrdenada;
    nodo** puntLista = &listaOrdenada; // Otra forma de usar el puntero doble, evitamos usar el & en los parametros
    inicLista(puntLista);
    pasarArchivoAListaOrdenado(archivo2, puntLista);
    mostrarLista(listaOrdenada);

    printf("\nEJERCICIO 3\n");
    int rta = nodoABuscar(&lista, 5);
    if(rta == 1){
        printf("\nEl nodo se encuentra en la lista!\n");
    }else{
        printf("\nEl nodo que buscas no existe en la lista\n");
    }

    printf("\nEJERCICIO 4\n");
    nodo* nuevaLista1;
    inicLista(&nuevaLista1);
    printf("\nCargando la lista 1\n");
    cargarListaEnOrden(&nuevaLista1);

    nodo* nuevaLista2;
    inicLista(&nuevaLista2);
    printf("\nCargando la lista 2\n");
    cargarListaEnOrden(&nuevaLista2);

    printf("\nLISTA 1\n");
    mostrarLista(nuevaLista1);
    printf("\nLISTA 2\n");
    mostrarLista(nuevaLista2);

    nodo* listaIntercalada;
    inicLista(&listaIntercalada);
    listaIntercalada = intercalarListas(nuevaLista1, nuevaLista2, listaIntercalada);
    printf("\nLISTA INTERCALADA\n");
    mostrarLista(listaIntercalada);

    //Porque se modifican las listas 1 y 2 si en intercalarListas uso una copia de ambas?
    printf("\nLISTA 1\n");
    mostrarLista(nuevaLista1);
    printf("\nLISTA 2\n");
    mostrarLista(nuevaLista2);

    printf("\n\n**************************************************************\n");

    nodo* listaAInvertir;
    inicLista(&listaAInvertir);
    printf("\nCargando la lista a Invertir: \n");
    cargarListaEnOrden(&listaAInvertir);
    printf("\nlista a Invertir\n");
    mostrarLista(listaAInvertir);
    invertirLista(&listaAInvertir);
    printf("\nlista a Invertida\n");
    mostrarLista(listaAInvertir);

    return 0;
}
