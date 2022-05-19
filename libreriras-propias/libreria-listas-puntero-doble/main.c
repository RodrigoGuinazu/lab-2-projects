#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-puntero-doble.h"

int main(){

    // Cargar al principio de la lista
    nodo* lista;
    inicLista(&lista);
    cargarListaAlPpio(&lista); // Funciona como la pila, el ultimo nodo ingresado sera el primero de la lista
    mostrarLista(lista);

    // Cargar al final de la lista
    nodo* lista2;
    inicLista(&lista2);
    cargarListaAlFinal(&lista2);
    mostrarLista(lista2);

    // Cargar en orden la lista
    nodo* lista3;
    inicLista(&lista3);
    cargarListaEnOrden(&lista3);
    mostrarLista(lista3);

    // Agrega al final de la lista
    printf("\n\nAgregando un nodo al final de la lista\n");
    Persona personaAlFinal = cargarPersona();
    nodo* nodoAlFinal;
    crearNodo(personaAlFinal, &nodoAlFinal);
    agregarAlFinal(nodoAlFinal, &lista);
    printf("\nLista con el nuevo nodo al final\n\n");
    mostrarLista(lista);

    // Elimina de la lista por la edad pasda por paranetro
    eliminarDeLaLista(&lista, 23);
    printf("\nLista con el nodo eliminado\n\n");
    mostrarLista(lista);

    // Agregando un nodo segun el orden de edad
    printf("\n\nAgregando un nodo segun el orden de edad\n");
    Persona personaOrdenada = cargarPersona();
    nodo* nodoOrdenado;
    crearNodo(personaOrdenada, &nodoOrdenado);
    insertarEnOrden(&lista, nodoOrdenado);
    printf("\nLista con el nuevo nodo ordenado\n\n");
    mostrarLista(lista);

    // Retornar el ultimo nodo
    nodo* ultimo;
    buscarElUltimo(&lista, &ultimo);
    printf("\nUltimo Nodo: \n");
    mostrarPersona(ultimo-> dato);

    // Buscar en el nodo
    nodoABuscar(&lista, 21);

    // Eliminar lista completa
    borrarListaCompleta(&lista);
    mostrarLista(lista);

    return 0;
}
