#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-dobles.h"

int main()
{

    // Cargar al principio de la lista
    nodoDoble* lista;
    lista = inicLista();
    printf("\nCargando la lista al principio\n");
    lista = cargarListaAlPpio(lista);
    mostrarLista(lista);

    // Cargar al final de la lista
    nodoDoble* lista2;
    lista2 = inicLista();
    printf("\nCargando la lista al final\n");
    lista2 = cargarListaAlFinal(lista2);
    mostrarLista(lista2);

    // Cargar en orden la lista
    nodoDoble* lista3;
    lista3 = inicLista();
    printf("\nCargando la lista en orden\n");
    lista3 = cargarListaEnOrden(lista3);
    mostrarLista(lista3);

    // Agregar al final de la lista
    printf("\nAgregar al final\n");
    nodoDoble* nuevoNodo = crearNodo(420);
    lista = agregarAlFinal(lista, nuevoNodo);
    mostrarLista(lista);

    // Insertar un nodo en orden
    printf("\Insertar en orden\n");
    lista = insertarEnOrden(lista, crearNodo(999));
    mostrarLista(lista);

    // Retornar el Ultimo Nodo
    printf("\nUltimo nodo\n");
    buscarElUltimo(lista);
    nodoDoble* ultimoNodo = buscarElUltimo(lista);
    mostrarNodo(ultimoNodo);

    // Buscar un nodo
    printf("\nBuscando el nodo\n");
    nodoDoble* busqueda = nodoABuscar(lista, 123);
    if(busqueda){
        mostrarNodo(busqueda);
    }else{
        printf("\nEl nodo buscado no existe en la lista\n");
    }

    // Retornar el numero del primer nodo
    printf("\nPrimer elemento\n");
    int primero = retornarPrimerNumero(lista);
    printf("\nPrimer numero: %d\n", primero);

    // Borrar el primer nodo
    printf("\Borrando el primer nodo\n");
    lista = borrarPrimerNodo(lista);
    mostrarLista(lista);

    // Borrar un nodo
    printf("\Borrando un nodo\n");
    lista = borrarNodo(lista, 89);
    mostrarLista(lista);

    // Borrar toda la lista
    printf("\Borrando toda la lista\n");
    lista = borrarListaCompleta(lista);
    mostrarLista(lista);

    return 0;
}
