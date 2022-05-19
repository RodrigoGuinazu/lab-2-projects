#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones-recursivas.h"
#include "listas-puntero-simple.h"

/*
1. Recorrer una lista y mostrarla en forma invertida.
2. Sumar los elementos de una lista.
3. Mostrar los elementos de una lista ubicados en una posición par.
4. Borrar un nodo de una lista (buscado por un dato específico).
5. Insertar un nodo en una lista en forma recursiva (manteniendo el orden de forma creciente).
6. Invertir una lista cambiando los vínculos.
*/

int main()
{
    nodo* lista;
    lista = inicLista();
    lista = cargarListaAlPpio(lista);
    mostrarListaRecursiva(lista);

    printf("\n\nSuma de la lista: \n");
    int suma = 0;
    suma = sumarListaRecursiva(lista, suma);
    printf("\n%d\n", suma);

    printf("\n\nMostrar posiciones pares: \n");
    mostrarPosicionPar(lista);

    printf("\n\nBorrar un Nodo: \n");
    lista = borrarNodoRecursivo(lista, 10);
    mostrarListaRecursiva(lista);

    printf("\n\Insertar el Nodo 4: \n");
    nodo* aInsertar = crearNodo(4);
    lista = insertarEnListaCreciente(lista, aInsertar);
    mostrarListaRecursiva(lista);

    printf("\n\nInvertir una lista: \n");
    lista = invertirLista(lista);
    mostrarListaRecursiva(lista);

    return 0;
}
