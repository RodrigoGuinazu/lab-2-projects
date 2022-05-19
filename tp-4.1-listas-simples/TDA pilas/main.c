#include <stdio.h>
#include <stdlib.h>
#include "listas-puntero-simple.h"
#include "pilas-puntero-doble.h"

/*
5.	Codificar el TDA Pila con las funciones necesarias, implementada con una lista enlazada (Similar al ejercicio hecho con arreglo).
7.	Utilizando el TDA Pila creado en el punto 5, cargar la pila con números enteros.
	Luego, recorrer dicha pila e insertar por orden de llegada (al final) en una lista simplemente enlazada aquellos números que sean pares. Cuidado, la función no debe perder la pila original, trabaje de forma tal que se conserven sus datos.

8.	Eliminar de la lista cargada en el ejercicio anterior, aquellos nodos que contengan valores menores a 10.
*/

int main()
{
    Pila dada1, dada2;
    inicPila(&dada1);
    inicPila(&dada2);

    apilar(&dada1, 1);
    apilar(&dada1, 2);
    leer(&dada1);
    leer(&dada1);

    printf("\nDADA 1\n");
    mostrar(&dada1);

    //int tope1 = tope(&dada1);
    //printf("\nTope DADA 1: %d\n", tope1);


    printf("\nDADA 2\n");
    mostrar(&dada2);

    printf("\n--------------------------------------------------------------\n");

    while(!pilaVacia(&dada1)){
        apilar(&dada2, desapilar(&dada1));
    }

    printf("\nDADA 1\n");
    mostrar(&dada1);

    // Como hacer con el retorno de tope cuando la pila este vacia?

    printf("\nDADA 2\n");
    mostrar(&dada2);

    printf("\n--------------------------------------------------------------\n");

    printf("\nEJERCICIO 7\n");
    nodo* lista;
    lista = inicLista();
    pasarALista(&lista, &dada2);
    printf("\nPILA DADA 2\n");
    mostrar(&dada2);
    printf("\nLISTA\n");
    mostrarLista(lista);

    printf("\n--------------------------------------------------------------\n");

    printf("\nEJERCICIO 8\n");
    borrarMenores(&lista);
    mostrarLista(lista);

    return 0;
}
