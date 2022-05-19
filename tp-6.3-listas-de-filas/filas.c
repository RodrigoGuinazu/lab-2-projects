#include "filas.h"

void inicFila(Fila* dada){
    dada-> inicio = inicLista();
    dada-> fin = inicLista();
}

void agregarAFila(Fila* dada, stAnimal animal){
    nodoDoble* nuevoNodo = crearNodo(animal);

    dada-> fin = agregarAlFinal(dada-> fin, nuevoNodo);
    dada-> fin = nuevoNodo;

    if(dada-> inicio == NULL){
        dada-> inicio = nuevoNodo;
    }
}

void mostrarFila(Fila* dada){
    mostrarLista(dada-> inicio);
}

int filaVacia(Fila* dada){
    int rta = listaVacia(dada-> inicio);
    return rta;
}
