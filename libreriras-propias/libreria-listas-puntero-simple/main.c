#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-puntero-simple.h"

int main(){

    // Agrega al Principio de la lista
    nodo* lista;
    lista = inicLista();
    lista = cargarListaAlPpio(lista); // Funciona como la pila, el ultimo nodo ingresado sera el primero de la lista
    mostrarLista(lista);

    // Agregar al final de la lista
    nodo* lista2;
    lista2 = inicLista();
    lista2 = cargarListaAlFinal(lista2);
    mostrarLista(lista2);

    // Agregar en orden a la lista
    nodo* lista3;
    lista3 = inicLista();
    lista3 = cargarListaEnOrden(lista3);
    mostrarLista(lista3);

    // Agrega al final de la lista
    printf("\n\nAgregando un nodo al final de la lista\n");
    Persona personaAlFinal = cargarPersona();
    nodo* nodoAlFinal = crearNodo(personaAlFinal);
    lista = agregarAlFinal(lista, nodoAlFinal);
    printf("\nLista con el nuevo nodo al final\n\n");
    mostrarLista(lista);

    // Elimina de la lista por la edad pasda por parametro
    eliminarDeLaLista(lista, 23);
    printf("\nLista con el nodo eliminado\n\n");
    mostrarLista(lista);

    // Retornar el ultimo nodo
    nodo* ultimo = buscarElUltimo(lista);
    printf("\nUltimo nodo de la lista\n\n");
    mostrarPersona(ultimo-> dato);

    // Agregando un nodo segun el orden de edad
    printf("\n\nAgregando un nodo segun el orden de edad\n");
    Persona personaOrdenada = cargarPersona();
    nodo* nodoOrdenado = crearNodo(personaOrdenada);
    lista = insertarEnOrden(lista, nodoOrdenado);
    printf("\nLista con el nuevo nodo ordenado\n\n");
    mostrarLista(lista);

    // Buscar en el nodo
    nodo* aBuscar = nodoABuscar(lista, 21);
    if(aBuscar != NULL){
        mostrarPersona(aBuscar-> dato);
    }else{
        printf("\nNo se encontro la persona en la lista\n");
    }

    // Eliminar lista completa
    lista = borrarListaCompleta(lista);
    mostrarLista(lista);

    return 0;
}
